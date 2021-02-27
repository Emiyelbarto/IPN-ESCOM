close all;
clear all;
E = 5;
c = 3 / 2;
T = 0:100;
k = 1;
d = 1;

Ro = 30;

for i = 1:100
    Q = E / (k * c * T(i));
    x(i) = Q;
end

[idx,idx] = sort(x);
y = x;
f1 = figure;
scatter(x(idx),y);
title('Flujo de gas');
xlabel('x');
ylabel('y');


%f = @(x) Ro * (1 + x + symsum(1:x));
%RW = Ro * (1 + d * T(10));
f = @(x) Ro * (1 + d + x);
ezplot( f, 0, 4 );
title('Resistencia entre R1 y R4');
xlabel('x');
ylabel('y');



f1 = @(x) (x * x * Ro);
ezplot(f1, 1 , 11);
title('Valores de distribución');
xlabel('x');
ylabel('y');


fv = @(x) (x * 10);
ezplot(fv,10,150);
title('Valores de voltaje');
xlabel('x');
ylabel('y');