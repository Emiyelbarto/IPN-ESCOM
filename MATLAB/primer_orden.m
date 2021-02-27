%G(s) = K / (1 + tau)
K = 1; 
tau = 1;
num = K; 
den = [tau 1];
t = [0:0.1:10]';
ye = step(num,den,t);
plot(t,ye);
title ('Respuesta a un escalon unitario');
xlabel ('tiempo(seg)');
grid;