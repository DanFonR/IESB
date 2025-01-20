package vendas;

public class Cliente extends Usuario {
	
	private String endereco;
	private String telefone;
	
	public Cliente(String nome, String senha,
			String endereco, String telefone) {
		super(nome, senha);
		
		this.endereco = endereco;
		this.telefone = telefone;
	}
	
	public void compraProduto(String produto) {
		System.out.println("Cliente " + this.nome + " comprou " + produto);
	}
	
	@Override
	public String toString() {
		return super.toString() + "; Endereco: " + this.endereco
						+ "; Telefone: " + this.telefone;
	}
}
