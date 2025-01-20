package academia;

public class Instrutor extends Recepcionista {
	
	public Instrutor(String nome, String senha, int ID) {
		super(nome, senha, ID);
	}
	
	public void criaPlanoDeTreino() {
		System.out.println("A criar planos de treino...");
	}
	
	public void avaliaDesempenhoDeAlunos() {
		System.out.println("Instrutor está avaliando o desempenho dos seus alunos");
	}
}
