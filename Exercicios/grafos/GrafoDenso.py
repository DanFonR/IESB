from Grafo import Grafo
from collections.abc import Iterable

class GrafoDenso(Grafo):
    __matriz: list[list[int]]
    __rotulos: dict[str, int]

    def __init__(self, vertices:int|Iterable[str]):
        if not isinstance(vertices, (int, Iterable)):
            raise TypeError("Tipo invalido")

        if isinstance(vertices, int):
            self.__rotulos = {str(i): i for i in range(vertices)}
        else:
            self.__rotulos = {
                rotulo: indice
                for (indice, rotulo) in enumerate(vertices)
            }

        self.__matriz = [[0] * self.numero_de_vertices()
                         for i in range(self.numero_de_vertices())]

    # Atividade 1

    def __definir_valor_aresta(self, u: int|str,
                               v: int|str, valor: int) -> None:
        if not isinstance(u, (int, str)) or not isinstance(v, (int, str)):
            raise TypeError("Tipo invalido")
        elif type(u) != type(v):
            raise TypeError("Tipos diferentes")

        U: int = self.__rotulos.get(str(u))
        V: int = self.__rotulos.get(str(v))

        if U == None or V == None:
            raise IndexError("Vertice nao existe")

        self.__matriz[U][V] = self.__matriz[V][U] = valor # matriz simetrica

    def adicionar_aresta(self, u: int|str, v: int|str) -> None:
        self.__definir_valor_aresta(u, v, valor=1)

    def remover_aresta(self, u: int|str, v: int|str) -> None:
        self.__definir_valor_aresta(u, v, valor=0)

    def numero_de_arestas(self) -> int:
        return sum(1 for i in range(self.numero_de_vertices())
                     for j in range(i, self.numero_de_vertices())
                     if self.__matriz[i][j])

    def numero_de_vertices(self) -> int:
        return len(self.__rotulos)

    def sequencia_de_graus(self) -> list[int]:
        return sorted(sum(1 for aresta in linha if aresta)
                       for linha in self.__matriz)

    def imprimir(self, file=None) -> None:
        valores_str: list[str]
        rotulos: list[str] = [str(i) for i in self.__rotulos.keys()]
        header: str = (" " * max(len(i) for i in rotulos)
                       + " | " + " | ".join(rotulos))

        print(header, file=file)
        print("-" * len(header), file=file)

        for (rotulo, valor) in self.__rotulos.items():
            valores_str = [str(i) for i in self.__matriz[valor]]

            print(f"{rotulo} | "
                  + " | ".join(valores_str), file=file)

    # Atividade 2

    def is_simples(self) -> bool: # matriz booleana nao permite varias arestas
        return not any(self.__matriz[i][i] for i in range(len(self.__rotulos)))

    def is_nulo(self) -> bool:
        return not any(self.__matriz[i][j]
                       for i in range(self.numero_de_vertices())
                       for j in range(self.numero_de_vertices()))

    def is_completo(self) -> bool:
        numero_vertices: int = self.numero_de_vertices()

        return all(self.__matriz[i][j]
                   if i != j else not self.__matriz[i][i]
                   for i in range(numero_vertices)
                   for j in range(numero_vertices))

    # Atividade 3

    def get_vertices(self) -> list[str]:
        return sorted(self.__rotulos.keys())

    def get_arestas(self) -> list[tuple[str, str]]:
        arestas: list[tuple[str, str]]|list = list()
        vertices_valores: dict[int, str] = {
            indice: rotulo for rotulo, indice in self.__rotulos.items()
        }

        for i in range(self.numero_de_vertices()):
            for j in range(i, self.numero_de_vertices()):
                if self.__matriz[i][j]:
                    tupla: tuple[str, str] = tuple(sorted(
                        (vertices_valores[j], vertices_valores[i])
                    ))
                    arestas.append(tupla)

        return arestas
