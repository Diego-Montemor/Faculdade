#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "algorithms.h"

#define INF INT_MAX

/*
Participantes do grupo
Nome: Diego Vianna Leite Montemor  Matrícula: 2025.1.08.023 
Nome: Pedro Medina Stracieri       Matrícula: 2023.1.08.033 
Nome: Francisco Toro Tonissi       Matrícula: 2025.1.08.025 
Nome: Pedro Ferrera Prado          Matrícula: 2025.1.08.028 
*/

// Algoritmo de Dijkstra usando matriz de adjacência
double dijkstra(int **matriz, int num_nos, int origem) {
    double custo = 0; // Guardará a soma de todas as distâncias mínimas
 
    // Alocação e inicialização do array de distâncias
    double *distancia = (double*)malloc(num_nos * sizeof(double));
    for (int i = 0; i < num_nos; i++) {
        distancia[i] = INF;
    }
    distancia[origem] = 0;
 
    // Alocação e inicialização do array de visitados
    bool *visitado = (bool *)malloc(num_nos * sizeof(bool));
    for (int i = 0; i < num_nos; i++) {
        visitado[i] = false;
    }
 
    // LOOP PRINCIPAL (Algoritmo guloso)
    for (int i = 0; i < num_nos; i++) {
 
        // Buscar o nó não visitado com a menor distância atual
        double min_dist = INF;
        int u = -1;
        for (int j = 0; j < num_nos; j++) {
            if (!visitado[j] && distancia[j] < min_dist) {
                min_dist = distancia[j];
                u = j;
            }
        }
 
        // Se não houver mais nós alcançáveis, interrompe
        if (u == -1) break;
 
        // Marcar o nó como visitado
        visitado[u] = true;
 
        // Atualizar a distância dos vizinhos (Relaxamento)
        for (int v = 0; v < num_nos; v++) {
            if (matriz[u][v] != 0 && !visitado[v]) {
                if (distancia[u] != INF && distancia[u] + matriz[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + matriz[u][v];
                }
            }
        }
    }
 
    // Acumula a soma de todas as distâncias mínimas na variável de retorno
    for (int i = 0; i < num_nos; i++) {
        if (distancia[i] != INF) {
            custo += distancia[i];
        }
    }
 
    // Liberação de memória
    free(distancia);
    free(visitado);
 
    /* Retorno obrigatório exigido pelo código-base, agora contendo a soma */
    return custo;
}

// Algoritmo de Duan usando matriz de adjacência
// Versão simplificada: mantém a ideia de processamento em camadas
typedef struct {
    int     n;
    int   **matriz;
    double *db;      
    int    *pred;      
    bool   *completo;  
    int     k;         
    int     t;         
} Estado;
 
/* Heap mínimo simples (usado no BaseCase) */
typedef struct { int v; double d; } HItem;
typedef struct { HItem *buf; int sz, cap; } Heap;
 
static Heap* heap_new(int cap) {
    Heap *h = malloc(sizeof(Heap));
    h->buf = malloc(cap * sizeof(HItem));
    h->sz  = 0; h->cap = cap;
    return h;
}
static void heap_free(Heap *h) { free(h->buf); free(h); }
 
static void heap_up(Heap *h, int i) {
    while (i > 0) {
        int p = (i-1)/2;
        if (h->buf[p].d > h->buf[i].d) {
            HItem t = h->buf[p]; h->buf[p] = h->buf[i]; h->buf[i] = t;
            i = p;
        } else break;
    }
}
static void heap_down(Heap *h, int i) {
    while (1) {
        int m = i, l = 2*i+1, r = 2*i+2;
        if (l < h->sz && h->buf[l].d < h->buf[m].d) m = l;
        if (r < h->sz && h->buf[r].d < h->buf[m].d) m = r;
        if (m == i) break;
        HItem t = h->buf[m]; h->buf[m] = h->buf[i]; h->buf[i] = t;
        i = m;
    }
}
static void heap_push(Heap *h, int v, double d) {
    if (h->sz == h->cap) { h->cap *= 2; h->buf = realloc(h->buf, h->cap * sizeof(HItem)); }
    h->buf[h->sz] = (HItem){v, d};
    heap_up(h, h->sz++);
}
static HItem heap_pop(Heap *h) {
    HItem r = h->buf[0];
    h->buf[0] = h->buf[--h->sz];
    heap_down(h, 0);
    return r;
}
 

static void find_pivots(Estado *E, double B,
                        int *S, int s_sz,
                        int **W_out, int *w_sz_out,
                        int **P_out, int *p_sz_out)
{
    int n = E->n, k = E->k;
 
    int  w_cap = s_sz * (k + 2) + 16;
    int *W     = malloc(w_cap * sizeof(int));
    int  w_sz  = 0;
    bool *em_W = calloc(n, sizeof(bool));
 
    /* W começa com S */
    for (int i = 0; i < s_sz; i++) {
        W[w_sz++] = S[i];
        em_W[S[i]] = true;
    }
 
    int *front      = malloc(n * sizeof(int));
    int *front_prox = malloc(n * sizeof(int));
    memcpy(front, S, s_sz * sizeof(int));
    int front_sz = s_sz;
    bool explodiu = false;
 
    /* k passos de relaxação */
    for (int passo = 1; passo <= k && !explodiu; passo++) {
        int fp_sz = 0;
        for (int i = 0; i < front_sz; i++) {
            int u = front[i];
            for (int v = 0; v < n; v++) {
                if (!E->matriz[u][v]) continue;
                double novo = E->db[u] + E->matriz[u][v];
                if (novo <= E->db[v]) {
                    E->db[v]   = novo;
                    E->pred[v] = u;
                    if (novo < B) {
                        front_prox[fp_sz++] = v;
                        if (!em_W[v]) {
                            if (w_sz == w_cap) { w_cap *= 2; W = realloc(W, w_cap * sizeof(int)); }
                            W[w_sz++] = v;
                            em_W[v]   = true;
                        }
                    }
                }
            }
        }
        memcpy(front, front_prox, fp_sz * sizeof(int));
        front_sz = fp_sz;
        if (w_sz > k * s_sz) explodiu = true;
    }
 
    /* marca W como completo */
    for (int i = 0; i < w_sz; i++) E->completo[W[i]] = true;
 
    /* calcula pivôs P */
    int *P   = malloc(s_sz * sizeof(int));
    int  p_sz = 0;
 
    if (explodiu) {
        /* P = S inteiro (linha 13-14 do Algorithm 1) */
        memcpy(P, S, s_sz * sizeof(int));
        p_sz = s_sz;
    } else {
        /*
         * Para cada v em W, sobe na SPT via pred[] até encontrar
         * um vértice de S — conta o tamanho da sub-árvore de cada s em S.
         * Pivôs são os de S com sub-árvore >= k.
         */
        bool *em_S     = calloc(n, sizeof(bool));
        int  *subtree  = calloc(n, sizeof(int));
        for (int i = 0; i < s_sz; i++) em_S[S[i]] = true;
 
        for (int i = 0; i < w_sz; i++) {
            int v = W[i];
            if (em_S[v]) continue;
            int cur = v;
            while (cur != -1 && !em_S[cur]) cur = E->pred[cur];
            if (cur != -1) subtree[cur]++;
        }
        for (int i = 0; i < s_sz; i++)
            if (subtree[S[i]] >= k) P[p_sz++] = S[i];
 
        free(em_S);
        free(subtree);
    }
 
    free(front); free(front_prox); free(em_W);
    *W_out = W; *w_sz_out = w_sz;
    *P_out = P; *p_sz_out = p_sz;
}
 

static double base_case(Estado *E, double B, int x,
                        int **U_out, int *u_sz_out)
{
    int n = E->n, k = E->k;
 
    int  u_cap = k + 4;
    int *U0    = malloc(u_cap * sizeof(int));
    int  u0_sz = 0;
    U0[u0_sz++] = x;
 
    Heap *H    = heap_new(n + 4);
    bool *em_H = calloc(n, sizeof(bool));
    heap_push(H, x, E->db[x]);
    em_H[x] = true;
 
    while (H->sz > 0 && u0_sz < k + 1) {
        HItem it = heap_pop(H);
        int u = it.v;
        E->completo[u] = true;
        if (u != x) {
            if (u0_sz == u_cap) { u_cap *= 2; U0 = realloc(U0, u_cap * sizeof(int)); }
            U0[u0_sz++] = u;
        }
        for (int v = 0; v < n; v++) {
            if (!E->matriz[u][v]) continue;
            double novo = E->db[u] + E->matriz[u][v];
            if (novo <= E->db[v] && novo < B) {
                E->db[v]   = novo;
                E->pred[v] = u;
                /* re-insere (heap simples sem decrease-key explícito) */
                heap_push(H, v, novo);
                em_H[v] = true;
            }
        }
    }
 
    heap_free(H);
    free(em_H);
 
    double B_linha;
    if (u0_sz <= k) {
        B_linha = B;
        *U_out = U0; *u_sz_out = u0_sz;
    } else {
        double bmax = 0.0;
        for (int i = 0; i < u0_sz; i++)
            if (E->db[U0[i]] > bmax) bmax = E->db[U0[i]];
        B_linha = bmax;
        int nova_sz = 0;
        for (int i = 0; i < u0_sz; i++)
            if (E->db[U0[i]] < B_linha) U0[nova_sz++] = U0[i];
        *U_out = U0; *u_sz_out = nova_sz;
    }
    return B_linha;
}
 
static double bmssp(Estado *E, int nivel, double B,
                    int *S, int s_sz,
                    int **U_out, int *u_sz_out)
{
    int n = E->n, k = E->k, t = E->t;
 
    /* --- Caso base --- */
    if (nivel == 0)
        return base_case(E, B, S[0], U_out, u_sz_out);
 
    /* --- FindPivots --- */
    int *W = NULL, *P = NULL, w_sz = 0, p_sz = 0;
    find_pivots(E, B, S, s_sz, &W, &w_sz, &P, &p_sz);
 
    /* --- U acumulado --- */
    int  u_cap = 4 * k + 16;
    int *U     = malloc(u_cap * sizeof(int));
    int  u_sz  = 0;
 
    /* M = 2^((nivel-1)*t) — tamanho do pull */
    int M = 1;
    for (int i = 0; i < (nivel - 1) * t; i++) { M *= 2; if (M > n) { M = n; break; } }
    if (M < 1) M = 1;
 
    /* D: array dinâmico de pares (v, db[v]), ordenado por db[v] */
    int     d_cap   = p_sz + 16;
    int    *d_v     = malloc(d_cap * sizeof(int));
    double *d_d     = malloc(d_cap * sizeof(double));
    int     d_sz    = 0;
    bool   *em_D    = calloc(n, sizeof(bool));
 
    /* insere pivôs em D */
    for (int i = 0; i < p_sz; i++) {
        d_v[d_sz] = P[i]; d_d[d_sz] = E->db[P[i]]; d_sz++;
        em_D[P[i]] = true;
    }
 
    /* B'_0 = min_{x in P} db[x] */
    double B_linha_i = B;
    for (int i = 0; i < p_sz; i++)
        if (E->db[P[i]] < B_linha_i) B_linha_i = E->db[P[i]];
 
    double B_ret   = B;
    int    limite  = k * M * 4 + 16;
    if (limite > k * n) limite = k * n;
 
    while (u_sz < limite && d_sz > 0) {
 
        /* ordena D por distância (insertion sort — D é pequeno por nível) */
        for (int i = 1; i < d_sz; i++) {
            int tv = d_v[i]; double td = d_d[i]; int j = i - 1;
            while (j >= 0 && d_d[j] > td) { d_v[j+1] = d_v[j]; d_d[j+1] = d_d[j]; j--; }
            d_v[j+1] = tv; d_d[j+1] = td;
        }
 
        /* Pull: pega os M menores */
        int pull_sz = (d_sz < M) ? d_sz : M;
        int *Si = malloc(pull_sz * sizeof(int));
        for (int i = 0; i < pull_sz; i++) { Si[i] = d_v[i]; em_D[Si[i]] = false; }
        double Bi = (pull_sz < d_sz) ? d_d[pull_sz] : B;
        memmove(d_v, d_v + pull_sz, (d_sz - pull_sz) * sizeof(int));
        memmove(d_d, d_d + pull_sz, (d_sz - pull_sz) * sizeof(double));
        d_sz -= pull_sz;
 
        /* chamada recursiva BMSSP(nivel-1, Bi, Si) */
        int    *Ui = NULL, ui_sz = 0;
        double  B_novo = bmssp(E, nivel - 1, Bi, Si, pull_sz, &Ui, &ui_sz);
 
        for (int i = 0; i < ui_sz; i++) {
            if (u_sz == u_cap) { u_cap *= 2; U = realloc(U, u_cap * sizeof(int)); }
            U[u_sz++] = Ui[i];
        }
 
        /* relaxa arestas saindo de Ui */
        int     k_cap = ui_sz * 4 + 8;
        int    *Kv    = malloc(k_cap * sizeof(int));
        double *Kd    = malloc(k_cap * sizeof(double));
        int     k_sz  = 0;
 
        for (int i = 0; i < ui_sz; i++) {
            int u = Ui[i];
            for (int v = 0; v < n; v++) {
                if (!E->matriz[u][v]) continue;
                double novo = E->db[u] + E->matriz[u][v];
                if (novo <= E->db[v]) {
                    E->db[v] = novo; E->pred[v] = u;
                    if (novo >= Bi && novo < B) {
                        /* inserção direta em D */
                        if (!em_D[v]) {
                            if (d_sz == d_cap) { d_cap *= 2; d_v = realloc(d_v, d_cap * sizeof(int)); d_d = realloc(d_d, d_cap * sizeof(double)); }
                            d_v[d_sz] = v; d_d[d_sz] = novo; d_sz++; em_D[v] = true;
                        }
                    } else if (novo >= B_novo && novo < Bi) {
                        /* batch-prepend K */
                        if (k_sz == k_cap) { k_cap *= 2; Kv = realloc(Kv, k_cap * sizeof(int)); Kd = realloc(Kd, k_cap * sizeof(double)); }
                        Kv[k_sz] = v; Kd[k_sz] = novo; k_sz++;
                    }
                }
            }
        }
 
        /* batch-prepend: insere K e Si com db ∈ [B'_i, Bi) de volta em D */
        for (int i = 0; i < k_sz; i++) {
            if (!em_D[Kv[i]]) {
                if (d_sz == d_cap) { d_cap *= 2; d_v = realloc(d_v, d_cap * sizeof(int)); d_d = realloc(d_d, d_cap * sizeof(double)); }
                d_v[d_sz] = Kv[i]; d_d[d_sz] = Kd[i]; d_sz++; em_D[Kv[i]] = true;
            }
        }
        for (int i = 0; i < pull_sz; i++) {
            int x = Si[i];
            if (E->db[x] >= B_novo && E->db[x] < Bi && !em_D[x]) {
                if (d_sz == d_cap) { d_cap *= 2; d_v = realloc(d_v, d_cap * sizeof(int)); d_d = realloc(d_d, d_cap * sizeof(double)); }
                d_v[d_sz] = x; d_d[d_sz] = E->db[x]; d_sz++; em_D[x] = true;
            }
        }
 
        B_linha_i = B_novo;
        free(Kv); free(Kd); free(Si); free(Ui);
    }
    B_ret = B;
 
fim:
    /* adiciona vértices de W com db < B_ret */
    for (int i = 0; i < w_sz; i++) {
        int x = W[i];
        if (E->db[x] < B_ret) {
            if (u_sz == u_cap) { u_cap *= 2; U = realloc(U, u_cap * sizeof(int)); }
            U[u_sz++] = x;
        }
    }
 
    free(W); free(P); free(d_v); free(d_d); free(em_D);
    *U_out = U; *u_sz_out = u_sz;
    return B_ret;
}

double duan(int **matriz, int num_nos, int origem) {
    double custo = 0;
 
    if (num_nos <= 0) return custo;
 
    /* parâmetros k e t do paper */
    int k = 1, t = 1;
    if (num_nos > 2) {
        double ln = log((double)num_nos);
        k = (int)floor(pow(ln, 1.0/3.0));
        t = (int)floor(pow(ln, 2.0/3.0));
        if (k < 1) k = 1;
        if (t < 1) t = 1;
    }
    int l_max = (int)ceil(log((double)(num_nos > 1 ? num_nos : 2)) / t);
    if (l_max < 1) l_max = 1;
 
    /* inicializa estado */
    Estado E;
    E.n        = num_nos;
    E.matriz   = matriz;
    E.k        = k;
    E.t        = t;
    E.db       = malloc(num_nos * sizeof(double));
    E.pred     = malloc(num_nos * sizeof(int));
    E.completo = calloc(num_nos, sizeof(bool));
 
    for (int i = 0; i < num_nos; i++) {
        E.db[i]   = (double)INF;
        E.pred[i] = -1;
    }
    E.db[origem]       = 0.0;
    E.completo[origem] = true;
 
    /* chama BMSSP no nível máximo com S = {origem} */
    int  s[1] = { origem };
    int *U = NULL, u_sz = 0;
    bmssp(&E, l_max, (double)INF, s, 1, &U, &u_sz);
 
    /* soma todas as distâncias mínimas */
    for (int i = 0; i < num_nos; i++)
        if (E.db[i] < (double)INF) custo += E.db[i];
 
    free(U);
    free(E.db);
    free(E.pred);
    free(E.completo);
 
    return custo;
}

// Implementação de outro algoritimo usando matriz de adjacência
double outro(int **matriz, int num_nos, int origem) {
    double custo = 0;
    
    // Estrutura para armazenar as arestas
    typedef struct {
        int u;
        int v;
        int peso;
    } Aresta;
    
    // Coletar todas as arestas da matriz de adjacência
    Aresta *arestas = (Aresta *)malloc(num_nos * num_nos * sizeof(Aresta));
    if (!arestas) {
        return 0;
    }
    
    int num_arestas = 0;
    for (int u = 0; u < num_nos; u++) {
        for (int v = u + 1; v < num_nos; v++) {
            if (matriz[u][v] != 0) {
                arestas[num_arestas].u = u;
                arestas[num_arestas].v = v;
                arestas[num_arestas].peso = matriz[u][v];
                num_arestas++;
            }
        }
    }
    
    // Inicializar as distâncias
    double *dist = (double *)malloc(num_nos * sizeof(double));
    if (!dist) {
        free(arestas);
        return 0;
    }
    
    for (int i = 0; i < num_nos; i++) {
        dist[i] = INF;
    }
    dist[origem] = 0;
    
    // Relaxar as arestas V-1 vezes (usando lista de arestas, não pares)
    for (int i = 0; i < num_nos - 1; i++) {
        for (int j = 0; j < num_arestas; j++) {
            int u = arestas[j].u;
            int v = arestas[j].v;
            int peso = arestas[j].peso;
            
            // Relaxamento em ambas as direções (grafo não direcionado)
            if (dist[u] != INF && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
            if (dist[v] != INF && dist[v] + peso < dist[u]) {
                dist[u] = dist[v] + peso;
            }
        }
    }
    
    // Calcular o custo total (soma das distâncias mínimas)
    for (int i = 0; i < num_nos; i++) {
        if (dist[i] != INF) {
            custo += dist[i];
        }
    }
    
    free(arestas);
    free(dist);

    /* Esta retorno também é obrigatório e não deve ser retirado*/  
    return custo;
}