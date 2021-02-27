
K = 1; 
tau = 1;
num = K; 
den = [tau 1];
t = [0:0.1:10]';
ye = step(num,den,t);
plot(t,ye);
ramp = t; 
yr = lsim (num,den,ramp,t); 
plot (t,yr,t,ramp); 
title ('Respuesta a una rampa'); 
xlabel ('tiempo(seg)'); grid;