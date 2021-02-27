num = [.2 .3 1];
den1 = [1 .4 1];
den2 = [1 .5];
den = conv(den1,den2)
t = [0:.3:15]';
ramp = t;
y = lsim(num,den,ramp,t);
plot (t,y,t,ramp);
title('Respuesta a una rampa');
xlabel('tiempo(seg)');