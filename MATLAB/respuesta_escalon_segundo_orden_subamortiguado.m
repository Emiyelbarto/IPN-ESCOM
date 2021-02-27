t = [0:0.2:200]';
d = 1; 
vectDelta = [0.1:0.1:0.9]; 
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
