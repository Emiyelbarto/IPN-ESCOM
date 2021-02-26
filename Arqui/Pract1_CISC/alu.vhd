library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
use work.operaciones.all;

entity ALU is
port(
	dato: in std_logic_vector(3 downto 0);
	sel0, sel1: in std_logic_vector(2 downto 0);
	en: in std_logic;
	u, d, c: out std_logic_vector(3 downto 0)
);
end entity ALU;

--ANODO COMUN
--1111*1111=1110 0001
-- 15 * 15 = 225
--datoA*datoB=f;

architecture funcion of ALU is

signal datoA, datoB: integer;
signal op_SUM, op_RES, op_REX, op_DIV, op_MUL: integer;
signal acum, acum_tmp: integer;
signal sum, res, rex, div, mul: integer;
signal op: std_logic_vector(7 downto 0);
constant limite: std_logic_vector(7 downto 0):="11100001" ;

begin 
	
	DAXTO: process(dato, en)
		begin
			if en = '0' then
				datoA<= conv_integer(unsigned(dato));
			else
				datoB<= conv_integer(unsigned(dato));
			end if;
	end process;
	
	sum<= SUMA(datoA, datoB);
	res<= RESTA(datoA, datoB);
	rex<= RESIDUO(datoA, datoB);
	div<= COCIENTE(datoA, datoB);
	mul<= MULTIPLICACION(datoA, datoB);
	
	OPERAXION: process(sum, res, rex, div, mul, acum, acum_tmp, sel0)
	begin
		if sel0= "000" then--SUMA
			--acum<= conv_std_logic_vector(sum, 8);
			acum_tmp<= sum;
			
		elsif sel0= "001" then--RESTA SOLO VALORES POSITIVOS
			--acum<= conv_std_logic_vector(res, 8);
			acum_tmp<= res;
		
		elsif sel0= "010" then--RESIDUO
			--acum<= conv_std_logic_vector(rex, 8);
			acum_tmp<= rex;
		
		elsif sel0= "011" then--COCIENTE
			--acum<= conv_std_logic_vector(div, 8);
			acum_tmp<= div;
		
		elsif sel0= "100" then--MULTIPLICACION
			--acum<= conv_std_logic_vector(mul, 8);
			acum_tmp<= mul;
			
		elsif sel0= "101" then--CARGA EL ACUMULADOR TEMPORAL AL ACUMULADOR PRINCIPAL
			acum<= acum_tmp;
		
		elsif sel0= "110" then--BORRA ACUMULADOR TEMPORAL
			acum_tmp<= 0;
		
		elsif sel0= "111" then--BORRA ACUMULADOR PRINCIPAL
			acum<= 0;
					
		else--MANTIENE
		
		end if;
	end process;
		
	op_SUM<= SUMA(acum_tmp, acum);
	op_RES<= RESTA(acum_tmp, acum);
	op_REX<= RESIDUO(acum_tmp, acum);
	op_DIV<= COCIENTE(acum_tmp, acum);
	op_MUL<= MULTIPLICACION(acum_tmp, acum);
	
	ACUMUXLADORES: process(acum, acum_tmp, sel1, op_SUM, op_RES, op_REX, op_DIV, op_MUL, op)
	begin
		if sel1= "000" then--SUMA
			op<= conv_std_logic_vector(op_SUM, 8);
			if (op > limite) then
				op<="11100001";
			end if;	
			
		elsif sel1= "001" then--RESTA
			op<= conv_std_logic_vector(op_RES, 8);
			if (op > limite) then
				op<="11100001";
			end if;
		
		elsif sel1= "010" then--RESIDUO
			op<= conv_std_logic_vector(op_REX, 8);
			if (op > limite) then
				op<="11100001";
			end if; 
		
		elsif sel1= "011" then--COCIENTE
			op<= conv_std_logic_vector(op_DIV, 8);
			if (op > limite) then
				op<="11100001";
			end if;
		
		elsif sel1= "100" then--MULTIPLICACION
			op<= conv_std_logic_vector(op_MUL, 8);
			if (op > limite) then
				op<="11100001";
			end if;
		
		else--MANTIENE
			
		end if;
	end process;
	
	DECIMAL: process(op)--CONVERSION DE BINARIO A UNIDADES, DECENAS, ....
	variable ext: std_logic_vector(18 downto 0);
	begin
		ext:= (others=> '0');
		ext(10 downto 3):= op;
		for i in 0 to 4 loop
			
			if ext(11 downto 8) >= 5 then
				ext(11 downto 8):= ext(11 downto 8) + 3;
			end if;
			
			if ext(15 downto 12) >=5 then
				ext(15 downto 12):= ext(15 downto 12)+3;
			end if;
			
			ext(18 downto 1):= ext(17 downto 0);
		end loop;
		
		u<= ext(11 downto 8);
		d<= ext(15 downto 12);
		c<= "0"&ext(18 downto 16);
		
	end process;
	
	
end funcion;