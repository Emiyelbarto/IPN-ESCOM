prompt = ('Introducir un numero\n');
x = input(prompt);
res = factorial(x);
fprintf('El resultado es:\n');
for i = 1:x
    if(x > 1)
        if(i == 1 || i ~= x)
            fprintf('%d * ',i);
        elseif(i == x)
            fprintf('%d',i);
        end
    elseif(x == 1)
        fprintf('%d * %d',i,i);
    end
end
fprintf(' = %d\n',res);
