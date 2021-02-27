verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero: \n');
    n = input(prompt);
    flag = verificacion(n);
end
res = divisors(n);
fprintf('Los divisores son:\n');
disp(res);  