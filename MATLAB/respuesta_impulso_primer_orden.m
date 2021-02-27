%G(s) = K / (1 + tau)
K = 1; 
tau = 1;
num = K; 
den = [tau 1];
t = [0:0.1:10]';
yi = impulse (num,den,t);
plot (t,yi);
title ('Respuesta a un impulso');
xlabel ('tiempo(seg)');