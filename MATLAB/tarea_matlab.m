t = [0:0.2:30]';
d = 1; 
wn = 1;
vectDelta = [1:1:4]; 
num = wn^2; 
Y = []; 
for ind = 1:length(vectDelta) 
    wn = vectDelta(ind); 
    den = [1,2*d*wn,wn^2]; 
    y = step (num,den,t); 
    Y = [Y, y]; 
end
plot (t,Y); 
title ('Respuesta a un escalon unitario'); 
xlabel ('tiempo(seg)'); 
grid;
