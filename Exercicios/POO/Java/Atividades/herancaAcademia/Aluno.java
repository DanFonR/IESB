package academia;

public class Aluno extends Usuario {
	
	private int numeroMatricula;
	
	public Aluno(String nome, String senha, int ID, int matricula) {
		super(nome, senha, ID);
		this.numeroMatricula = matricula;
	}

	public void agendaAula() {
		System.out.println(this.toString() + " está agendando uma aula...");
	}

	public void cancelaAula() {
		System.out.println(this.toString() + " está cancelando uma aula agendada...");
	}
	
	@Override
	public String toString() {
		return String.format("%s; Matrícula: %d",
				super.toString(), this.numeroMatricula);
	}
}
