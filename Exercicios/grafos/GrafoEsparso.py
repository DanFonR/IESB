from Grafo import Grafo
from collections.abc import Iterable
from sys import stderr

type lista_adj = dict[str, list[str]|list]

class GrafoEsparso(Grafo):
    __vertices: lista_adj|dict

    def __init__(self, vertices:int|Iterable[str]):
        if isinstance(vertices, int):
            self.__vertices = {str(vertice): list()
                               for vertice in range(vertices)}
        elif isinstance(vertices, Iterable):
            self.__vertices = {str(vertice): list() for vertice in vertices}
        else:
            raise TypeError("Tipo invalido para inicializacao")

    # Atividade 1

    def numero_de_vertices(self) -> int:
        return len(self.__vertices)

    def numero_de_arestas(self) -> int:
        return sum(len(arestas) for arestas in self.__vertices.values()) // 2

    def sequencia_de_graus(self) -> list[int]:
        return sorted(len(arestas) for arestas in self.__vertices.values())

    def adicionar_aresta(self, u: int|str, v:int|str) -> None:
        if not isinstance(u, (int, str)) or not isinstance(v, (int, str)):
            raise TypeError("Tipo invalido")
        elif type(u) != type(v):
            raise TypeError("Tipos diferentes")

        if str(u) in self.__vertices and str(v) in self.__vertices:
            self.__vertices[str(u)].append(str(v))
            self.__vertices[str(v)].append(str(u))
        else:
            raise IndexError("Um dos vertices nao encontrado")

    def remover_aresta(self, u:int|str, v:int|str, peso: int = 1) -> None:
        if not isinstance(u, (int, str)) or not isinstance(v, (int, str)):
            raise TypeError("Tipo invalido")
        elif type(u) != type(v):
            raise TypeError("Tipos diferentes")

        if str(u) in self.__vertices and str(v) in self.__vertices:
            try:
                self.__vertices[str(u)].remove(str(v))
                self.__vertices[str(v)].remove(str(u))
            except ValueError:
                raise ValueError("Aresta nao existe")
        else:
            raise IndexError("Um dos vertices nao encontrado")

    def imprimir(self, file=None) -> None:
        for vertice, arestas in self.__vertices.items():
            print(f"{vertice} -> {arestas}", file=file)

    # Atividade 2

    def is_simples(self) -> bool:
        for vertice, arestas in self.__vertices.items():
            if vertice in arestas or len(arestas) != len(set(arestas)):
                return False

        return True

    def is_nulo(self) -> bool:
        return not any(self.__vertices.values())

    def is_completo(self) -> bool:
        if not self.is_simples(): return False

        for arestas in self.__vertices.values():
            if len(set(arestas)) + 1 != len(self.__vertices):
                return False

        return True

    # Atividade 3

    def get_vertices(self) -> list[str]:
        return sorted(self.__vertices.keys())

    def get_arestas(self) -> list[tuple[str, str]]:
        arestas: list[tuple[str, str]]|list = list()
        vertices_processados: list[str]|list = list()

        for vertice in self.get_vertices():
            for vertice2 in self.__vertices[vertice]:
                if vertice2 in vertices_processados:
                    continue

                arestas.append(tuple(sorted((vertice, vertice2))))

            vertices_processados.append(vertice)

        return arestas
