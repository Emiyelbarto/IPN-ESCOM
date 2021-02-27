verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero para la secuenci de Collatz: \n');
    lim = input(prompt);
    flag = verificacion(lim);
end
count = 0;
while (lim ~= 1)
    if(rem(lim,2) == 0) %par
        fprintf('n = %d / 2',lim);
        lim = lim / 2;
        fprintf(' = %d\n',lim);
    else
        fprintf('n = (%d * 3) + 1',lim);
        lim = (lim * 3) + 1;
        fprintf(' = %d\n',lim);
    end
    count = count + 1;
end
fprintf('n = %d\n',lim);
fprintf('Tomó %d iteraciones',count);