package academia;

public class Usuario {
	
	private String nome;
	private String senha;
	private int userID;
	
	public Usuario(String nome, String senha, int ID) {
		this.nome = nome;
		this.senha = senha;
		this.userID = ID;
	}
	
	@Override
	public String toString() {
		return "Nome: " + this.nome + "; ID: " + this.userID;
	}
}
