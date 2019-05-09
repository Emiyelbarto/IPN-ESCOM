<?php
//AUTORES: OMAR APARICIO QUIRÓZ, EDUARDO DAVID RAMIREZ OSORIO, JOSÉ EMILIANO PÉREZ GARDUÑO
echo "AUTORES: OMAR APARICIO QUIRÓZ, EDUARDO DAVID RAMIREZ OSORIO, JOSÉ EMILIANO PÉREZ GARDUÑO<br>";
$file = 'datos.csv'; //Declaramos el nombre del archivo
$Lineas = ContarLineas($file); //Obtenemos el número de lineas en el archivo
$Valor = array_fill(0, $Lineas, 0); //Declaramos la variable de valor del archivo simulado.
$Mb = array_fill(0, $Lineas, 0); //Declaramos la variable de tamaño del archivo simulado.
$Costo = array_fill(0, $Lineas, 0); //Declaramos la variable de Costo del archivo simulado.
$Valor = ObtenerValores($file,$Valor); //Obtenemos los datos de valor en los archvivos.
$Mb = ObtenerTam($file,$Mb); //Obtenemos los datos de tamaño en los archvivos.
$handle = VerificarArchivo($file); //Verificamos si el archivo existe.
for ($i=0; $i < $Lineas; $i++) //Obtenemos el costo de cada archivo con respecto a su tamaño y valor.
	$Costo[$i] = $Valor[$i] / $Mb[$i]; //Obtenemos el costo i
$mayor = $Costo[0]; //Definimos el costo de mayor tamaño.
$carga = 0; //Definimos la carga que llevará de acuerdo a los MB del archivo.
echo "Introducir tamaño de Mb de la memoria: ";
//Obtenemos el tamaño de la memoria por el usuario.
?>
<form method = "get" action="">
	<input type="text" name="value">
	<input type="submit">
</form>
<?php
for ($i=0; $i < $Lineas; $i++) { 
	echo "Archivo [".$i."]=> Valor->(".$Valor[$i]."); Mb->(".$Mb[$i].") <br> Costo->(".$Costo[$i].")<br><br>";
}
$TamMemoria = (int) $_GET['value']; //Guardamos el valor introducido por el usuario como tamaño de la memoria
echo "<br>El tamaño es: [".$TamMemoria."]<br>";
if ($TamMemoria <= 0) //Evitamos que el valor introducido sea erroneo
{
	echo "Introducir un valor válido<br>";
	exit(1); //Paramos la ejecución si es un valor inválido
}
$position = 0;//Para seleccionar un archivo
$largest = 0;//Declara el mayor costo
$sizeUsed = 0;//Declara el tamano utilizado
$sizeMB = 0; //Tamano de MB dispoinble
$contValue = 0; //Cuenta el valor que lleva acumulado
$contZeros = 0; //Cuenta el numero de ceros que hay
while ($sizeUsed <= $TamMemoria) {
	$largest = $Costo[0];
	$sizeMB = $Mb[0];
	$position = 0;
	for ($i=1; $i < $Lineas ; $i++) { 
		if ($largest <= $Costo[$i]) {
			$largest = $Costo[$i];
			$position = $i;
			$sizeMB = $Mb[$i];
		}
	}

	for ($i=0; $i < $Lineas; $i++) { 
		if ($Costo[$i] == 0) {
			$contZeros++;
		}
	}

	if ($contZeros < $Lineas)
		$contZeros = 0;
	else
		break;

	if ($sizeMB <= ($TamMemoria - $sizeUsed)) {
		echo "<br>Archivo Seleccionado: [".$position."] - Valor: ".$Valor[$position]." - Mb: ".$Mb[$position]." - Costo: ".$Costo[$position]."";
		$contValue += $Valor[$position];
		$Costo[$position] = 0;
		$sizeUsed = $sizeUsed + $sizeMB;
		echo "<br>Tamaño Utilizado:";
	}
	else
		$Costo[$position] = 0;
}

echo "<br/><br/>Tamaño usado: '".$sizeUsed."'<br>Espacio Disponible: '".($TamMemoria - $sizeUsed)."'";
echo "<br/><br/><strong>Valor total: '".$contValue."'</strong><br/>";

fclose($handle);//Cerramos el archivo.

function MenorTamMb($Mb) //Obtenemos el valor con menor tamaño de MB
{
	$menor = $Mb[0]; 
	for ($i=1; $i < sizeof($Mb); $i++){
		if ($menor > $Mb[$i])
			$menor = $Mb[$i];
	}
	return $menor;
}

function MenorTamArreglo($Mb)//Obtenemos el lugar del menor valor de MB
{
	$z = 0;
	$menor = $Mb[0];
	for ($i=1; $i < sizeof($Mb); $i++) //Recorremos arreglo MB
	{
		if ($menor >= $Mb[$i])
		{
			$menor = $Mb[$i];
			$z = $i;
		}
	}
	return $z;
}

function VerificarArchivo($file)
{
	$Handle = fopen($file,'r');
	if ($Handle) 
		return $Handle;
	else
		exit("unable to open file ($filename)");
}

function ContarLineas($file)
{
	$Handle = VerificarArchivo($file);
	while (!feof($Handle)) 
	{
		$CuentaLinea = fgets($Handle);
		$Lineas++;
	}
	fclose($Handle);
	return $Lineas;
}

function ObtenerValores($file,$Valor)
{
	$x = 0;
	$Handle = VerificarArchivo($file);
	while (!feof($Handle))
	{
		$line = fgets($Handle);
		$datos = explode(',', $line);
		$Valor[$x] = $datos[0];
		$x++;
	}
	fclose($Handle);
	return $Valor;
}

function ObtenerTam($file,$Mb) //Obtenemos los MB en el archivo.
{
	$x = 0; //x será la línea actual
	$Handle = VerificarArchivo($file); //Abrimos el archivo
	while (!feof($Handle)) //Empezamos un ciclo desde el inicio del archivo hasta el final
	{
		$line = fgets($Handle); //Obtenemos el archivo.
		$datos = explode(',', $line); //Separamos los datos
		$Mb[$x] = $datos[1]; //Obtenemos los MegaBytes
		$x++; //Pasamos a la siguiente linea
	}
	fclose($Handle); //Cerramos el archivo.
	return $Mb; //Regresamos los MB
}
?>