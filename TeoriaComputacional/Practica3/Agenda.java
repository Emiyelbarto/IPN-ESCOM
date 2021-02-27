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

public class Agenda 
{

    Contacto[] lista_contactos = new Contacto[25];
	
    private int contador_contactos = 0; // Contador de objetos creados.
	
	public boolean c;

    public void Consultar(String nombre, int telefono) 
	{
        for (int i = 0; i < this.contador_contactos; i++) 
		{

            if (nombre.equals(this.lista_contactos[i].getNombre())) 
			
			{
                System.out.println("Ya existe un contacto con ese nombre");
            }
        }

    }

    public void Anadir(String nombre, int telefono, String email) 
	{
        if (contador_contactos < 25)
			{
				this.lista_contactos[contador_contactos] = new Contacto();
			
				this.lista_contactos[contador_contactos].set_nombre(nombre);
				this.lista_contactos[contador_contactos].set_email(email);
				this.lista_contactos[contador_contactos].set_telefono(telefono);
				
				this.contador_contactos++;
           
			} 
		else 
		{
            System.out.println("La agenda está llena");
        }

    }

    public void Buscar(String nombre) 
	{
        boolean encontrado = false;




        for (int i = 0; i < contador_contactos; i++) 
		{
            if (nombre.equals(this.lista_contactos[i].getNombre())) 
			{
                System.out.println(this.lista_contactos[i].getNombre() + "-" + "Tf:" + this.lista_contactos[i].getTelefono());
                encontrado = true;
            }
        }
        if (!encontrado) 
		{
            System.out.println("Contacto inexistente");
        }
    }
	
	public boolean verificarEmail(String email)
	{
		Pattern pat = Pattern.compile("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@" +"[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$");
		Matcher mat = pat.matcher(email);
		
		if (mat.matches())
		{
			System.out.print(" - Email aceptado\n");
			//System.out.print("\n"+email+"\n");
			c=true;
			
		}
		else
		{
			System.out.print(" - Email invalido"+"\n");
			c=false;
			
			
		}
		
		//System.out.print(c);
		return c;
	}
	
	public boolean verificarTelefono(String telefono)
	{
		Pattern pat = Pattern.compile("[0-9]+[0-9]+[0-9]+[0-9]+[0-9]+[0-9]+[0-9]+[0-9]");
		Matcher mat = pat.matcher(telefono);
		
		if (mat.matches())
		{
			System.out.print(" - telefono aceptado\n");
			//System.out.print("\n"+email+"\n");
			c=true;
			
		}
		else
		{
			System.out.print(" - telefono invalido"+"\n");
			c=false;
			
			
		}
		
		//System.out.print(c);
		return c;
	}
   

    public void Mostrar( ) 
	{
        if (this.contador_contactos == 0) 
		{
            System.out.println("No hay contactos");
        } 
		else 
		{
            for (int t = 0; t < this.contador_contactos; t++) 
			{
                
				
				System.out.println("Nombre "+this.lista_contactos[t].getNombre());
				System.out.println("Telefono "+Integer.toString(this.lista_contactos[t].getTelefono()));
				System.out.println("Email: "+this.lista_contactos[t].getEmail());
				System.out.println(" ");
            }
        }
    }

    public class IsKeyPressed {
	    boolean wPressed = false;
	    boolean isWPressed() {
	        synchronized (IsKeyPressed.class) {
	            return wPressed;
	        }
	    }
	}

}
	
	

