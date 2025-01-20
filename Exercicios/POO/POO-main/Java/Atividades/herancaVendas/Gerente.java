package vendas;

public class Gerente extends Funcionario {
	
	public Gerente(String nome, String senha) {
		super(nome, senha);
	}
	
	public void fechaCaixa() {
		System.out.println("Gerente fechou o caixa");
	}
}
