public class Hoffman{

  public static void main(String[] args) {
    System.out.print("Hola");
  }

  private static int TAM_ALFABETO = 256;

  public ResultadoComprimidoHuffman compress(final String data){

    return null;
  }

  private static int[] ConstruirTablaFrecuencias(final String data){

        final int[] freq = new int[TAM_ALFABETO];
        for(final char character : data.toCharArray()){
          freq[character]++;
        }

        return freq;
  }

  public String decompress(final ResultadoComprimidoHuffman result){
    return null;
  }

  static class ResultadoComprimidoHuffman{

  }

}
