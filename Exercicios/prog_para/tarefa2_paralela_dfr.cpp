#include <iostream>
#include <limits>
#include <vector>
#include <string>

#define clear_cin() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
#define clear_screen() std::cout << "\033[2J\033[1;1H";

// questao 6
// item 6.a.
int soma(int a, int b);
// item 6.b.
void incrementa(int &num);
// item 6.c.
int soma(int a, int b, int c);

int main() {
    std::cout << std::boolalpha;
    // questao 1.
    // item 1.a.
    {
        std::string nome = "Dannyel";
        int idade = 21;
        double altura = 1.74;
        bool is_aprovado = false;

        std::cout << nome << "; idade: " << idade \
                  << "; altura: " << altura \
	              << "; aprovado: " << is_aprovado << std::endl;
    }

    std::cout << std::endl;

    // item 1.b.
    {
        int raio = 5;
        const double PI = 3.1415926;
        double area = PI * raio * raio;

        std::cout << "area de circulo de raio " << raio << ": " << area << "u.a." << std::endl;
    }

    std::cout << std::endl;

    // questao 2.
    // item 2.a.
    {
        std::string nome_entrada;
        int idade_entrada;
        std::cout << "digite seu primeiro nome: ";
        std::cin >> nome_entrada;
        clear_cin();

        std::cout << "digite sua idade: ";
        std::cin >> idade_entrada;
        clear_cin();

        std::cout << "Olá, " << nome_entrada << "! " \
                  << "Você tem " << idade_entrada << " anos." << std::endl;
    }
 
    std::cout << std::endl;

    // item 2.b.
    {
        std::string nome_completo;
        std::cout << "digite seu nome completo: ";
        std::getline(std::cin, nome_completo);

        std::cout << "Nome completo: " << nome_completo << std::endl;
    }

    std::cout << std::endl;

    // questao 3.
    {
        // item 3.a.
        int numero1;
        int numero2;
    
        std::cout << "digite o 1o numero: ";
        std::cin >> numero1;
        clear_cin();

        std::cout << "digite o 2o numero: ";
        std::cin >> numero2;
        clear_cin();

        int soma = numero1 + numero2;
        int subtracao = numero1 - numero2;
        int multiplicacao = numero1 * numero2;
        int divisao_inteira = numero1 / numero2;
        double divisao_real = (double)numero1 / numero2;

        std::cout << "soma: " << soma << std::endl \
	              << "subtracao: " << subtracao << std::endl \
	              << "multiplicacao: " << multiplicacao << std::endl \
	              << "divisao inteira: " << divisao_inteira << std::endl \
	              << "divisao real: " << divisao_real << std::endl;

        // item 3.b.
        std::cout << "O maior entre " << numero1 << " e " << numero2 \
		          << " é " << ((numero1 > numero2)? numero1 : numero2) << std::endl;
    }

    std::cout << std::endl;

    // questao 4.
    // item 4.a.
    {
        int nota;

	    std::cout << "Digite uma nota (0-10) ";
	    std::cin >> nota;
	    clear_cin();

	    if (6 <= nota && nota <= 10)
	        std::cout << "Aprovado" << std::endl;
	    else if (4 <= nota && nota < 6)
	        std::cout << "Prova final" << std::endl;
	    else if (nota < 4)
	        std::cout << "Reprovado" << std::endl;
	    else
	        std::cout << "Nota invalida" << std::endl;
    }

    std::cout << std::endl;

    // item 4.b.
    {
        int opcao;
	    bool em_loop = true;
	    std::vector<std::string> nomes;

	    while (em_loop) {
            char voltar;
	        std::string nome;

            std::cout << "Deseja" << std::endl \
	    	          << "1 - Cadastrar nome;" << std::endl \
	    	          << "2 - Listar nomes;" << std::endl \
	    	          << "3 - Sair" << std::endl;
	        std::cin >> opcao;
	        clear_cin();

	        switch (opcao) {
                case 1:	    
	    	        std::cout << "Digite o nome: ";
	    	        std::getline(std::cin, nome);
	    	        nomes.push_back(nome);
	    	        break;
	    	    case 2:
	    	        std::cout << "Nomes: " << std::endl;

	    	        for (std::string nome : nomes)
	    	            std::cout << nome << std::endl;
	    	        break;
                case 3:
	    	        em_loop = false;
	    	        break;
	    	    default:
	    	        std::cerr << "Opcao invalida";
	    	        break;
	        }

            if (em_loop) break;

	        std::cout << "Deseja voltar ao menu? (Y/n) ";
	        std::cin >> voltar;
            clear_cin();

	        if (voltar == 'n' || voltar == 'N') break;

	        clear_screen();
	    }
    }

    std::cout << std::endl;

    // questao 5
    // item 5.a.
    {
	    std::cout << "Numeros impares de 1 a 20: " << std::endl;

	    for (int i = 1; i < 20; i++)
	        if (i % 2 == 1)
		        std::cout << i << std::endl;
    }

    std::cout << std::endl;

    // item 5.b.
    {
        int num = 10;

	    std::cout << "Contador regressivo (10 a 0): " << std::endl;

	    while (num >= 0) {
	        std::cout << num << std::endl;

            num--;
        }
        
        
    }

    std::cout << std::endl;

    // item 5.c.
    {
        int opcao;

	    do {
	        std::cout << "Menu: " << std::endl \
	       	          << "1 - Opcao 1" << std::endl \
	    	          << "2 - Opcao 2" << std::endl \
	    	          << "3 - Opcao 3" << std::endl \
	    	          << "0 - Sair" << std::endl;
	        std::cin >> opcao;
	        clear_cin();

	        switch (opcao) {
                case 1:
	    	    case 2:
                case 3:
                    std::cout << "Opcao " << opcao << "..." << std::endl;
                    break;
                case 0:
                    std::cout << "Saindo..." << std::endl;
                    break;
                default:
                    std::cerr << "Opcao invalida" << std::endl;
                    break;
	        }

        }
        while (opcao != 0);
    }

    std::cout << std::endl;

    // questao 6
    // item 6.a.
    {
        int a = 6;
        int b = 7;
        int c = soma(a, b);

        std::cout << "Funcao soma(" << a << ", " << b << ") = " \
                  << c << std::endl;
    }

    std::cout << std::endl;

    // item 6.b.
    {
        int num = 8;

        std::cout << "Valor atual de num: " << num << std::endl;

        incrementa(num);

        std::cout << "Valor apos incrementa(num): " << num << std::endl;
    }

    std::cout << std::endl;

    // item 6.c.
    {
        int c = 11;
        int d = 34;
        int e = 25;
        int f = soma(c, d, e);

        std::cout << "Funcao soma(" << c << ", " << d << ", " << e << ") = " \
                  << f << std::endl;
    }

    std::cout << std::endl;

    // questao 7
    // item 7.a.
    {
        int inteiros[] = {26, 12, 243, 12, 967};
        int tamanho_array = 5;
        int somatorio = 0;

        std::cout << "Somatorio do array {";

        for (int i = 0; i < tamanho_array; i++) {
            somatorio += inteiros[i];

            std::cout << inteiros[i] << ", ";
        }

        std::cout << "\b\b} = " << somatorio << std::endl;   
    }

    std::cout << std::endl;

    // item 7.b.
    {
        std::vector<int> valores = {5, 10, 15};

        int valor1 = 20;
        int valor2 = 25;

        valores.push_back(valor1);
        valores.push_back(valor2);

        std::cout << "Valores inseridos: " << valor1 << ", " << valor2 << std::endl;

        int soma_vetor = 0;
        int tamanho = valores.size();

        std::cout << "Valores do vetor: <";

        for (int valor : valores) {
            std::cout << valor << ", ";

            soma_vetor += valor;
        }

        std::cout << "\b\b>" << std::endl << "Tamanho: " << tamanho << std::endl \
                  << "Soma: " << soma_vetor << std::endl;
    }

    std::cout << std::endl;

    // questao 8
    // item 8.a.
    {
        int numero = 2;
        int *ponteiro = &numero;
        int &referencia = numero;

        std::cout << "Valor: " << numero << std::endl;

        *ponteiro *= 2;
        std::cout << "Valor duplicado: " << numero \
                  << " (Valor pelo ponteiro: " << *ponteiro << ")" << std::endl;
        
        referencia *= 3;
        std::cout << "Valor triplicado: " << numero \
                  << " (Valor pela referencia: " << referencia << ")" << std::endl;
    }
    
    std::cout << std::endl;

    // item 8.b.
    {
        int *ponteiro_dinamico = new int;
        *ponteiro_dinamico = 5;

        std::cout << "Valor apontado pelo ponteiro dinamico: " << *ponteiro_dinamico << std::endl;

        delete ponteiro_dinamico;
        ponteiro_dinamico = NULL;
    }

    std::cout << std::endl;

    // questao 9
    // item 9.a.
    {
        struct Aluno {
            std::string nome;
            int idade;
        } aluno;

        std::cout << "Insira o nome do aluno: ";
        std::getline(std::cin, aluno.nome);

        std::cout << "Insira a idade do aluno: ";
        std::cin >> aluno.idade;
        clear_cin();

        std::cout << "Aluno " << aluno.nome << " (" << aluno.idade << " anos)" << std::endl;
    }

    std::cout << std::endl;

    // item 9.b.
    {
        class ContaBancaria {
            private:
                double valor_conta = 0;
            public:
                void depositar(double valor) {
                    this->valor_conta += valor;
                }

                double sacar(double valor) {
                    double valor_sacado;

                    if (valor >= this->valor_conta) {
                        valor_sacado = this->valor_conta;
                        this->valor_conta = 0;
                    }
                    else {
                        this->valor_conta -= valor;
                        valor_sacado = valor;
                    }

                    return valor_sacado;
                }

                void imprimir() {
                    std::cout << "Voce tem R$" << this->valor_conta << std::endl;
                }
        };

        double valor_deposito = 500.00;
        double valor_saque = 271.24;
        ContaBancaria conta_teste = ContaBancaria();

        conta_teste.depositar(valor_deposito);
        conta_teste.imprimir();
        conta_teste.sacar(valor_saque);
        conta_teste.imprimir();
    }
    return 0;
}

// questao 6
// item 6.a.
int soma(int a, int b) {
    int resultado = a + b;

    return resultado;
}

// item 6.b.
void incrementa(int &num) {
    num++;
}

// item 6.c.
int soma(int a, int b, int c) {
    int resultado = a + b + c;

    return resultado;
}
