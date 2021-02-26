//Canvas con una clase externa
import javax.microedition.midlet.*;
import javax.microedition.ledui.*;

public class Pinta extends MIDlet implements CommandListener{
    Command c;
    Display d;
    Lienzo l;

    public Pinta(){
        c = new Command("Salir",Command.EXIT,2);
        d = Display.getDisplay(this);
        l = new Lienzo();
        l.addCommand(c);
        l.setCommandListener(this);
    }

    public void startApp(){
        d.setCurrent(l);
    }

    public void pauseApp(){}
    public void destroyApp(boolean b){}
    public void commandAction(Command co, Displayable di){
        if(co == c){
            destroyApp(false);
            notifyDestroyed();
        }
    }
}