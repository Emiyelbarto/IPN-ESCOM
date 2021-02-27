function a=FabonacciSequence(n)
    a(1)=0;
    a(2)=1;
    for i=1:10;
        a(i+2)=a(i+1)+a(i);
        fprintf('Numero %d = %d\n',i,a(i+2));
    end
end