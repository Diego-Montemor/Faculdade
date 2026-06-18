% Diego Vianna Leite Montemor   2025.1.08.023

lsort(Lista, Ordenada) :-  troca(Lista,ListaOrdenando), lsort(ListaOrdenando,ListaOrdenando) .
     
confere([]).
confere([_]).
confere([A,B|C]) :- tamlista(A,X),tamlista(B,Y), X =< Y , confere([B|C]).

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

tamlista([],0).
tamlista([_|B],X) :- tamlista(B,X1), X is X1 + 1.