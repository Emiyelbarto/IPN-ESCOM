verificacion = @(n) (rem(n,1) == 0) & (n > 0); %Verifica si un numero es entero positivo, si es positivo regresa 1, si no lo es regresa 0
flag = 0; %Iniciamos la bandera en 0 para empezar el bucle
while(flag == 0)
    prompt = ('Introducir el numero para el lim superior: \n');
    lim = input(prompt);
    flag = verificacion(lim);
end
inicial = 1:lim;
res = inicial; 
res(~mod(res,3)|~mod(res,7)) = [];
fprintf('Los numeros resultantes son: [');
fprintf('%g ', res);
fprintf(']\n');