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
% 2.1 detarmina o comprimento de cada sublista
comprimento([],[([],0)]).
comprimento([A|B], [(A,X)|Y]) :- tamlista(A, X), comprimento(B,Y).
% 2.1 calcula a frequencia de cada tamanho
frequenciaComprimento([],[]).
frequenciaComprimento([A|B],[(X,Y)|Z]) :- tamlista(A,X), frequenciaComprimento(B,Z).
