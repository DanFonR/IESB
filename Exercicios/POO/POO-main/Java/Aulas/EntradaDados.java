import java.util.Scanner;
import java.io.*;

class EntradaDados {

  public static void main(String[] args) {

    try {
      System.setOut(new PrintStream(System.out, true, "UTF-8"));
    }
    catch (UnsupportedEncodingException e) {
      System.err.println("Encoding type not supported");
      System.exit(1);
    }


    System.out.print("Digite um número: ");

    try {
      Scanner scanner = new Scanner(System.in);
      int numero = scanner.nextInt();
    
      System.out.println("O número digitado foi " + numero);
      scanner.close();
    }
    catch (Exception e) {
      System.err.println("Você não digitou um número");
      System.exit(1);
    }
  }
}