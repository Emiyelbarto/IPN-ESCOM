/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import javax.microedition.lcdui.*;
import javax.microedition.midlet.*;
import javax.microedition.lcdui.game.GameCanvas;
/**
 * @author Emiliano
 */
public class Rebota extends MIDlet {
	Display d;
	Pantalla p;
	public Rebota() {
		d = Display.getDisplay(this);
		p = new Pantalla();
	}
	protected void destroyApp(boolean b) throws MIDletStateChangeException{ }
	protected void pauseApp() { }
	protected void startApp() throws MIDletStateChangeException {
		d.setCurrent(p);
	}
}
class Pantalla extends GameCanvas implements Runnable{
	int x = 0, y = 0;
	int velx = 6, vely = 4;
	public Pantalla(){
		super(true);
		Thread t=new Thread(this);
		t.start();
	}
	public void paint(Graphics g) {
		g.setColor(255, 255, 210);
		g.fillRect(0, 0, getWidth(), getHeight());
		g.setColor(0, 255, 2);
		g.fillArc(x, y, 30, 30, 0, 360);
	}
	public void run() {
		while(true){
			x = x + velx;
			y = y + vely;
			repaint();
			if( x+30 > getWidth()  || x < 0 ) velx = -velx;
			if( y+30 > getHeight() || y < 0 ) vely = -vely;
			try {
				Thread.sleep(50);
				flushGraphics();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
