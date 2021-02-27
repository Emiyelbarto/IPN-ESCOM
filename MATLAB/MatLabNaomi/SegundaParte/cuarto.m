verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el limite inferior: \n');
    lim_inf = input(prompt);
    flag = verificacion(lim_inf);
end

flag = 0;
while(flag == 0)
    prompt = ('Introducir el limite superior: \n');
    lim_sup = input(prompt);
    flag = verificacion(lim_sup);
end
rango = lim_inf+1:lim_sup-1;
for i = lim_inf+1:lim_sup-1
    if(i == lim_sup-1)
        fprintf('%d = ',i);
    else
        fprintf('%d + ',i);
    end
end
res = sum(rango);
fprintf('%d\n',res);