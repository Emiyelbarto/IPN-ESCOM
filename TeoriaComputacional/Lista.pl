%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 1: Definici\'on recursiva de lista
%
% Define un predicado "es_lista(X)" tal que tenga exito si "X" 
% es una lista y no lo tenga en caso contrario.
%
% Ejemplos                                                              
%
%  ?- es_lista(f(a,b)).
%  No
%  ?- es_lista([]).
%  Yes
%  ?- es_lista([a,b]).
%  Yes
%
% Nota: Estudia el comportamiento de los  predicados predefinidos is_list/1 y
% proper_list/1 y comp\'aralos con es_lista/1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

es_lista([]).
es_lista([_|X]):-
	es_lista(X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 2: Concatenacion de listas
% Define el predicado conc(L1,L2,L3) de forma que si L1 y L2 son 
% listas, entonces L3 es la lista obtenida escribiendo los elementos 
% de L2 a continuaci\'on de los elementos de L1. Por ejemplo, 
% si L1 es [a,b] y L2 es [c,d], entonces L3 es [a,b,c,d].
%
% Ejemplos
%
% ?- conc([a,b],[c,d,e],L).
% L = [a, b, c, d, e] ;
% 
% ?- conc([a,b],L,[a,b,c,d]).
% L = [c, d] ;
% 
% ?- conc(L1,L2,[a,b]).
% L1 = []
% L2 = [a, b] ;
% L1 = [a]
% L2 = [b] ;
% L1 = [a, b]
% L2 = [] ;
% 
% ?- conc(L1,[b|L2],[a,b,c]).
% L1 = [a]
% L2 = [c] ;
% 
% ?- conc(_,[b|_],[a,b,c]).
% Yes
% 
% ?- conc(_,[b,c|_],[a,b,c,d]).
% Yes
% 
% ?- conc(_,[b,d|_],[a,b,c,d]).
% No
% 
% ?- conc(_,[X],[b,a,c,d]).
% X = d ;
% No
%
% Nota: conc/3 corresponde con el predicado predefinido append/3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

conc([],L,L).
conc([X|L1],L2,[X|L3]):-
	conc(L1,L2,L3).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 3: Par consecutivo en una lista
% Define el predicado "par_en_lista(L1,L2)" donde L1 es una lista de dos
% elementos que aparecen de forma consecutiva en la lista L2.
% Ejemplos
%
%  ?- par_en_lista(L,[1,2,3,4]).
%  L = [1, 2] ;
%  L = [2, 3] ;
%  L = [3, 4] ;
%  No
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

par_en_lista([],[]).
par_en_lista([],[_]).
par_en_lista([X,Y],L):-
	conc(L1,_L2,L),
	conc(_L3,[X,Y],L1).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 4: Define la relaci\'on rota(L1,L2) 
% de forma que la lista L2 sea la lista L1 en la que el primer elemento se ha
% situado en la \'ultima posici\'on. Usa la relaci\'on "conc" ya definida.
%
% Ejemplos
%
% ?- rota([a,b,c,d],L).
% L = [b, c, d, a] 
% Yes
% 
% ?- rota(L,[b,c,d,a]).
% L = [a, b, c, d] 
% Yes
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

rota([],[]).
rota([X|L1],L2):-
	conc(L1,[X],L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 5: Define el predicado 
%	                 inversa(L1,L2)
% de forma que si L1 es una lista, entonces L2 es la lista obtenida
% invirtiendo los elementos de L1. Por ejemplo, si L1 es [a,b,c]
% entonces L2 es [c,b,a].
%
% Ejemplos:
%
%  ?- inversa([a,b,c],L).
%    L = [c, b, a] ;
%    No
%
% Nota: inversa/2 coincide con el predicado predefinido reverse/2  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inversa([],[]).
inversa([X|L1],L2):-
	inversa(L1,L3),
	conc(L3,[X],L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 6: Define recursivamente la relacion 
%	              borrado_1(X,L1,L2)
% de forma que L2 sea una lista obtenida eliminando una ocurrencia 
% del elemento X en la lista L1.  
%
% Ejemplos
%
% ?- borrado_1(a,[a,b,a],L).
% L = [b, a] ;
% L = [a, b] ;
% No
% 
% ?- borrado_1(a,L,[1,2]).
% L = [a, 1, 2] ;
% L = [1, a, 2] ;
% L = [1, 2, a] ;
% No
% 
% ?- borrado_1(X,[1,2,3],[1,3]).
% X = 2 ;
% No
%
% Nota: borrado_1/3 corresponde con el predicado predefinido select/3.
%        Comp\'aralo con delete/3.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

borrado(X,L1,L2):-
	conc(L5,L4,L1),
	conc(L3,[X],L5),
	conc(L3,L4,L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 7: Define la relaci\'on 
%	insertado(X,L1,L2)
% de forma que L2 sea una lista obtenida insertando el elemento X 
% en la lista L1. Usa la relaci\'on "borrado" ya definida.
%
% Sesi\'on 
%
% ?- insertado(a,[1,2],L).
% L = [a, 1, 2] ;
% L = [1, a, 2] ;
% L = [1, 2, a] ;
% No
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

insertado(X,L2,L1):-
	conc(L3,L4,L2),
	conc(L3,[X],L5),
	conc(L5,L4,L1).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 8: Define recursivamente la relaci\'on 
%	           permutacion_1(L1,L2)
% de forma que la lista L2 sea una permutaci\'on de los elementos de 
% la lista L1. Usa la relaci\'on "insertado" definida anteriormente. 
%
% Ejemplos
%
% ?- permutacion_1([a,b,c],L).
% L = [a, b, c] ;
% L = [b, a, c] ;
% L = [b, c, a] ;
% L = [a, c, b] ;
% L = [c, a, b] ;
% L = [c, b, a] ;
% No
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

permutacion_1([],[]).
permutacion_1([X|L1],L2):-
	permutacion_1(L1,L3),
	insertado(X,L3,L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 9: ¿Qu\'e t\'erminos hay que poner en lugar de los
% asteriscos para que el programa
%
%           permutacion_2([],*).
%           permutacion_2(L1,[X|L2]) :-            
%                borrado_1(*,*,*),
%                permutacion_2(L3,*).
%
% sea una definici\'on de permutacion_2(L1,L2) de forma que la lista L2 sea 
% una permutaci\'on de los elementos de la lista L1?
%
% Ejemplos
%
% ?- permutacion_2([a,b,c],L).
% L = [a, b, c] ;
% L = [a, c, b] ;
% L = [b, a, c] ;
% L = [b, c, a] ;
% L = [c, a, b] ;
% L = [c, b, a] ;
% No
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

permutacion_2([],[]).
permutacion_2(L1,[X|L2]) :-            
	borrado(X,L1,L3),
	permutacion_2(L3,L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 10: Define la relaci\'on 
%	n_esimo(N,L,X) 
% de forma que X sea el N-\'esimo elemento de la lista L.
%
% Ejemplos
%
% ?- n_esimo(2,[a,b,c,d],X).
% X = b
% Yes
%
% Nota: Estudia el comportamiento de los predefinidos nth0/3 y nth1/3
%       y comp\'aralos con n_esimo/3
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

longitud([],0).
longitud([_|L],N):-
	longitud(L,N1),
	N is N1+1.

n_esimo(1,[Y|_],Y).
n_esimo(N,[Y|L],X):-
	longitud([Y|L],N1),
	N < N1+1,
	N > 1,
	N2 is N-1,
	n_esimo(N2,L,X).













