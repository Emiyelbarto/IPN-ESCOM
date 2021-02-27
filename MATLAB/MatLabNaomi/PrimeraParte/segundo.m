verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 1; %Iniciamos la bandera en 0 para empezar el bucle
res = []; %Iniciamos el arreglo donde se guardaran los numeros
while(flag == 1)
    prompt = 'Introducir un número\n';
    x = input(prompt);
    flag = verificacion(x);
    if (flag == 0)
        break
    end
    res = [res,x];
end
promedio = mean(res)
count = numel(res);
fprintf('Hubo %d numeros guardados\n',count);
fprintf('Los numeros guardados son:\n');
disp(res)
fprintf('El promedio es: %d\n',promedio);