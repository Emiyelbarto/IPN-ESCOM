%verificacion
%G(s) = K / (1 + tau)
K = 1; 
tau = 1;
num = K; 
den = [tau 1];
t = [0:0.1:10]';
yRP = ye(length(ye)); % Valor en regimen permanente
n = 1;
while ye(n) < 0.63*yRP
n=n+1;
end
% Constante de tiempo (0.1 es el intervalo transcurrido entre dos medidas,
% se le resta 1, porque los indices empiezan en 1):
tauEstim = 0.1*(n-1);
ramp = t;
yr = lsim (num,den,ramp,t);
plot (t,yr,t,ramp);
title ('Respuesta a una rampa');
xlabel ('tiempo(seg)');
grid;