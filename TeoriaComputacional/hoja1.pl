%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 1: 
% Supongamos que tenemos el siguiente conocimiento sobre 
% divisibilidad:
%   " 2 divide a 6"
%   " 2 divide a 12"
%   " 3 divide a 6"
%   " 3 divide a 12"
%   " Si un número es divisible por 2 y por 3 entonces es 
%     divisible por 6"
%
% Escribir un programa que represente este conocimiento y usarlo 
% para responder a las siguientes preguntas:
% (1) ¿Existe algún múltiplo de 2?
% (2) ¿Cuáles son los divisores de 6?
% (3) ¿Conocemos algún múltiplo de 6?
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

divide(2,6).
divide(2,12).
divide(3,6).
divide(3,12).
divide(6, X):-
	divide(2, X),
	divide(3, X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 2: En este ejercicio y los siguientes vamos a 
% realizar un ejemplo que describe la carta de un restaurante. 
% Los objetos que interesan son los platos que se pueden consumir 
% y una primera clasificación puede ser la siguiente:
% * Entradas: paella, gazpacho, consomé
% * Carne: filete de cerdo, pollo asado
% * Pescado: trucha, bacalao
% * Postre: flan, nueces con miel, naranja
%
% Escribe como programa Prolog la clasificación de comidas   
% del restaurante. El programa constara de 10 cláusulas y los 
% predicados a usar son entrada/1, carne/1, pescado/1 y postre/1.	     % Prueba después el programa con preguntas como                           
%    ?- carne(X).                                                         
%    ?- carne(X), postre(X).                                                
%     ... etc...                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

entrada(paella).
entrada(gazpacho).
entrada(consome).
carne(filete_de_cerdo).
carne(pollo_asado).
pescado(trucha).
pescado(bacalao).
postre(flan).
postre(nueces_con_miel).
postre(naranja).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 3: Definir la relación "plato_principal(X)" que 
% indicara que un plato principal es un plato de carne o de 
% pescado.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

plato_principal(X):-
	carne(X).
plato_principal(X):-
	pescado(X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 4: Definir la relación "comida(X,Y,Z)" que indicara 
% que la comida consta de tres platos, una entrada "X", un plato  
% principal "Y" y un postre "Z". 
% Pidiéndole respuestas sucesivas a la pregunta ?- comida(X,Y,Z).
% podemos generar todas las posibles comidas del restaurante.  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

comida(X, Y, Z):-
	entrada(X),
	plato_principal(Y),
	postre(Z).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 5: 
% (a) ¿Cómo se pregunta por las comidas con pescado sin modificar 
%     el programa? comida(X, Y, Z), pescado(Y).
% (b) ¿Cómo se pregunta por las comidas con naranja sin modificar 
%     el programa? comida(X, Y, naranja).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 6: Para completar un poco la información que tenemos 
% sobre las comidas del restaurante vamos a mirar la lista de las 
% calorías que aporta cada plato: 
% * Una ración de paella aporta 200 calorías           
% * Una ración de gazpacho aporta 150 calorías         
% * Una ración de consomé aporta 300 calorías          
% * Una ración de filete de cerdo aporta 400 calorías  
% * Una ración de pollo asado aporta 280 calorías      
% * Una ración de trucha aporta 160 calorías           
% * Una ración de bacalao aporta 300 calorías          
% * Una ración de flan aporta 200 calorías             
% * Una ración de nueces con miel aporta 500 calorías  
% * Una ración de naranja aporta 50 calorías           
%
% Definir la relacion "calorias(X,N)" que indicará  que una 
% ración de "X" tiene "N" calorías.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

calorias(paella, 200).
calorias(gazpacho, 150).
calorias(consome, 300).
calorias(filete_de_cerdo, 300).
calorias(pollo_asado, 280).
calorias(trucha, 160).
calorias(bacalao, 300).
calorias(flan, 200).
calorias(nueces_con_miel, 500).
calorias(naranja, 50).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 7: Definir la relacion "valor_calorico(X,Y,Z,V)"  
% que indicará que la comida comida(X,Y,Z) suma en total "V" 
% calorías.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

valor_calorico(X, Y, Z, V):-
	comida(X, Y, Z),
	calorias(X, V1),
	calorias(Y, V2),
	calorias(Z, V3),
	V is V1+V2+V3.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 8: Definir la relacion "comida_equilibrada(X,Y,Z)" 
% que indicará que la comida comida(X,Y,Z) no supera las 800 
% calorías.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

comida_equilibrada(X, Y, Z):-
	valor_calorico(X, Y, Z, V),
	V<800.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ejercicio 9:
% Considera el siguiente programa que describe algunas relaciones 
% familiares

padre(andres,bernardo).
padre(andres,belen).
padre(andres,baltasar).
padre(baltasar,david).
padre(david,emilio).
padre(emilio,francisco).
madre(ana,bernardo).
madre(ana,belen).
madre(ana,baltasar).
madre(belen,carlos).
madre(belen,carmen).

% extender el programa para definir las siguientes relaciones 
% familiares
% (9.1) abuelo/2
% (9.2) progenitor/2
% (9.3) nieta/2
% (9.4) antepasado/2
% (9.5) descendiente/2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

abuelo(X, Y):-
	padre(X, Z),
	padre(Z, Y).
abuelo(X, Y):-
	padre(X, Z),
	madre(Z, Y).
progenitor(X, Y):-
	padre(X, Y).
progenitor(X, Y):-
	madre(X, Y).
mujer(belen).
mujer(ana).
mujer(carmen).
nieta(X, Y):-
	mujer(X),
	progenitor(Y, Z),
	progenitor(Z, X).
antepasado(X, Y):-
	progenitor(X, Y).
antepasado(X, Y):-
	progenitor(X, Z),
	antepasado(Z, Y).
descendiente(X, Y):-
	antepasado(Y, X).


















