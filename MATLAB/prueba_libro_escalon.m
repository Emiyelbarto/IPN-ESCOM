num = [.2 .3 1];
den1 = [1 .4 1];
den2 = [1 .5];
den = conv(den1,den2)
t = [0:.3:15]';
y = impulse (num,den,t);
plot(t,y)
title('Respuesta escalón unitario');
xlabel('tiempo(seg)');
grid;