verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero de sumas: \n');
    lim = input(prompt);
    flag = verificacion(lim);
end
res = 1;
fprintf('e = (1/0! + ');
for i = 1:lim
    res = res + (1/factorial(i));
    if(i == lim)
        fprintf('1/%d!',i);
    else
        fprintf('1/%d! +',i);
    end
end
fprintf(')\nCon %d sumas e = %d\n',lim,res);