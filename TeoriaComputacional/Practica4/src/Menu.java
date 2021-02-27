
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Emiliano
 */
public class Menu {
    
    boolean exit;
    
    public static void main(String[] args){
        Menu menu = new Menu();
        menu.correrMenu();
    }
    
    public void correrMenu(){
        printHeader();
        while(!exit){
            printMenu();
            int choice = getInput();
            realizarAccion(choice);
        }
    }
    
    private void realizarAccion(int choice){
        switch(choice){
            case 0:
                System.out.println("Adios");
                exit = true;
                break;
            case 1:
                System.out.println("Automata 1");
                PrimerAutomata();
                break;
            case 2:
                System.out.println("Automata 2");
                break;
            case 3:
                System.out.println("Automata 3");
                break;
            case 4:
                System.out.println("Automata 4");
                break;
            default:
                System.out.println("Ha ocurrido un error");
                break;
        }
    }
    
    private void PrimerAutomata(){
        
    }
    
    private void printHeader(){
        System.out.println("+------------------------------+");
        System.out.println("|------------MENU--------------+");
        System.out.println("+------------------------------+");
        System.out.println("+------------------------------+");
    }
    
    private void printMenu(){
        System.out.println("\nPor favor hacer una selección");
        System.out.println("1) automata 1");
        System.out.println("2) automata 2");
        System.out.println("3) automata 3");
        System.out.println("4) automata 4");
        System.out.println("0) Salir");
    }
    
    private int getInput(){
        Scanner in = new Scanner(System.in);
        int choice = -1;
        while(choice < 0 || choice > 4){
            try{
                System.out.print("\nEscribe tu elección:\n");
                choice = Integer.parseInt(in.nextLine());
            }
            catch(NumberFormatException e){
                System.out.println("Selección Invalida, intentar de nuevo.");
            }
        }
        return choice;
    }
    
    
}
