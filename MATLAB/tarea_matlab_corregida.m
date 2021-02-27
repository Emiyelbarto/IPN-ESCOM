%G(s) = K / (1 + tau)
%Vector para medici�n de tiempo
t = [0:.1:10]';
%constante numerador
K = 1;
%constante tau
tau = 1;
%Vector para las iteraciones y valores del escal�n
vectDelta = [1:1:10];
%Vector para guardar iteraci�n escal�n
Y = [];
%Recorremos las iteraciones del escal�n
for ind = 1:length(vectDelta)
    %Multiplicamos el numerador por la iteraci�n
    num = K * vectDelta(ind);
    %Denominador t 
    den = [tau 1];
    %gr�fica step con el numerador multiplicado
    ye = step(num,den,t);
    %guardamos resultado en arreglo
    Y = [Y, ye];
end
%graficamos
plot(t,Y);
title ('Tarea MatLab');
ylabel ('Voltaje(V)');
xlabel ('Tiempo(seg)');
grid;