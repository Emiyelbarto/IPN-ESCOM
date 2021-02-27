verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 1; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 1)
    prompt = 'Introducir un número\n';
    x = input(prompt);
    flag = verificacion(x);
    if (flag == 1)
        break
    end
end
n = 1:x; %Iniciamos el arreglo donde se guardaran los numeros
res = n; %Iniciamos arreglo donde se guardara el resultado
res(~mod(res,7)&res~=7) = [];
fprintf('El arreglo final queda como: \n');
disp(res);