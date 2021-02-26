library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

package operaciones is
    function SUMA (signal p,q: integer) return integer;
	function RESTA (signal x,y: integer) return integer;
	function RESIDUO (signal divisor, dividendo: integer) return integer;
	function COCIENTE (signal divis, divid: integer) return integer;
	function MULTIPLICACION (signal a, b: integer) return integer;
end package;

package body operaciones is

    function SUMA(signal p,q: integer) return integer is 
    begin
        return p+q;
    end function SUMA;
	
	function RESTA(signal x,y: integer) return integer is
	begin
		if x < y then
			return y-x;
		else
			return x-y;
		end if;
	end function RESTA;
	
	function RESIDUO(signal divisor, dividendo: integer) return integer is
	variable res: integer;
	begin
		res:= dividendo;
		if divisor < dividendo then
			for i in 0 to 100 loop
				res:= res - divisor;
				exit when res < divisor;
			end loop;
		
		else
			for i in 0 to 1000 loop
				res:= res - dividendo;
				exit when res < dividendo;
			end loop;		
		end if;
		return res;
	end function RESIDUO;
	
	function COCIENTE (signal divis, divid: integer) return integer is
	variable res, cont: integer;
	begin
		res:= divid;
		cont:= 0;
		for i in 0 to 1000 loop
			res:= res-divis;
			cont:= cont +1;
			exit when res < divis;
		end loop;
		return cont;
	end function COCIENTE;
	
	function MULTIPLICACION ( signal a, b: integer) return integer is
	begin
	return a*b;
	end function MULTIPLICACION;
	
end package body;