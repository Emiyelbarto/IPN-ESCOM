num = [.2 .3 1];
den1 = [1 .4 1];
den2 = [1 .5];
den = conv(den1,den2)
t = [0:.3:15]';
noise = rand(size(t));
y = lsim(num,den,noise,t);
plot (t,y,t,noise);
title('Respuesta a un ruido aleatorio');
xlabel('tiempo(seg)');