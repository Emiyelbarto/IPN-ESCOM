close all;
clear all; %#ok<CLALL>
s = tf('s');
hold on
k = 1000;
m = 0.1;
%m = (1.2)^(-1);
Wn = sqrt(k/m);
E = 0.5;
R = 1000;
Ka = 1;
Kd = 1;
Kf = 1;
sisotool
Gs = ((R*m*Ka*Kd)/k) / ((s^2/Wn^2)+(2*E/Wn)*s+1)
