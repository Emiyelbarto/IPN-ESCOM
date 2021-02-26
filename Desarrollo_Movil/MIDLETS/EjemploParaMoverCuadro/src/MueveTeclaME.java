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
public class MueveTeclaME extends MIDlet implements CommandListener {
	private Display d;
	private Command cs; 
	private Canvas ca; 
	public MueveTeclaME(  ) {
		d = Display.getDisplay(this);
		ca = new Canvas() {
			private int x=0, y=0;
			public void paint (Graphics g){
				g.setColor(255, 255, 255);
				g.fillRect(0, 0, getWidth(), getHeight());
				g.setColor(255, 0, 0);
				g.setStrokeStyle(Graphics.SOLID);
                                g.fillArc(x, y, 50, 50, 0, 360);
                                g.drawString("x="+x+", y="+y, getWidth()/2, getHeight()/2, 0);
			}
			protected void keyPressed(int k) {
				int up = getKeyCode(UP);
				int dn = getKeyCode(DOWN);
				int lf = getKeyCode(LEFT);
				int rt = getKeyCode(RIGHT);
				if (k == up)      { if(y>0) y-=1; repaint(); }
				else if (k == dn) { if(y<getWidth()) y+=1; repaint(); }
				else if (k == lf) { if(x>0) x-=1; repaint(); }
				else if (k == rt) { if(x<getHeight()) x+=1; repaint(); }
			}
		};
		cs = new Command("Salir",Command.EXIT, 3);
		ca.addCommand(cs);
		ca.setCommandListener(this);
	}
	protected void startApp(  ) {
		d.setCurrent(ca);
	}
	protected void pauseApp(  ) {    }
	protected void destroyApp(boolean b) {    }
	public void commandAction(Command co, Displayable di) {
		if (co == cs) {
			destroyApp(true);
			notifyDestroyed();
		} else d.setCurrent(new Alert("", "Otro comando digitado...", null, AlertType.ERROR));
	} 
}
