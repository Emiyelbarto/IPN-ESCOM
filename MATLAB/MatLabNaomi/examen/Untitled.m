prompt = 'Introducir el valor x\n';
x = input(prompt);
prompt = 'Introducir el valor y\n';
y = input(prompt);
prompt = 'Introducir el valor r\n';
r = input(prompt);

ImgSizeX = x +100;
ImgSizeY = y +100;
[columnsInImage rowsInImage] = meshgrid(1:ImgSizeX, 1:ImgSizeY);
% Next create the circle in the image.
centerX = x;
centerY = y;
radius = r;
circlePixels = (rowsInImage - centerY).^2 + (columnsInImage - centerX).^2 <= radius.^2;
image(circlePixels) ;
%colormap(jet(8));
title('Circulo');

