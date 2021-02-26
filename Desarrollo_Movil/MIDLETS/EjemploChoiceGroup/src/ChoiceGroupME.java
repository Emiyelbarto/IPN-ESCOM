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
public class ChoiceGroupME extends MIDlet implements CommandListener {
        public static final int MENU = 1;
        private int m = MENU;
	private Display		d;
	private Form		f;
	private TextField	tf;
	private ChoiceGroup	cg; 
	private ChoiceGroup	ch; 
	private Command		cs; 
	public ChoiceGroupME(  ) {
		d  = Display.getDisplay(this);
		tf = new TextField("Nombre:", "", 10, TextField.ANY);
		cg = new ChoiceGroup("Sexo:", ChoiceGroup.EXCLUSIVE);
		cg.append("Masculino", null);
		cg.append("Femenino", null);
		ch = new ChoiceGroup("Lenguajes:", ChoiceGroup.MULTIPLE);
		ch.append("Java", null);
		ch.append("C++", null);
		ch.append("Prolog", null);
		ch.append("Otros", null);
		f  = new Form ("ChoiceGroup");
		f.append(tf); 
		f.append(cg);
		f.append(ch);
		cs = new Command("Salir", Command.EXIT, 3);
		f.addCommand(cs);
		f.setCommandListener(this);
	}
	protected void startApp(  ) {
		d.setCurrent(f);
	}
	protected void pauseApp(  ) {    }
	protected void destroyApp(boolean b) {    }
	public void commandAction(Command co, Displayable di) {
		if (co == cs) {
			destroyApp(true);
			notifyDestroyed();
		} else d.setCurrent(new Alert("", "Otro comando...", null, AlertType.ERROR));
	} 
}