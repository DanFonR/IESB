import java.util.Scanner;

class Scans {
  
  public static void main(String[] args) {

    Scanner entrada = new Scanner(System.in);

    System.out.print("Opção de Exercício (1-5): ");
    
    int opcao = entrada.nextInt();

    switch (opcao) {
      
      case 1:
        exercicio1();
        break;
      
      case 2:
        exercicio2();
        break;

      case 3:
        exercicio3();
        break;

      case 4:
        exercicio4();
        break;

      case 5:
        exercicio5();
        break;

      default:
        System.err.println("Opcao Inválida");
    }

    entrada.close();
  }

  static void exercicio1() {

    Scanner entrada = new Scanner(System.in);

    System.out.print("Digite seu nome: ");
    String nome = entrada.nextLine();

    System.out.print("Digite sua idade: ");
    int idade = entrada.nextInt();

    System.out.printf("Olá %s, você tem %d anos\n", nome, idade);
    entrada.close();
  }

  static void exercicio2() {

    Scanner entrada = new Scanner(System.in);

    System.out.print("Digite o 1º número: ");
    int numero1 = entrada.nextInt();

    System.out.print("Digite o 2º número: ");
    int numero2 = entrada.nextInt();

    System.out.print("Escolha a operação (+, -, *, /): ");
    char opcao = entrada.next().charAt(0);

    switch (opcao) {
      
      case '+':
        System.out.println("Soma: " + (numero1 + numero2));
        break;

      case '-':
        System.out.println("Subtração: " + (numero1 - numero2));
        break;

      case '*':
        System.out.println("Multiplicação: " + (numero1 * numero2));
        break;

      case '/':
        System.out.println("Divisão: " + (numero1 / numero2));
        break;

      default:
        System.err.println("Opção inválida");
    }

    entrada.close();
  }

  static void exercicio3() {

    Scanner entrada = new Scanner(System.in);
    int[] arr = new int[5];

    for (int i = 0; i < 5; i++) {
      System.out.printf("Digite o %dº número: ", i + 1);
      arr[i] = entrada.nextInt();
    }

    System.out.print("O array possui os inteiros:\n{");
    
    for (int num : arr)
      System.out.printf("%d, ", num);

    System.out.println("\b\b}");
    entrada.close();
  }

  static void exercicio4() {

    Scanner entrada = new Scanner(System.in);

    System.out.print("Digite uma palavra: ");
    String palavra = entrada.next();

    int tamanho = palavra.length();

    for (int i = 0; i < tamanho; i++)
      if (palavra.charAt(i) != palavra.charAt(tamanho - 1 - i)) {
        System.out.println("A palavra não é um palíndromo");
        System.exit(1);
      }

    System.out.println("A palavra é um palíndromo");
    entrada.close();
  }

  static void exercicio5() {

    Scanner entrada = new Scanner(System.in);

    System.out.print("Insira quantas provas você fez: ");
    int qtdProvas = entrada.nextInt();

    double somaNotas = 0;

    for (int i = 1; i <= qtdProvas; i++) {
      System.out.printf("Digite a nota da %dª prova: ", i);
      somaNotas += entrada.nextDouble();
    }

    System.out.printf("A média das provas é de %.2f\n", somaNotas / qtdProvas);    
    entrada.close();
  }
}
