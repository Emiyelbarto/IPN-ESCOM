verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = 'Introducir un número entero positivo\n';
    x = input(prompt);
    flag = verificacion(x);
end
%fprintf('Bien por meter un numero positivo :)\n');
if(x == 1)
    fprintf('El numero %d no es primo\n',x);
elseif(x > 1)
    a = primes(x);
    prm=a((length(a)));
    if x==prm;
        fprintf('El numero %d es primo\n',x);
    else
        fprintf('El numero %d no es primo\n',x);
    end
end
