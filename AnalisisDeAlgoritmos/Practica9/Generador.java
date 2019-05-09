/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedWriter;
import java.util.Scanner;
import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;
/**
 *
 * @author José Emiliano Pérez Garduño
 */
public class Matriz {
    public static void main(String[] args){
        int n = RecibirNumMatrices();
        int[][] Matrices = CrearMatrices(n);
        ImprimirMatrices(Matrices);
    }
    
    public static int RecibirNumMatrices(){
        System.out.println("Escribir el numero de matrices:");
        int NumMatrices;
        try (Scanner scan = new Scanner(System.in)) {
            NumMatrices = scan.nextInt();
            while(NumMatrices < 2 || NumMatrices > 9){
                System.out.println("Introducir un numero mayor a 1 y menor a 10");
                if(scan.hasNextLine())
                    NumMatrices = scan.nextInt();
                else
                    NumMatrices = 0;
            }
        }
        System.out.println("Habra "+NumMatrices+" matrices.");
        return NumMatrices;
    }
    
    public static int[][] CrearMatrices(int NumMatrices){
        Random rand = new Random();
        int[][] data = new int [NumMatrices][2];
        for(int i = 0; i < NumMatrices; i++){
            for(int j = 0; j < 2; j++){
                if(i >= 1){
                    data[i][0] = data[i-1][1];
                    data[i][1] = rand.nextInt(8) + 1;
                }
                else
                    data[i][j] = rand.nextInt(8) + 1;
            }
        }
        return data;
    }
    
    public static void ImprimirMatrices(int[][] data){
        String NomArchivo = "Matriz.txt";
        int NumMatrices = data.length;
        Random rand = new Random();
        int aux;
        try{
            BufferedWriter bw = new BufferedWriter(new FileWriter(NomArchivo));
            for(int i = 0; i < NumMatrices; i++){
                System.out.println("M"+(i+1)+"\nD:"+data[i][0]+"*"+data[i][1]);
                bw.write("M"+(i+1));
                bw.newLine();
                bw.write("D:"+data[i][0]+"x"+data[i][1]);
                bw.newLine();
                for(int j = 0; j < data[i][0]; j++){
                    for(int k = 0; k < data[i][1]; k++){
                        aux = rand.nextInt(9);
                        System.out.println((j+1)+","+(k+1)+":"+aux);
                        bw.write((j+1)+","+(k+1)+":"+aux);
                        bw.newLine();
                    }
                }
            }
            bw.flush();
        }catch (IOException e) {}
    }
}