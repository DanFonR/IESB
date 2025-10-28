#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <omp.h>

inline int para_classe(int valor, int min, int intervalo) {
    return (valor - min) / intervalo;
}

inline double coef_pearson(double media, double desvio_padrao) {
    return (desvio_padrao / media) * 100;
}

typedef struct {
    std::vector<int> classes;
    int min;
    int intervalo;
} class_mins;

class_mins classes(std::vector<int> valores, int intervalo) {
    class_mins retorno;

    int min = valores[0];
    int max = valores[0];

    #pragma omp parallel for
    for (int valor : valores) {
        #pragma omp critical
        {
            if (valor < min) min = valor;
            if (valor > max) max = valor;
        }
    }

    std::vector<int> classes(para_classe(max, min, intervalo) + 1, 0);

    #pragma omp parallel for ordered
    for (int valor : valores) {
        #pragma omp ordered
        {
            int classe = para_classe(valor, min, intervalo);
            classes[classe]++;
        }
    }

    retorno.classes = classes;
    retorno.min = min;
    retorno.intervalo = intervalo;

    return retorno;
}

double media_agrupada(class_mins dados) {
    std::vector<int> classes = dados.classes;
    int min = dados.min;
    int intervalo = dados.intervalo;

    size_t soma_freq = 0.0;
    double prods = 0.0;

    #pragma omp parallel for reduction(+:soma_freq, prods)
    for (size_t i = 0; i < classes.size(); i++) {
        int xi = (2 * min + intervalo * (2*i + 1)) / 2;
        prods += xi * classes[i];
        soma_freq += classes[i];
    }

    return prods / soma_freq;
}

double desvio_padrao_agrupado(class_mins dados) {
    std::vector<int> classes = dados.classes;
    int min = dados.min;
    int intervalo = dados.intervalo;

    double desvio_padrao;
    double termo_1;
    double termo_2;

    double soma_xi = 0.0;
    double soma_xi2 = 0.0;
    double soma_freq = 0.0;

    #pragma omp parallel for reduction(+:soma_xi, soma_xi2, soma_freq)
    for (size_t i = 0; i < classes.size(); i++) {
        int xi = (2 * min + intervalo * (2*i + 1)) / 2;
        soma_xi += xi;
        soma_xi2 += xi * xi;
        soma_freq += classes[i];
    }

    termo_1 = soma_xi2 / soma_freq;
    termo_2 = (soma_xi / soma_freq) * (soma_xi / soma_freq);
    desvio_padrao = std::sqrt(termo_1 + termo_2);

    return desvio_padrao;
}

void testa_cv(size_t tam_vetor) {
    std::vector<int> alturas_cm(tam_vetor, 0);
    std::vector<int> pesos_kg(tam_vetor, 0);

    #pragma omp parallel for
    for (size_t i = 0; i < tam_vetor; i++) {
        alturas_cm[i] = rand() % 30 + 150;
        pesos_kg[i] = rand() % 30 + 43;
    }

    class_mins classes_alturas = classes(alturas_cm, 8);
    class_mins classes_pesos = classes(pesos_kg, 4);

    double media_alturas = media_agrupada(classes_alturas);
    double desvio_alturas = desvio_padrao_agrupado(classes_alturas);
    double cv_alturas = coef_pearson(media_alturas, desvio_alturas);

    double media_pesos = media_agrupada(classes_pesos);
    double desvio_pesos = desvio_padrao_agrupado(classes_pesos);
    double cv_pesos = coef_pearson(media_pesos, desvio_pesos);

    std::cout << "Alturas:" << std::endl
    << "Média: " << media_alturas << "; Desvio Padrão: " << desvio_alturas
    << "; CV: " << cv_alturas << std::endl << std::endl;

    std::cout << "Pesos:" << std::endl
    << "Média: " << media_pesos << "; Desvio Padrão: " << desvio_pesos
    << "; CV: " << cv_pesos << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    testa_cv(2);
    return 0;
}
