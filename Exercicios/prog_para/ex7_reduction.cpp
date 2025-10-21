#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#include <ctime>
#include <omp.h>

typedef struct {
    size_t id;
    int departamento;
    int cargo;
    double salario;
} Pessoa;

typedef struct {
    double media;
    double dp;
} stats;

enum {
    Vendas, RnD
};

enum {
    Cargo1, Cargo2
};

double media(std::vector<double> valores, bool is_amostra) {
    double somatorio = 0.0;

    #pragma omp parallel for reduction(+:somatorio)
    for (double valor : valores)
        somatorio += valor;

    double resultado = somatorio / (valores.size() - is_amostra);

    return resultado;
}

double desvio_padrao(std::vector<double> valores, bool is_amostra) {
    double mi = media(valores, is_amostra);
    double somatorio = 0.0;

    #pragma omp parallel for reduction(+:somatorio)
    for (double valor : valores) {
        const double desvio = (valor - mi);
        const double desvio_quad = desvio * desvio;

        somatorio += desvio_quad;
    }

    double resultado = std::sqrt(somatorio / (valores.size() - is_amostra));

    return resultado;
}

int main() {
    std::srand(std::time(NULL));

    stats dados_departamentos[2] = {
        {0.0, 0.0}, {0.0, 0.0}
    };
    stats dados_cargos[2] = {{0.0, 0.0}, {0.0, 0.0}};

    std::vector<Pessoa> BT_AlfaOmega(2000000);
    std::vector<double> vendas_dados = std::vector<double>();
    std::vector<double> rnd_dados = std::vector<double>();
    std::vector<double> cargo1_dados = std::vector<double>();
    std::vector<double> cargo2_dados = std::vector<double>();

    #pragma omp parallel for
    for (size_t i = 0; i < BT_AlfaOmega.size(); i++) {
        const int id = (-i * 2 + 5 + i * i) % 2000000;
        const int dep = rand() % 2;
        const int cargo = rand() % 2;
        const double salario = static_cast<double>(rand() % 10000 + 1200);

        const Pessoa p = {id, dep, cargo, salario};
        BT_AlfaOmega[i] = p;
    }

    #pragma omp parallel for
    for (Pessoa p : BT_AlfaOmega) {
        #pragma omp critical
        {
            switch (p.departamento) {
                case Vendas:
                    vendas_dados.push_back(p.salario);
                    break;
                case RnD:
                    rnd_dados.push_back(p.salario);
                    break;
            }
            switch (p.cargo) {
                case Cargo1:
                    cargo1_dados.push_back(p.salario);
                    break;
                case Cargo2:
                    cargo2_dados.push_back(p.salario);
                    break;
            }
        }
    }

    dados_departamentos[Vendas] = {
        media(vendas_dados, true), desvio_padrao(vendas_dados, true)
    };
    dados_departamentos[RnD] = {
        media(rnd_dados, true), desvio_padrao(rnd_dados, true)
    };
    dados_cargos[Cargo1] = {
        media(cargo1_dados, true), desvio_padrao(cargo1_dados, true)
    };
    dados_cargos[Cargo2] = {
        media(cargo2_dados, true), desvio_padrao(cargo2_dados, true)
    };

    std::cout << "Dados departamentos:" << std::endl;
    std::cout << "Vendas: média: " << dados_departamentos[Vendas].media
    << ", DP: " << dados_departamentos[Vendas].dp << std::endl;
    std::cout << "RnD: média: " << dados_departamentos[RnD].media
    << ", DP: " << dados_departamentos[RnD].dp << std::endl << std::endl;

    std::cout << "Cargos:" << std::endl;
    std::cout << "Cargo 1: média: " << dados_cargos[Cargo1].media << ", DP: "
    << dados_cargos[Cargo1].dp << std::endl;
    std::cout << "Cargo 2: média: " << dados_cargos[Cargo2].media << ", DP: "
    << dados_cargos[Cargo2].dp << std::endl;

    return 0;
}