verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = 'Introducir un número entero positivo que servirá como limite inferior\n';
    a = input(prompt);
    flag = verificacion(a);
end
fprintf('%d es el limite inferior\n',a);
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = 'Introducir un número entero positivo que servirá como limite superior\n';
    b = input(prompt);
    if a == b
        flag == 0;
    else
        flag = verificacion(b);
    end
end
fprintf('%d es el limite superior\n',b);
C = a:b;
disp(C);
Tam = numel(C);
impares = sum(rem(C,2));
Numpares = Tam - impares;
CPares = C(rem(C, 2) == 0);
fprintf('Hay %d numeros pares en el rango indicado\n',Numpares);
disp(CPares);