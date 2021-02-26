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
public class GaugeME extends MIDlet implements CommandListener {
	private Display d;
	private Form    f;
	private Gauge   g;
	private Command c; 
	public GaugeME(  ) {
		d = Display.getDisplay(this);
		g = new Gauge("Amplitud", true, 10, 5);
		f = new Form ("Gauge");
		f.append(g); 
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
		} else d.setCurrent(new Alert("", "Otro comando...", null, AlertType.ERROR));
	} 
}