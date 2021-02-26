/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
/**
 *
 * @author Emiliano
 */

public class TunelCiencia extends MIDlet implements CommandListener{

    Canvas canvas;
    Display d;
    Command cs;
    Command cc;
    Command ch;
    Form f;
    TextField tf;
    int iteraciones;
    
    public TunelCiencia()
    {
        canvas = this.new canvas();
        cc = new Command ("Crear", Command.OK, 2);
        cs = new Command ("Salir", Command.EXIT, 4);
        tf = new TextField("Iteraciones:", "", 2, TextField.NUMERIC);
        d = Display.getDisplay(this);
        f = new Form("Tunel Ciencia");
        canvas.addCommand(cs);
        canvas.addCommand(cc);
        f.addCommand(cs);
        f.addCommand(cc);
        f.append(tf);
        f.setCommandListener(this);
    }
    
    public void startApp()
    {
        d.setCurrent(f);
    }
    
    public void pauseApp(){}
    
    public void destroyApp(boolean unconditional){
        notifyDestroyed();
    }

    public void commandAction(Command co, Displayable di){        
        if(co == cs)
        {
            destroyApp(true);
        }
        if(co == cc)
        {
            d.setCurrent(canvas);
            canvas.setCommandListener(this);
            canvas.repaint();
            iteraciones = Integer.parseInt(tf.getString());
            System.out.println("Se metió a pintar con " + iteraciones + " iteraciones");
        }
    }
    
    class canvas extends Canvas
    {
        public void paint(Graphics g)
        {
            int r;
            int a;
            int x;
            int aux;
            r = getWidth() / 2; 
            a = (int) ((int) r * (Math.sqrt(2) / 2));
            x = r - a;
            
            g.setColor(0x000000);
            g.fillRect(0, 0, getWidth(), getWidth());
            g.setColor(0xffffff);
            g.fillArc(0, 0, getWidth(), getWidth(), 0, 360);
            
            do
            {
                g.setColor(0x000000);
                g.fillRect(x, x, a*2, a*2);
                g.setColor(0xffffff);
                g.fillArc(x, x, (a*2), (a*2), 0, 360);
                aux = x;
                r = a;
                a = (int) ((int) r * (Math.sqrt(2) / 2));
                x = r - a + aux;
                System.out.println("Me meti al while" + iteraciones);
                iteraciones--;
            }while(iteraciones != 0);
            

        }
    }
}