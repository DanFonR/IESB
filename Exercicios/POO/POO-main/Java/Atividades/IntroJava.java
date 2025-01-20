class IntroJava {

  public static void main(String[] args) {

    Aluno aluno1 = new Aluno("João da Silva", "Ciência da Computação", 20);
    Livro livro1 = new Livro("The Java Programming Language",
                            "James Gosling", 2005);
    Retangulo retangulo1 = new Retangulo(3.0, 5.0);
    Triangulo triangulo1 = new Triangulo(3.0, 4.0, 5.0);

    aluno1.apresentar();
    System.out.println("------");

    livro1.exibir();
    System.out.println("------");

    System.out.printf("\"retangulo1\" possui área de %.2f ua\n",
                      retangulo1.calcularArea());

    System.out.println("------");
    System.out.println("Tipo do triangulo1: " + triangulo1.obterTipo());
  }
}

class Aluno {

  private String nome;
  private String curso;
  private int idade;

  Aluno(String nome, String curso, int idade) {

    this.nome = nome;
    this.curso = curso;
    this.idade = idade;
  }

  public void apresentar() {
    System.out.printf("%s, %s, %d anos\n", this.nome, this.curso, this.idade);
  }
}

class Livro {

  private String titulo;
  private String autor;
  private int ano;

  Livro(String titulo, String autor, int ano) {

    this.titulo = titulo;
    this.autor = autor;
    this.ano = ano;
  }

  public void exibir() {
    System.out.printf("%s; %s; %d\n", this.autor, this.titulo, this.ano);
  }
}

class Retangulo {

  private double comprimento;
  private double largura;

  Retangulo(double comprimento, double largura) {

    this.comprimento = comprimento;
    this.largura = largura;
  }

  public double calcularArea() {
    return this.comprimento * this.largura;
  }
}

class Triangulo {

  private double ladoA;
  private double ladoB;
  private double ladoC;

  Triangulo(double A, double B, double C) {

    this.ladoA = A;
    this.ladoB = B;
    this.ladoC = C;
  }

  public boolean formaTriangulo() {

    return (this.ladoA + this.ladoB > this.ladoC)
        && (this.ladoA + this.ladoC > this.ladoB)
        && (this.ladoB + this.ladoC > this.ladoA);
  }

  public String obterTipo() {

    if (this.formaTriangulo() == false)
      return null;

    if (this.ladoA == this.ladoB && this.ladoB == this.ladoC)
      return "Equilátero";

    else if (this.ladoA == this.ladoB
          || this.ladoA == this.ladoC
          || this.ladoB == this.ladoC)
      return "Isósceles";

    else return "Escaleno";
  }
}
