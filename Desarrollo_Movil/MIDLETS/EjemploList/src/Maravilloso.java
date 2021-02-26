/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
public class Maravilloso extends MIDlet implements CommandListener {
	public static final int CONECTAR = 0;
	public static final int ESTADO = 1;
	public static final int INSERTAR = 2;
	public static final int DESCONECTAR = 3;
	public static final int MENU = 4;
	private Display     d;
	private List        l;
	private TextBox     tb;
	private Form        f;
	private TextField   ts;
	private TextField   tf;
	private ChoiceGroup cr;
	private Command     cs; 
	private Command     cc; 
	private int         n;
	public Maravilloso(  ) {
		n  = MENU;
		d  = Display.getDisplay(this);
		ts = new TextField("Servidor:", "", 10, TextField.URL);
		tb = new TextBox("Estado", "Sin Conexion", 400, TextField.ANY);
		tf = new TextField("Area ID", "0", 10, TextField.NUMERIC);
		cr= new ChoiceGroup("Riesgo:", ChoiceGroup.EXCLUSIVE);
		cr.append("Bajo", null);
		cr.append("Normal", null);
		cr.append("Alto", null);
		l  = new List ("Seleccionar opci�n:", List.EXCLUSIVE);
		l.append("Conectar", null); 
		l.append("Solicitar Datos", null); 
		l.append("Ingresar Datos", null); 
		l.append("Desconectar", null); 
		f  = new Form ("Menu Conectar");
		cs = new Command("Salir", Command.EXIT, 3);
		cc = new Command("Continuar", Command.OK, 1);
		l.addCommand(cc);
		l.addCommand(cs);
		l.setCommandListener(this);
		f.addCommand(cc);
		f.addCommand(cs);
		f.setCommandListener(this);
		tb.addCommand(cs);
		tb.setCommandListener(this);
	}
	protected void startApp(  ) {
		d.setCurrent(l);
	}
	protected void pauseApp(  ) {    }
	protected void destroyApp(boolean b) {    }
	public void commandAction(Command co, Displayable di) {
		if (n == MENU ) {
			if (co == cs) {
				destroyApp(true);
				notifyDestroyed();
			} else if (co == cc) {
				switch ( l.getSelectedIndex() ){
					case CONECTAR:      conectar(); break;
					case ESTADO:        listar();break;
					case INSERTAR:      insertar();break;
					case DESCONECTAR:   desconectar();break;
				}
			} d.setCurrent(new Alert("", "Otro comando digitado...", null, AlertType.ERROR));
		} else {
			if (co == cs) {
				muestraMenu();
			} else if (co ==cc) {
				switch ( n ){
					case CONECTAR:	listar();break;
					case ESTADO:	muestraMenu();break;
					case INSERTAR:	listar();break;
					case DESCONECTAR: muestraMenu();break;
				}
			} d.setCurrent(new Alert("", "Otro comando digitado...", null, AlertType.ERROR));
		}
	 }
	public void conectar(){
		n = CONECTAR; 
		f.setTitle("Menu Conectar");
		while (f.size()>0) f.delete(0);
		f.append(ts);
		d.setCurrent(f);
	}
	public void insertar(){
		n = INSERTAR;
		f.setTitle("Menu Insertar");
		while (f.size()>0) f.delete(0);
		f.append(tf);
		f.append(cr);
		d.setCurrent(f);
	}
	public void desconectar(){
		d.setCurrent(new Alert("Desconectar","No est� conectado a un servidor.", null, AlertType.ERROR));
		n = DESCONECTAR;
		n = MENU;
	}
	public void listar(){
		n = ESTADO;
		d.setCurrent(tb);
	}
	public void muestraMenu(){
		n = MENU;
		d.setCurrent(l);
	}
}