-- 3CV4 ARQUITECTURA DE COMPUTADORAS
-- MONTES ROMERO PAULINA
-- PEREZ GARDUÑO JOSÉ EMILIANO

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;
-- ES LA ALU FUNCIONAL
ENTITY alu_chida IS
	PORT (
		instruccion : IN std_logic_vector(8 DOWNTO 0);
		salida : OUT std_logic_vector(7 DOWNTO 0)
	);
END ENTITY alu_chida;
-- ARQUITECTURA DE LA ALU
ARCHITECTURE behavioral OF alu_chida IS
	-- SEÑALES DE REGISTROS, CONTADORES, DATOS DE ENTRADA Y DATO DE SELECCIÓN
	SIGNAL sum, sumTemp : std_logic_vector(3 DOWNTO 0);
	SIGNAL datoA, datoB, set_instruccion : std_logic_vector(3 DOWNTO 0);
	SIGNAL regF, regD : std_logic_vector(3 DOWNTO 0);
	SIGNAL selDato : std_logic;
BEGIN
	-- SELECCIÓN DE DATO MUX
	selDato <= instruccion(8);
	-- CREACIÓN DE MICROINSTRUCCIÓN 
	set_instruccion <= instruccion(7 DOWNTO 4);
	-- PROCESO DE INSTRUCCIÓN
	MUX : PROCESS (instruccion, selDato)
	BEGIN
		-- SELECCIÓN DE DATO
		CASE selDato IS
			WHEN '0' => datoA <= instruccion(3 DOWNTO 0);
			WHEN '1' => datoB <= instruccion(3 DOWNTO 0);
			WHEN OTHERS => datoA <= "0000";
				datoB <= "0000";
		END CASE;
	END PROCESS MUX;
	-- SELECIÓN DE OPERACIÓN
	OPERACION : PROCESS (sum, sumTemp, datoA, datoB, regF, regD, selDato)
	BEGIN
		CASE set_instruccion IS
			WHEN "0000" => --Mueve una copia del registro f al destino d.
				regD <= regF;
			WHEN "0001" => --Carga un numero en el acumulador W.
				IF (selDato = '0') THEN
					sum <= datoA;
				ELSE
					sum <= datoB;
				END IF;
			WHEN "0010" => --Suma el contenido del acumW con num d;
				sumTemp <= sum;
				sum <= sumTemp + regD;
			WHEN "0011" => --Realiza la resta d - w
				sumTemp <= sum;
				sum <= regD - sumTemp;
			WHEN "0100" => --Rota el contenido del registro f  una posición a la derecha
				regF <= regF(0) & regF(3 DOWNTO 1);
			WHEN "0101" => --Rota el contenido del registro f  una posición a la izquierda
				regF <= regF(2 DOWNTO 0) & regF(3);
			WHEN "0110" => --Pone en uno el bit bit del filereg.
				regF <= "1111";
			WHEN "0111" => --Pone en cero el bitbitdel filereg.
				regF <= "0000";
			WHEN "1000" => --AND el acumulador y el numero d.Resultado en el acumulador.
				sumTemp <= sum;
				sum <= sumTemp AND regD;
			WHEN "1001" => --OR el acumulador y el numero d.Resultado en el acumulador.
				sumTemp <= sum;
				sum <= sumTemp OR regD;
			WHEN OTHERS => regF <= regF;
				regD <= regD;
		END CASE;
	END PROCESS OPERACION;
END behavioral;