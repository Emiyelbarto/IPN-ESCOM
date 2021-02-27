num = [.2 .3 1];
den1 = [1 .4 1];
den2 = [1 .5];
den = conv(den1,den2)
[ceros, polos, ganancia] = tf2zp(N,D);
[N,D] = zp2tf (ceros, polos, ganancia);
