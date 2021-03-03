import javax.swing.JOptionPane;

public class Ventanas {
        //Muestra un mensaje
	public static void mensaje(String m){
		JOptionPane.showMessageDialog(null,m);
	}
        //Muesta una ventana con opciones
        //o: opciones de la ventana. m: Mensaje a mostrar. v: Mensaje de la ventana. valida: revisa que no sea nulo
        public static String seleccionS(Object[]o,String m, String v,boolean valida){
                Object r = JOptionPane.showInputDialog(null, m, v,  
                JOptionPane.PLAIN_MESSAGE, null, o, null);
                String regresa;
                if(r==null){
                    regresa="";
                    valida=true;
                }                  
                else{
                    regresa=r.toString();
                    valida=false;
                }
                return regresa;
        }
        public static int seleccionI(Object[]o,String m, String v,boolean valida){
                Integer r = (Integer) JOptionPane.showInputDialog(null,m, v,  
                JOptionPane.PLAIN_MESSAGE, null, o, null);
                int regresa;
                if(r==null){
                    regresa=0;
                    valida=true;
                }          
                else{
                    regresa=Integer.parseInt(r.toString());
                    valida=false;
                }                   
                return regresa;
        }
        public static double seleccionD(Object[]o,String m, String v,boolean valida){
                Integer r = (Integer) JOptionPane.showInputDialog(null, m, v,  
                JOptionPane.PLAIN_MESSAGE, null, o, null);
                double regresa;
                if(r==null){
                    regresa=0.0;
                    valida=true;
                }          
                else{
                    regresa=Double.parseDouble(r.toString());
                    valida=false;
                }                  
                return regresa;
        }
        public static Object seleccionO(Object[]o,String m, String v){
                Object r= JOptionPane.showInputDialog(null, m, v,  
                JOptionPane.PLAIN_MESSAGE, null, o, null);
                return r;
        }
	//Acepta un mensaje para mostrar y regresa la cadena de entrada
	public static String entradaS(String m){
		String regresa = JOptionPane.showInputDialog(m);
		return regresa;
	}
	//Acepta un mensaje para mostrar y regresa la cadena de entrada convertida en entero
	public static int entradaI(String m){
		boolean valida = true;
		String regresa;
		Integer r;
		do{
			regresa = JOptionPane.showInputDialog(m);
			r = Integer.parseInt(regresa);
			if(regresa == null)
				continue;
			if( regresa.equals("NaN"))
				mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
			else{
				if(r<0)
					mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
				else
					valida = false;
			}
		}
		while(valida==true);

		return r;
	}
	//Acepta un mensaje para mostrar y regresa la cadena de entrada convertida en double
	public static double entradaD(String m){
		boolean valida = true;
		String regresa;
		Double r;
		do{
			regresa = JOptionPane.showInputDialog(m);
			r = Double.parseDouble(regresa);
			if(regresa == null)
				continue;
			if( regresa.equals("NaN"))
				mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
			else{
				if(r<0)
					mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
				else
					valida = false;
			}
		}
		while(valida==true);

		return r;
	}
	//Acepta un mensaje para mostrar y regresa la cadena de entrada convertida en flotante
	public static float entradaF(String m){
		boolean valida = true;
		String regresa;
		Float r;
		do{
			regresa = JOptionPane.showInputDialog(m);
			r = Float.parseFloat(regresa);
			if(regresa == null)
				continue;
			if( regresa.equals("NaN"))
				mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
			else{
				if(r<0)
					mensaje("No ingreso un numero entero positivo en el campo, pruebe de nuevo.");
				else
					valida = false;
			}
		}
		while(valida==true);

		return r;
	}

	//Dialogo que muestra la Ventanastana de confirmación ya sea con un si o un no, regresará un true o false.
	public static boolean confirma(String m){
		int res = JOptionPane.showConfirmDialog(null, m);
		boolean r = false;

		if(res == JOptionPane.YES_OPTION)
			r=true;
		else if(res == JOptionPane.NO_OPTION)
			r=false;
		return r;
	}   
}