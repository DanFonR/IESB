package vendas;

public class Usuario {
	
	protected String nome;
	private String senha;
	
	public Usuario(String nome, String senha) {
		this.nome = nome;
		this.senha = senha;
	}

	@Override
	public String toString() {
		return this.nome;
	}
}
