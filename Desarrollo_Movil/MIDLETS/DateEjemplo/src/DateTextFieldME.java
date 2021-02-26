/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Date;
import java.util.Calendar;
import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
/**
 * @author Emiliano
 */
public class DateTextFieldME extends MIDlet implements CommandListener {
	private Display	d;
	private Form	f;
	private TextField tf;
	private DateField df; 
	private StringItem si; 
	private Command	cc; 
	private Command	cs;
	public DateTextFieldME (  ) {
		d  = Display.getDisplay(this);
		tf = new TextField("Nombre:","", 10, TextField.ANY);
		df = new DateField("Cumpleaños:", DateField.DATE);
		si = new StringItem("", "");
		f  = new Form ("TextField y DateField");
		f.append(tf); 
		f.append(df);
		f.append(si);
		cc = new Command("Continuar", Command.OK, 0);
		cs = new Command("Salir", Command.EXIT, 3);
		f.addCommand(cc);
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
		} else if (co == cc) {
			Calendar c1 = Calendar.getInstance();
			Calendar c2 = Calendar.getInstance();
			Date date = df.getDate();
			if ((date == null) || (tf.getString().equals(""))) {
				si.setText("Favor de ingresar su nombre…");
				return;
			}
			c2.setTime(date);
			int edad = c1.get(Calendar.YEAR)-c2.get(Calendar.YEAR);
			f.delete(0);
			f.delete(0);
			f.removeCommand(cc);
			si.setText("Hola " + tf.getString() + "\nTu edad es = " + edad + " años");
		} else d.setCurrent(new Alert("", "Otro comando...", null, AlertType.ERROR));
	} 
}
