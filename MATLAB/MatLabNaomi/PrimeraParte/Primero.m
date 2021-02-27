verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = 'Introducir un número entero positivo\n';
    x = input(prompt);
    flag = verificacion(x);
end
fprintf('%d^2 = ',x);
for i = 1:x
    if(x == 1)
        fprintf('1 =');
        break;
    elseif(x == 2)
        fprintf('1 + 2 + 1 =');
        break;
    elseif(x == 3)
        fprintf('1 + 2 + 3 + 2 + 1 =');
        break;
    end
end
fprintf(' %d\n',x^2);