bode(num,den);
[mag,phase,w] = bode (num,den);
[mag,phase] = bode (num,den,w);
subplot(211), loglog(w,mag), title('Magnitud'), xlabel('rad/s'); 
subplot(212), semilogx(w,phase), title('Fase'), xlabel('rad/s');