verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero de sumas: \n');
    lim = input(prompt);
    flag = verificacion(lim);
end

fprintf('%c = 4(1',960);
res = 4;
coeficiente = 1;
for i = 0:lim
    if(i == 0)
        coeficiente = coeficiente - (1/3);
        fprintf(' - ');
    else
        if(rem(i,2)==1)
            fprintf(' + ');
            coeficiente = coeficiente + (1/(3+2*i));
        else
            fprintf(' - ');
            coeficiente = coeficiente - (1/(3+2*i));
        end
    end
    fprintf('%d/%d',1,3+2*i);
end
res = res * coeficiente;
fprintf(') = %d\n',res);
fprintf('El resultado es: %d\n',res);