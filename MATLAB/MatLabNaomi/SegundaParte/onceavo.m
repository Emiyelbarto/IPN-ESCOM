x = 0:10;
x(1)= 1;
x(2)= 0;
for i = 1:10
    x(i+2) = 2*x(i)-x(i+1);
    fprintf('x(%d)= %d\n',i,x(i+2));
end