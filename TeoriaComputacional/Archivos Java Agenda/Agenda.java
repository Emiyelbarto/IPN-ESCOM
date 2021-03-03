import java.util.ArrayList;

public class Agenda {

 public static void main(String[]clientes) {
		ArrayList<Contacto> contactos = new ArrayList<Contacto>();
                contactos.add(new Contacto("Eje 3","Pancho Villa","pachito@revo.com",55101110));
                contactos.add(new Contacto("Av. Lazaro Cardenas #102","Tata Cardenas","lazarus@card.com",65201540));
                contactos.add(new Contacto("Av. Insurgentes #10","Agustin Iturbide","agus@bisnes.com",59284530));
                contactos.add(new Contacto("Av. Zaragoza 82","Xabi Irueta","abi@mail.com",67254531));
                contactos.add(new Contacto("Av. Cuauhtemoc #1001","El cuauh","aguilas@rara.com",71284561));
                contactos.add(new Contacto("Av. Circunvalancion #301","Circus Zincio","circo@mail.com",43287581));
                contactos.add(new Contacto("Av. Politecnico #30","El poli","poli@mail.com",33292584));
                contactos.add(new Contacto("Av. Juan de dios Batiz #100","Juan Batiz","batiz@nono.com",84291596));
                contactos.add(new Contacto("El ciclo sin fin #30","Sim ba","ra@fiki.com",93281583));
                contactos.add(new Contacto("Stairway to Heaven 4","Led Zeppelin","babeimgonna@leaveyou.com",73281483));
		String direc,menu,selec2;
		int selec,s,i;

		boolean valida1=false,valida2=false;
                
                do{
                    Ventanas.mensaje("Que desea hacer?");
                    menu="------------------------------------------------------------------------------\n"
                        +"| 1) Buscar por nombre          | 2) Buscar por telefono         |"
                        +"\n----------------------------------------------------------------------------\n"
                        +"| 3) Mostrar todos                    | 4) Salir                                |"
                        +"\n-----------------------------------------------------------------------------\n";
			selec = Ventanas.entradaI(menu);

				switch(selec){
					case 1:
                                            selec2=Ventanas.entradaS("Ingrese el nombre");
                                            for(i=0;i<contactos.size() && valida1==false;i++){
                                                if(selec2.matches(contactos.get(i).getNombre()))
                                                    valida1=true;
                                            }
                                            i--;
                                            if(valida1==false)
                                                Ventanas.mensaje("No se encontro ningun contacto con el nombre ingresado");
                                            else{
                                                selec2="Nombre: "+contactos.get(i).getNombre()+
                                                        "\nDireccion: "+contactos.get(i).getDirec()+
                                                        "\nTelefono: "+contactos.get(i).getTelefono()+
                                                        "\nEmail: "+contactos.get(i).getEmail();
                                                Ventanas.mensaje(selec2);
                                            }
                                            valida1=false;
					break;
					case 2:
                                            s=Ventanas.entradaI("Ingrese el telefono");
                                            for(i=0;i<contactos.size() && valida1==false;i++){
                                                if(s == contactos.get(i).getTelefono())
                                                    valida1=true;
                                            }
                                            i--;
                                            if(valida1==false)
                                                Ventanas.mensaje("No se encontro ningun contacto con el telefono ingresado");
                                            else{
                                                selec2="Nombre: "+contactos.get(i).getNombre()+
                                                        "\nDireccion: "+contactos.get(i).getDirec()+
                                                        "\nTelefono: "+contactos.get(i).getTelefono()+
                                                        "\nEmail: "+contactos.get(i).getEmail();
                                                Ventanas.mensaje(selec2);
                                            }
                                            valida1=false;
						break;
					case 3:
                                            for(i=0;i<contactos.size();i++){                                                
                                                selec2=" "+(i+1)+")"+
                                                        "\nNombre: "+contactos.get(i).getNombre()+
                                                        "\nDireccion: "+contactos.get(i).getDirec()+
                                                        "\nTelefono: "+contactos.get(i).getTelefono()+
                                                        "\nEmail: "+contactos.get(i).getEmail();
                                                Ventanas.mensaje(selec2);
                                            }   
						break;
					case 4:
                                                valida2=true;
						break;

					default:
						Ventanas.mensaje("Ingreso un dato mal");
						break;
				}
			
		}
		while(valida2==false);
           }

}