
C = 1e-3;
R = 5;
L = 19.57e-3;
Gp = (s*C*R) / (s^2 * C * L + s * C * R + 1);
bode(Gp);

Dig1 = c2d(Gp, 1/100000, 'tustin');
[NUM,DEN] = tfdata(Dig1, 'v');