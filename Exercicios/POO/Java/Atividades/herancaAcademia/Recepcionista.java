package academia;

public class Recepcionista extends Usuario {
	
	public Recepcionista(String nome, String senha, int ID) {
		super(nome, senha, ID);
	}
	
	public void registraNovoAluno(String aluno) {
		System.out.println(super.toString() + " registra aluno " + aluno);
	}
	
	public void gerenciaPagamentos() {
		System.out.println("A gerenciar pagamentos...");
	}
}
