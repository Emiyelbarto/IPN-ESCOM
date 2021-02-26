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

public class Maravilloso extends MIDlet implements CommandListener{
    Command cs, CNumM, CPrimo, CFibonacci, CPalindromo;
    Display d;
    Form f;
    StringItem si;
    TextField tf;

    public Maravilloso(){
        cs = new Command ("Salir", Command.EXIT, 1);
        CNumM = new Command ("Maravilloso", Command.OK, 2);
        CPrimo = new Command ("Primo", Command.OK, 3);
        CFibonacci = new Command ("Fibonacci", Command.OK, 4);
        CPalindromo = new Command ("Palindromo", Command.OK, 5);
        d = Display.getDisplay(this);
        f = new Form("Ejercicio 1");
        si = new StringItem("","Escribir un numero natural O una cadena.");
        tf = new TextField("","",256,TextField.ANY);
        f.addCommand(cs);
        f.addCommand(CNumM);
        f.addCommand(CPrimo);
        f.addCommand(CFibonacci);
        f.addCommand(CPalindromo);
        f.append(si);
        f.append(tf);
        f.setCommandListener(this);
    }
    
    public void startApp(){
        d.setCurrent(f);
    }
    
    public void pauseApp() {}
    public void destroyApp(boolean bo) {}
    public void commandAction (Command co, Displayable di){
        if(co == CNumM)
        {
            String n = tf.getString();
            int res = Integer.parseInt(n);
            si = new StringItem("Numero Maravilloso: ",n);
            f.append(si);
            int cuenta;
            cuenta = VerificacionFantastico(res);
            si = new StringItem("Le tomo n iteraciones = ",n);
            f.append(si);
        }
        else if(co == CPrimo)
        {
            String n = tf.getString();
            int res = Integer.parseInt(n);
            si = new StringItem("Numero Primo a analizar: ",n);
            f.append(si);
            boolean flag = VerificacionPrimo(res);
            if(flag)
            {
                si = new StringItem("El numero SI es PRIMO","");
                f.append(si);                
            }
            else
            {                
                si = new StringItem("El numero NO es PRIMO","");
                f.append(si);
            }
        }
        else if(co == CFibonacci)
        {
            String n = tf.getString();
            int res = Integer.parseInt(n);
            si = new StringItem("Numero Fibonacci a analizar: ",n);
            f.append(si);
            boolean flag = VerificacionFibonacci(res);
            if(flag)
            {
                si = new StringItem("El numero SI es fibonacci","");
                f.append(si);                
            }
            else
            {
                si = new StringItem("El numero NO es fibonacci","");
                f.append(si);                     
            }
        }
        else if(co == CPalindromo)
        {
            si = new StringItem("Palindromos","");
            f.append(si);
            char[] palindromo = tf.getString().toCharArray();
            si = new StringItem("Cadena a analizar: ",tf.getString());
            f.append(si);
            boolean flag = VerificacionPalindromo(palindromo);
            if(flag == true)
            {
                si = new StringItem("La palabra SI es un palindromo","");
                f.append(si);
            }
            else
            {
                si = new StringItem("La palabra NO es un palindromo","");     
                f.append(si);           
            }
        }
    }
    
    public int VerificacionFantastico(int numero)
    {
        while(numero != 1)
        {
            if(numero % 2 == 0)
            {
                numero = numero / 2;
                si = new StringItem("Numero Par = numero / 2 = ",Integer.toString(numero));
                f.append(si);
                numero = VerificacionFantastico(numero);   
            }
            else
            {                        
                numero = (numero * 3) + 1;
                si = new StringItem("Numero Imar = (numero * 3) + 1 = ",Integer.toString(numero));
                f.append(si);
                numero = VerificacionFantastico(numero);
            }
        }     
        return numero;
    }
    
    public boolean VerificacionPrimo(int numero)
    {
        if(numero <= 3)
            return true;
        else if(numero % 2 == 0 || numero % 3 == 0)
            return false;
        int i = 5;
        while(i * i <= numero)
        {
            if(numero % i == 0 || numero % (i+2) == 0)
                return false;
            i = i + 6;
        }
        return true;
    }
    
    public boolean VerificacionFibonacci(int numero)
    {
        if(numero == 0 || numero == 3 || numero == 5 || numero == 8)
            return true;
        double raiz, power;
        power = numero * numero;
        System.out.println("power:" + power);
        raiz = (5 * power) - 4;
        System.out.println("raiz antes de sacar raiz:" + raiz);
        raiz = Math.sqrt(raiz);
        System.out.println("raiz = " + raiz);
        if(raiz - Math.floor(raiz) == 0)
            return true;
        return false;
    }
    
    public boolean VerificacionPalindromo(char[] palindromo)
    {
        boolean flag = false;
        int longitud = palindromo.length;
        if(longitud % 2 == 0)
        {
            //longitud par
            for(int i = 0; i < (palindromo.length/2) - 1; i++)
            {
                if(palindromo[i] != palindromo[palindromo.length -i - 1])
                    return false;
                else
                    flag = true;
            }
        }
        else
        {
            //longitud impar
            for(int i = 0; i < (palindromo.length-1 /2) - 1; i++)
            {
                if(palindromo[i] != palindromo[palindromo.length -i -1])
                    return false;
                else
                    flag = true;
            }
        }
        return flag;
    }
}
