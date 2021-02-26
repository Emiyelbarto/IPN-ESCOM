LIBRARY IEEE;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

entity led1 is 
port(
	X0: in std_logic;
	Y0: out std_logic
);
end led1;

architecture Behavioral of led1 is
begin
	encendido:process(X0)
		begin
			if X0 = '1' then
				Y0 <= '1';
			else
				Y0 <= '0';
			end if;
		end process encendido;
end behavioral;