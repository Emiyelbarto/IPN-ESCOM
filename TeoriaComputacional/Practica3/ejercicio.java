import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.awt.KeyEventDispatcher;
import java.awt.KeyboardFocusManager;
import java.awt.event.KeyEvent;

public class ejercicio 
{
    
    
    public static void main(String[] args) 
	{
        try 
		{
            BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
			
            String texto="";
            char opcion='1';
            
			Agenda mi_agenda= new Agenda();
            
			while ((opcion=='1') || (opcion=='2') || (opcion=='3') || (opcion=='4')|| (opcion=='5') || (opcion=='6') )
            {
                System.out.println("......................");
                System.out.println("AGENDA");
                System.out.println("......................");
                System.out.println("1-Nuevo contacto");
                System.out.println("2-Buscar contacto");
                System.out.println("3-Mostrar contactos");                
                System.out.println("0-Salir");
                System.out.println("......................");
				
                texto=teclado.readLine();
                opcion= texto.charAt(0);
				
                System.out.println("Opcion: ");
                System.out.println("......................");
                
                switch(opcion)
				{
                    case '1':
                        String nombre;
                        String telefono;
						String email;
                        boolean validar;
						
                        System.out.println("introduzca el nombre:");
                        nombre=teclado.readLine();
						
						System.out.println("Introduzca email");
						email=teclado.readLine();
							mi_agenda.verificarEmail(email);
						
                        System.out.println("introduzca el telefono (8 digitos):");
                        telefono=teclado.readLine();
						
                        validar=esNumerica(telefono);
                        if (validar)
						{
                            int telefono_entero= Integer.parseInt(telefono);
                             mi_agenda.Consultar(nombre, telefono_entero);
                             mi_agenda.Anadir(nombre, telefono_entero, email);
							 mi_agenda.verificarTelefono(telefono);
                        }
                        else
						{
                             System.out.println("No es un número, formato de telefono incorrecto.");
							
							 
						}
                        
                       
                        break;
                       
                                
                    case '2':
                        System.out.println("Nombre a buscar:");
                        nombre=teclado.readLine().toUpperCase();
                        mi_agenda.Buscar(nombre);
                        break;
                    case '3':
                        mi_agenda.Mostrar();
                        break;
                    
                    case '0':
                        System.out.println("Ha salido del programa");
                        break;
                     
                    default:
                        System.out.println("Opción incorrecta ...");
                        opcion='1';
                     
                }
                
            }    
            
        } 
					catch (IOException ex) {
            Logger.getLogger(ejercicio.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    public static boolean esNumerica(String str)
	{
		for (char c : str.toCharArray())
		{
			if (!Character.isDigit(c)) 
			return false;
		}
		return true;
	}
	
	
}