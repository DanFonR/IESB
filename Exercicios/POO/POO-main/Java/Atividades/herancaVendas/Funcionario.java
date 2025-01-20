package vendas;

public class Funcionario extends Usuario {
	
	public Funcionario(String nome, String senha) {
		super(nome, senha);
	}
	
	public void vendeProduto(String produto) {
		System.out.print("Funcionário " + this.nome + " vendeu o produto ");
		this.exibeProduto(produto);
	}
	
	public void exibeProduto(String produto) {
		System.out.println(produto);
	}
}
