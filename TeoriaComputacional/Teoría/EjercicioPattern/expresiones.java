import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class expresiones
{
	public static void main(String[] args) 
	{
		Scanner s = new Scanner(System.in);

		String cadena;

		System.out.print("Ingresar cadena:");
		cadena = s.nextLine();

		Pattern p = Pattern.compile("^[\\w-]+(\\.[\\w-]+)*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");
		Matcher m = p.matcher(cadena);

		if(m.matches())
		{
			System.out.print("La cadena si es valida como correo.");
			System.out.print("\n"+cadena);
		}
		else
		{
			System.out.print("La cadena no es valida como correo");
			System.out.print("\n"+cadena);
		}
	}
}