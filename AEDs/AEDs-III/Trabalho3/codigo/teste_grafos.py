#!/usr/bin/env python3
"""
Script para executar o algoritmo de caminhos mais curtos em todos os grafos
e salvar os resultados em um arquivo CSV.
"""

import os
import subprocess
import csv
import sys
from pathlib import Path
from datetime import datetime

# Configuração de caminhos
CODIGO_DIR = Path(__file__).parent
GRAFOS_DIR = Path(__file__).parent / "grafos"
EXECUTAVEL = CODIGO_DIR / "base.exe"
CSV_OUTPUT = Path(__file__).parent / "resultados_grafos.csv"

def compilar_codigo():
    """Compila o código C se necessário."""
    print("[*] Verificando compilação...")
    
    if EXECUTAVEL.exists():
        print(f"[✓] Executável encontrado: {EXECUTAVEL}")
        return True
    
    print("[!] Executável não encontrado. Tentando compilar...")
    try:
        resultado = subprocess.run(
            ["make", "base"],
            cwd=str(CODIGO_DIR),
            capture_output=True,
            text=True,
            timeout=30
        )
        
        if resultado.returncode == 0:
            print("[✓] Compilação bem-sucedida!")
            return True
        else:
            print("[✗] Erro na compilação:")
            print(resultado.stderr)
            return False
    except Exception as e:
        print(f"[✗] Erro ao compilar: {e}")
        return False

def encontrar_grafos():
    """Encontra todos os arquivos de grafo nas subpastas."""
    grafos = []
    
    if not GRAFOS_DIR.exists():
        print(f"[!] Pasta de grafos não encontrada: {GRAFOS_DIR}")
        return grafos
    
    # Procura em cada subpasta (barabasi, erdos, watts)
    for item in GRAFOS_DIR.iterdir():
        if item.is_dir():
            # Procura arquivos .txt em subpastas
            for arquivo_grafo in sorted(item.glob("*.txt")):
                grafos.append(arquivo_grafo)
        elif item.is_file() and item.suffix == '.txt':
            # Procura arquivos .txt diretos na pasta
            grafos.append(item)
    
    # Ordena a lista final
    grafos.sort()
    
    print(f"[✓] Encontrados {len(grafos)} grafos")
    return grafos

def executar_grafo(caminho_grafo):
    """Executa o algoritmo para um grafo e retorna os resultados."""
    try:
        resultado = subprocess.run(
            [str(EXECUTAVEL), str(caminho_grafo)],
            capture_output=True,
            text=True,
            timeout=60
        )
        
        if resultado.returncode != 0:
            print(f"[✗] Erro ao executar para {caminho_grafo.name}")
            return None
        
        # Parse da saída
        linhas = resultado.stdout.strip().split('\n')
        dados = {}
        
        for linha in linhas:
            if linha.startswith("Dijkstra:"):
                partes = linha.split()
                dados['dijkstra_custo'] = float(partes[1])
                dados['dijkstra_tempo'] = float(partes[2])
            elif linha.startswith("Duan:"):
                partes = linha.split()
                dados['duan_custo'] = float(partes[1])
                dados['duan_tempo'] = float(partes[2])
            elif linha.startswith("Outro:"):
                partes = linha.split()
                dados['outro_custo'] = float(partes[1])
                dados['outro_tempo'] = float(partes[2])
        
        if len(dados) == 6:  # Deve ter os 6 valores
            return dados
        else:
            return None
    
    except subprocess.TimeoutExpired:
        print(f"[✗] Timeout ao executar {caminho_grafo.name}")
        return None
    except Exception as e:
        print(f"[✗] Erro ao executar {caminho_grafo.name}: {e}")
        return None

def main():
    print("=" * 70)
    print("Teste de Algoritmos de Caminhos Mais Curtos")
    print("=" * 70)
    print()
    
    # Compilar
    if not compilar_codigo():
        print("[✗] Falha na compilação. Abortando.")
        return 1
    
    print()
    
    # Encontrar grafos
    grafos = encontrar_grafos()
    if not grafos:
        print("[✗] Nenhum grafo encontrado. Abortando.")
        return 1
    
    print()
    print(f"[*] Processando {len(grafos)} grafos...")
    print()
    
    # Executar para cada grafo
    resultados = []
    for idx, caminho_grafo in enumerate(grafos, 1):
        nome_relativo = caminho_grafo.relative_to(GRAFOS_DIR)
        print(f"[{idx}/{len(grafos)}] Processando: {nome_relativo}...", end=" ", flush=True)
        
        dados = executar_grafo(caminho_grafo)
        
        if dados:
            resultados.append({
                'arquivo': str(nome_relativo),
                'dijkstra_custo': dados['dijkstra_custo'],
                'dijkstra_tempo': dados['dijkstra_tempo'],
                'duan_custo': dados['duan_custo'],
                'duan_tempo': dados['duan_tempo'],
                'outro_custo': dados['outro_custo'],
                'outro_tempo': dados['outro_tempo']
            })
            print("✓")
        else:
            print("✗")
    
    print()
    
    # Salvar em CSV
    if resultados:
        print(f"[*] Salvando resultados em {CSV_OUTPUT}...")
        
        with open(CSV_OUTPUT, 'w', newline='', encoding='utf-8') as csvfile:
            fieldnames = [
                'arquivo',
                'dijkstra_custo', 'dijkstra_tempo',
                'duan_custo', 'duan_tempo',
                'outro_custo', 'outro_tempo'
            ]
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            
            writer.writeheader()
            writer.writerows(resultados)
        
        print(f"[✓] {len(resultados)} resultados salvos com sucesso!")
        print()
        print(f"Arquivo de saída: {CSV_OUTPUT}")
        
        # Resumo rápido
        print()
        print("Resumo dos resultados:")
        print("-" * 70)
        
        dijkstra_tempo_total = sum(r['dijkstra_tempo'] for r in resultados)
        duan_tempo_total = sum(r['duan_tempo'] for r in resultados)
        outro_tempo_total = sum(r['outro_tempo'] for r in resultados)
        
        print(f"Dijkstra - Tempo total: {dijkstra_tempo_total:.4f}s (média: {dijkstra_tempo_total/len(resultados):.4f}s)")
        print(f"Duan     - Tempo total: {duan_tempo_total:.4f}s (média: {duan_tempo_total/len(resultados):.4f}s)")
        print(f"Outro    - Tempo total: {outro_tempo_total:.4f}s (média: {outro_tempo_total/len(resultados):.4f}s)")
        
        return 0
    else:
        print("[✗] Nenhum resultado foi obtido.")
        return 1

if __name__ == "__main__":
    sys.exit(main())
