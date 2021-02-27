verificacion = @(n) (rem(n,1) == 0) & (n > -1); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero para calcular su factorial: \n');
    lim = input(prompt);
    flag = verificacion(lim);
end
res = factorial(lim);
fprintf('El resultado es: %d\n',res);