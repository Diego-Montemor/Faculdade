% Exercicio 1
analisaLista([]) :- write('lista vazia'), nl.
analisaLista([X|Y]) :-
    write('cabeca: '), write(X), nl,
    write('cauda: '), write(Y).

% Exercicio 2
pertence(A,[A,_]).
pertence(A,[_|B]) :- pertence(A,B). 

rmDup([],[]).
rmDup([A|B],C) :- pertence(A,B), rmDup(B,C).
rmDup([A|B],[A|C]) :- \+ pertence(A,B), rmDup(B,C).

% Exercicio 3
trocaLista([],_,_,[]) :- write('lista vazia'), nl.
trocaLista([A|B],A,X,[X|C]) :- trocaLista(B,A,X,C).
trocaLista([A|B],X,Y,[A|C]) :- A\=X, trocaLista(B,X,Y,C).
%       {Conclusão}                  {Condição}


% Exercicio 4
potencia([],[[]]).
potencia([A|B],[A|C]) :- potencia(B,C).


% Exercicio 5
maisLongo([],[_|_]).
maisLongo([_|B],[_|D]) :- maisLongo(B,D).

tam([],0).
tam([_|C], N) :- tam(C,N1), N is N1 + 1.

maisLongo2([],[],0).
maisLongo2([_|_],[],1).
maisLongo2([],[_|_],2).
maisLongo2([_|B],[_|D],X) :- maisLongo2(B,D,X).


% Exercicio 6
distancia((X,Y),(A,B),D) :-
    D is sqrt((X-A)*(X-A)+(Y-B)*(Y-B)).

% Exercicio 7

% Exercicio 8
elementoN([X|_],1,X).
elementoN([_|B],I,X) :- I> 1 ,  I1 is I - 1 , elementoN(B,I1,X).

% Exercicio 11
constroiLista(A,A,[A]).
constroiLista(B,A,[]) :- B > A.
constroiLista(A,B,[A|C]) :- A < B , A1 is A + 1 , constroiLista(A1,B,C). 













