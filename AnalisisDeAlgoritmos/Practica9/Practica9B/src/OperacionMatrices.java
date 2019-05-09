
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author José Emiliano Pérez Garduño
 */
public class OperacionMatrices {
    
    public static void main(String[] args) throws FileNotFoundException{
        int[][][] ListaMatrices;
        ListaMatrices = ConseguirMatriz();
        ImprimirMatrices(ListaMatrices);
        Operacion(ListaMatrices);
    }
    
    public static void ImprimirMatrices(int[][][] ListaMatrices){
        for(int i = 0; i < ListaMatrices.length; i++){
            System.out.println("+--------------------+\n|     Matriz("+(i+1)+")      |\n+--------------------+");
            for (int j = 0; j < ListaMatrices[i].length; j++) {
                for (int k = 0; k < ListaMatrices[i][j].length; k++) {
                    System.out.print("["+ListaMatrices[i][j][k]+"]\t");
                }
                System.out.println();
            }        
        }   
        System.out.println("+--------------------+");   
    }
    
    public static int ConseguirNumMatrices(String NomArchivo){
        String linea;
        String M = "M";
        int RepeticionesM = 0;
        int CuentaM = 0;
        try (Scanner scanner = new Scanner(new File(NomArchivo))) {
            while(scanner.hasNextLine()){
                linea = scanner.nextLine();
                RepeticionesM = linea.indexOf(M,RepeticionesM);
                if(RepeticionesM != -1){
                    CuentaM++;
                    RepeticionesM += M.length();
                }             
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(OperacionMatrices.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Numero de Matrices: "+CuentaM);        
        return CuentaM;
    }
    
    public static String[] ConseguirDimension(String NomArchivo, int NumM){
        String linea;
        String D = "D";
        int RepeticionesD = 0;
        int CuentaD = 0;
        String[] Dimension = new String[NumM];
        try (Scanner scanner = new Scanner(new File(NomArchivo))) {
            while(scanner.hasNextLine()){
                linea = scanner.nextLine();
                RepeticionesD = linea.indexOf(D,RepeticionesD);
                if(RepeticionesD != -1){
                    Dimension[CuentaD] = linea;
                    CuentaD++;
                    RepeticionesD += D.length();
                }                
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(OperacionMatrices.class.getName()).log(Level.SEVERE, null, ex);
        }
        return Dimension;
    }
    
    public static int[][][] ConseguirDato(String NomArchivo, int[][][] Matriz){
        Scanner scanner = null;  
        List<String> datos = new ArrayList<String>();
        int x = 0;
        try {
            scanner = new Scanner(new File(NomArchivo));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(OperacionMatrices.class.getName()).log(Level.SEVERE, null, ex);
        }
        while (scanner.hasNextLine()) {  
           String line = scanner.nextLine();
           if(line.contains("D")){               
                while(scanner.hasNextLine()){
                    String aux = scanner.nextLine();
                    if(aux.contains("M")){
                        break;
                    }
                    else{
                        String[] dato = aux.split(":");
                        datos.add(dato[1]);
                    }
                }
           }
        }
        for(int i = 0; i < Matriz.length; i++){
            for(int j = 0; j < Matriz[i].length; j++){
                for(int k = 0; k < Matriz[i][j].length; k++){
                    String datoobtenido = datos.get(x);
                    Matriz[i][j][k] = Integer.parseInt(datoobtenido);
                    x++;
                }                                    
            }
        }
        return Matriz;
    }

    public static int[][][] ConseguirMatriz() throws FileNotFoundException{
        Scanner input = new Scanner(System.in);
        System.out.println("Introducir ruta del archivo matriz");
        String NomArchivo = input.nextLine();
        System.out.println("La ruta del archivo es: "+NomArchivo);
        int CuentaM = ConseguirNumMatrices(NomArchivo);
        String[] Dimension = new String[CuentaM];
        Dimension = ConseguirDimension(NomArchivo,CuentaM);
        String[] aux = new String[CuentaM*2];
        String[] Dimaux = new String[CuentaM*2];
        int[][][] Matriz;
        Matriz = new int[CuentaM][][];
        for(int i = 0; i < CuentaM; i++){
            aux = Dimension[i].split(":");
            Dimaux = aux[1].split("x");
            Matriz[i] = new int[Integer.parseInt(Dimaux[0])][Integer.parseInt(Dimaux[1])];
            System.out.println("Matriz["+(i+1)+"]: de Dimension: "+Integer.parseInt(Dimaux[0])+"x"+Integer.parseInt(Dimaux[1]));
        }        
        Matriz = ConseguirDato(NomArchivo,Matriz);
        return Matriz;
    }
    
    public static int[][][] VerificacionMatriz(int [][][] ListaMatrices){
        int[][][] resultado = new int[ListaMatrices.length][][];
        for(int i = 0; i < ListaMatrices.length - 1; i++){
            System.out.println("Verificando Multiplicacion["+(i+1)+"] x ["+(i+2)+"]");
            System.out.println("MatrizResultado["+i+"] tendra\n'"+ListaMatrices[i].length+"' filas\n'"+ListaMatrices[i+1][0].length+"' columnas");
            resultado[i] = new int[ListaMatrices[0].length][ListaMatrices[i+1][0].length];
            if(ListaMatrices[i][0].length != ListaMatrices[i+1].length){
                System.out.println("Las Matrices ["+i+"] y ["+(i+1)+"] no pueden ser multiplicadas");
                System.exit(0);
            }
        }            
        return resultado;
    }
    
    public static void Operacion(int[][][] ListaMatrices){
        int[][][] resultado;
        resultado = VerificacionMatriz(ListaMatrices);        
        for(int k = 0; k < ListaMatrices.length; k++){
            if(k == 0){
                System.out.println("resultado["+k+"] = array["+resultado[k].length+"]["+ListaMatrices[k+1][0].length+"]");
                int sum = 0;
                for(int i = 0; i < ListaMatrices[0].length; i++){
                    for(int j = 0; j < ListaMatrices[1][0].length; j++){
                        for(int l = 0; l < ListaMatrices[1].length; l++){
                            //System.out.println("ListaMatrices[0]["+i+"]["+l+"]="+ListaMatrices[0][i][l]+" * ListaMatrices[1]["+l+"]["+j+"]= "+ListaMatrices[1][l][j]);
                            sum = sum + ListaMatrices[0][i][l] * ListaMatrices[1][l][j];
                        }
                    resultado[0][i][j] = sum;
                    sum = 0;
                    }
                }
                for(int i = 0; i < ListaMatrices[k].length; i++){
                    for(int j = 0; j < ListaMatrices[k+1][0].length; j++){
                        System.out.print("["+resultado[k][i][j]+"]\t");
                    }
                    System.out.println();
                }
            }
            if(k > 0){
                if((k+1) == ListaMatrices.length)
                    break;
                System.out.println("resultado["+k+"] = array["+resultado[k].length+"]["+ListaMatrices[k+1][0].length+"]");
                int sum = 0;
                for(int i = 0; i < resultado[k-1].length; i++){
                    for(int j = 0; j < ListaMatrices[k+1][0].length; j++){
                        for(int l = 0; l < ListaMatrices[k+1].length; l++){
                            //System.out.println("ListaMatrices[0]["+i+"]["+l+"]="+ListaMatrices[0][i][l]+" * ListaMatrices[1]["+l+"]["+j+"]= "+ListaMatrices[1][l][j]);
                            sum = sum + resultado[k-1][i][l] * ListaMatrices[k+1][l][j];
                        }
                    resultado[k][i][j] = sum;
                    sum = 0;
                    }
                }
                for(int i = 0; i < resultado[k-1].length; i++){
                    for(int j = 0; j < ListaMatrices[k+1][0].length; j++){
                        System.out.print("["+resultado[k][i][j]+"]\t");
                    }
                    System.out.println();
                }
            }
        }        
    }
}