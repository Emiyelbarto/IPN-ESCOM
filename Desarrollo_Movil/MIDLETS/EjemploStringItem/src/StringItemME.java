/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
/**
 * @author Emiliano
 */
public class StringItemME extends MIDlet implements CommandListener {
private Display	d;
	private Form	f;
	private Alert	a;
	private Command	cs;
	private Command	cc;
	private StringItem si;
	private int	n;
	public StringItemME( ) {
		n  = 0;
		d  = Display.getDisplay(this);
		f  = new Form ("StringItem");
		f.append("Ejemplo de StringItem\n");
		si = new StringItem("Cadena: ", "Contador = " + n);
		f.append(si);
		cs = new Command("Salir", Command.EXIT, 3);
		cc = new Command("Contar", Command.SCREEN, 1);
		f.addCommand(cs);
		f.addCommand(cc);
		f.setCommandListener(this);
	}
	protected void startApp(  ) {
		d.setCurrent(new Alert("", "MIDlet activo...", null, AlertType.ERROR));
		d.setCurrent(f);
	}
	protected void pauseApp(  ) {
		d.setCurrent(new Alert("", "MIDlet pausado...", null, AlertType.ERROR));
	}
	protected void destroyApp(boolean b) {
		d.setCurrent(new Alert("", "MIDlet terminado.", null, AlertType.ERROR));
	}
	public void commandAction(Command co, Displayable di) {
		if (co == cs) {
			destroyApp(true);
			notifyDestroyed();
		} else if (co == cc) {
			n++;
			si.setText("Contador = " + n);
		} else d.setCurrent(new Alert("", "MIDlet activo...", null, AlertType.ERROR));
	}
}