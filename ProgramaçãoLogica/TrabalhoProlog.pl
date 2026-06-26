% Diego Vianna Leite Montemor   2025.1.08.023

% Exercício 1
% 1.1 acha o tamanho da lista
tamlista([],0).
tamlista([_|B],X) :- tamlista(B,X1), X is X1 + 1.
% 1.2 troca os elementos de lugar, colocando o maior elemento para o final da lista
troca([],[]).
troca([A],[A]).
troca([A,B|C],[B|D]) :- 
    tamlista(A,X),
    tamlista(B,Y),
    X > Y,
    troca([A|C],D). 

troca([A,B|C],[A|D]) :- 
    tamlista(A,X),
    tamlista(B,Y),
    X =< Y,
    troca([B|C],D).
% 1.3 confere se a lista está ordenada
confere([]).
confere([_]).
confere([A,B|C]) :- tamlista(A,X),tamlista(B,Y), X =< Y , confere([B|C]).
% 1.4 ordena a lista usando o método bubble sort
lsort(Lista, Ordenada) :-
    confere(Lista),
    Ordenada = Lista,
    !.
lsort(Lista, Ordenada) :-
    troca(Lista,ListaOrdenando),
    lsort(ListaOrdenando,Ordenada).

% Exercício 2
% 2.1 Comprimento de cada sublista
comprimento([], []).
comprimento([A|B], [(A,X)|Y]) :-
    length(A, X),
    comprimento(B, Y).

% 2.2 Frequência de cada comprimento
frequenciaComprimento(Pares, Frequencias) :-
    extrairTamanhos(Pares, Tamanhos),
    msort(Tamanhos, Ordenados),
    contarFrequencias(Ordenados, Frequencias).

extrairTamanhos([], []).
extrairTamanhos([(_,T)|Resto], [T|Ts]) :-
    extrairTamanhos(Resto, Ts).

contarFrequencias([], []).
contarFrequencias([T|Ts], [(T,Freq)|Resto]) :-
    contarOcorrencias(T, [T|Ts], Freq, Remaining),
    contarFrequencias(Remaining, Resto).

contarOcorrencias(_, [], 0, []).
contarOcorrencias(T, [T|Ts], Freq, Remaining) :-
    !,
    contarOcorrencias(T, Ts, F1, Remaining),
    Freq is F1 + 1.
contarOcorrencias(_, Lista, 0, Lista).

% 2.3 Associar cada sublista à frequência do seu comprimento
associarFrequencia([], _, []).
associarFrequencia([(Sub,Tam)|Resto], Frequencias, [(Freq-Sub)|Rs]) :-
    buscarFrequencia(Tam, Frequencias, Freq),
    associarFrequencia(Resto, Frequencias, Rs).

buscarFrequencia(Tam, [(Tam,Freq)|_], Freq) :- !.
buscarFrequencia(Tam, [_|Resto], Freq) :-
    buscarFrequencia(Tam, Resto, Freq).

% 2.4 Ordenar pela frequência (usando insertion sort)
inserirOrdenado(X-S, [], [X-S]).
inserirOrdenado(X-S, [Y-T|Resto], [X-S,Y-T|Resto]) :- X =< Y, !.
inserirOrdenado(X-S, [Y-T|Resto], [Y-T|Resto2]) :- inserirOrdenado(X-S, Resto, Resto2).

ordena([], []).
ordena([H|T], Ordenada) :-
    ordena(T, OrdT),
    inserirOrdenado(H, OrdT, Ordenada).

ordenaFrequencia(Lista, Ordenada) :-
    ordena(Lista, ListaOrdenada),
    extrairSublistas(ListaOrdenada, Ordenada).

extrairSublistas([], []).
extrairSublistas([_-Sub|Resto], [Sub|Rs]) :- extrairSublistas(Resto, Rs).

% lfsort
lfsort(Lista, Ordenada) :-
    comprimento(Lista, Pares),
    frequenciaComprimento(Pares, Frequencias),
    associarFrequencia(Pares, Frequencias, ListaAssociada),
    ordenaFrequencia(ListaAssociada, Ordenada).