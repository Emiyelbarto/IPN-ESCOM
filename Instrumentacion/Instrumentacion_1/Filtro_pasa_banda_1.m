%**************************************************************************
%DISE�O DEL CONTROL PI (En Isla)
%**************************************************************************
%clc;
close all;
clear all;
s=tf('s');
z=tf('z');
% Datos
%B=0.006;
%Gc=(1.94*s^2+12.244*s+25.968)/s;
%Gc1=2.04*s+12.244+(25.968/s);
%Gc2=-0.1*s;
%Gp=10/(s*(s+1));
%sisotool
%C=1e-6;
%R=400;
%L=1.583e-3;
%Gp=(s*L)/(s^2*C*L*R+s*L+R);
Gp= 1740 /(((0.25*s)+1)*s);
bode (Gp);
% C=594.6e-12;
% R=5000;
% L=20.57e-6;
% Gp=(s*C*R)/(s^2*C*L+s*C*R+1);
Dig1=c2d(Gp,0.011,'tustin')
[NUM,DEN] = tfdata(Dig1,'v')
sisotool;
% Gp1=1/(s*C*R+1);
% bode(Gp1, 'r')
% hold on
% 
% 
% %Gp=10/(s+1);
% %YsDs=Gp/(1+(Gp*(Gc1+Gc2)));
% %YsDs1=Gp/(1+(Gp*(Gc1)));
% %figure (5);
% %M=0.5;
% %B=0;
% %=122.2;
% %B=0;
% % K=22.2;
% % Gmr=1/(((s^2)*M) +(B*s)+K);
% %Gmr=(s+6)/((s+4)*(s^2+(4*s)+8));
% %step(Gmr);
% %margin (Gmr);
% %Gp= (100*(s+1))/((0.2*s+1)*(0.1*s+1));
% % k=200;
% % c=6.0;
% % m=0.5;
% % wo=sqrt((k/m)-((c^2)/(4*m^2)));
% % E=0.6;
% % B=wo*E;
% %Gp=-(s*s)/((s*s)+(2*B*s)+(wo^2));
% %margin (Gp);
% %bode (Gp);
%sisotool
% 
% %**************************************************************************
% 
% 
% %**************************************************************************
% k=1;
% wc=500*2*pi;
% e=0.707;
% Gp=((k*wc*wc)/((s*s)+(2*e*wc*s)+(wc*wc)));
% bode(Gp)
% Dig1=c2d(Gp,1/1000000,'tustin')
% [NUM,DEN] = tfdata(Dig1,'v')

% 
%                                                                                                                                                                          