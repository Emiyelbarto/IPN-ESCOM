prompt = ('Escribir la n-esima potencia de 2\n');
x = input(prompt);
potencias = 0:x;
fprintf('Las potencias de 2 de 0 hasta %d son:\n',x);
for i = 1:length(potencias)-1
    if(i ~= length(potencias)-1)
        fprintf('%d, ',2^(i-1));
    else
        fprintf('%d\n',2^(i-1));
    end
end