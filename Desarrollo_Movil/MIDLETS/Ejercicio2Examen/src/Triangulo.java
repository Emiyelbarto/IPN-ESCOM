/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Random;
import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

/**
 * @author Emiliano
 */
public class Triangulo extends MIDlet implements CommandListener {
    
    public int i;
    public int contador;
    public Graphics g;
    public Canvas canvas;
    public static final int MENU = 1;
    private int m = MENU;
    private TextField tfColores;
    private TextField tfIteraciones;
    private Form f;
    private Display d;
    private Command cs;
    private Command cc;
    public String color;
    public String aux;
    Random rand = new Random();
    
    public Triangulo()
    {
        canvas = this.new canvas();
        d = Display.getDisplay(this);
        f = new Form("Ejercicio 2");
        cs = new Command("Salir",Command.EXIT,2);
        cc = new Command("Crear",Command.OK,1);
        tfColores = new TextField("Introducir el color en hexadecimal: ","",6,TextField.ANY);
        tfIteraciones = new TextField("Introducir el numero de iteraciones: ","",5,TextField.NUMERIC);
        f.append(tfColores);
        f.append(tfIteraciones);
        f.addCommand(cs);
        f.addCommand(cc);
        canvas.addCommand(cs);
        canvas.addCommand(cc);
        f.setCommandListener(this);
    }

    public void startApp() {
        d.setCurrent(f);
    }
    
    public void pauseApp() {
    }
    
    public void destroyApp(boolean unconditional) {
        notifyDestroyed();
    }

    public void commandAction(Command co, Displayable di) {
        if(co == cs)
        {
            destroyApp(true);
            notifyDestroyed();
        }
        else if(co == cc)
        {
            d.setCurrent(canvas);
            for(i = 0; i < 10; i++)
                canvas.repaint();
            canvas.setCommandListener(this);
            m = 2;
            aux = tfIteraciones.getString();
            color = tfColores.getString();
        }
        
    }
        
    public void Inicio()
    {
        m = MENU;
        d.setCurrent(canvas);
    }
    
    public int PuntoMedioX(int v1x, int px)
    {
        int i = 0;
        i = (px + v1x)/ 2;
        return i;
    }
    
    public int PuntoMedioY(int v1y, int py)
    {
        int i = 0;
        i = (py + v1y) / 2;
        return i;
    }
    
    class canvas extends Canvas
    {
        public int v1x = 55;
        public int v2x = 100;
        public int v3x = 10;
        public int v1y = 10;
        public int v2y = 90;
        public int v3y = 90;
        public int px = rand.nextInt(getWidth());
        public int py = rand.nextInt(getHeight());
        public int pmy = PuntoMedioY(v1y,py);
        public int pmx = PuntoMedioX(v1x,px);
        
        public void paint(Graphics g)
        {           
            System.out.println("Estoy pintando el canvas");
            g.setColor(0xffffff);
            g.drawRect(v1x, v1y, 1, 1);
            g.setColor(0xffff00);
            g.drawRect(v2x, v2y, 1, 1);
            g.setColor(0x00ff00);
            g.drawRect(v3x, v3y, 1, 1);
            g.setColor(0xffffff);
            g.drawRect(px,py,1,1);
            g.drawRect(pmx,pmy,1,1);
        }
    }
}
