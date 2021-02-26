/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 * @author Emiliano
 */
import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
public class AltoNivelME extends MIDlet implements CommandListener {
	private Display	d;
	private Form	f;
	private Command	c;
	private Alert	a;
	public AltoNivelME(  ) {
		d = Display.getDisplay(this);
		f = new Form ("Hola MIDlet");
		f.append("Hola MIDlet!\n");
		c = new Command("Salir", Command.EXIT, 3);
		f.addCommand(c);
		f.setCommandListener(this);
	}
 	protected void startApp(  ) {
		d.setCurrent(f);
	}
	protected void pauseApp(  ) {    }
 	protected void destroyApp(boolean b) {    }
	public void commandAction(Command co, Displayable di) {
		if (co == c) {
			destroyApp(true);
			notifyDestroyed();
		} else d.setCurrent(new Alert("", "Otro comando...", null, AlertType.ERROR));	} 
}