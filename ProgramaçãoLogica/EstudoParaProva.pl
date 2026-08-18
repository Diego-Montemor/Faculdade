ordena2lista([],[],[]).
ordena2lista([],L2,L2).
ordena2lista(L1,L1,[]).
ordena2lista([A|L1],[A|L2],[B|L3]) :- A =< B, ordena2lista(L1,L2,[B|L3]).
ordena2lista([A|L1],[B|L2],[B|L3]) :- A > B, ordena2lista([A|L1],L2,L3).

trunca(0,_,[]).
trunca(N,[X|L],[X|L2]) :- N1 is N-1, trunca(N1,L,L2).