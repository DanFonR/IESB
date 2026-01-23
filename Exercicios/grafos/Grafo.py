from __future__ import annotations # Permite tipagem da propria classe em seus metodos
from abc import ABC, abstractmethod
from itertools import permutations

class Grafo(ABC):
    # Atividade 1

    @abstractmethod
    def numero_de_vertices(self) -> int:
        pass

    @abstractmethod
    def numero_de_arestas(self) -> int:
        pass

    @abstractmethod
    def sequencia_de_graus(self) -> list[int]:
        pass

    @abstractmethod
    def adicionar_aresta(self, u, v) -> None:
        pass

    @abstractmethod
    def remover_aresta(self, u, v) -> None:
        pass

    @abstractmethod
    def imprimir(self, file=None) -> None:
        pass

    # Atividade 2

    @abstractmethod
    def is_simples(self) -> bool:
        pass

    @abstractmethod
    def is_nulo(self) -> bool:
        pass

    @abstractmethod
    def is_completo(self) -> bool:
        pass

    # Atividade 3

    @abstractmethod
    def get_vertices(self) -> list[str]:
        pass

    @abstractmethod
    def get_arestas(self) -> list[tuple[str, str]]:
        pass

    def is_subgrafo(self, outro_grafo: Grafo) -> bool:
        if not isinstance(outro_grafo, Grafo):
            raise TypeError("Comparacao invalida")

        arestas_self: set[tuple[str, str]] = set(self.get_arestas())
        arestas_outro: set[tuple[str, str]] = set(outro_grafo.get_arestas())
        vertices_self: set[str] = set(self.get_vertices())
        vertices_outro: set[str] = set(outro_grafo.get_vertices())

        return (arestas_self.issubset(arestas_outro)
                and vertices_self.issubset(vertices_outro))

    def is_subgrafo_gerador(self, outro_grafo: Grafo) -> bool:
        if not isinstance(outro_grafo, Grafo):
            raise TypeError("Comparacao invalida")

        return (set(self.get_vertices()) == set(outro_grafo.get_vertices())
                and self.is_subgrafo(outro_grafo))

    def is_subgrafo_induzido(self, outro_grafo: Grafo) -> bool:
        arestas_outro: list[tuple[str, str]]

        # possiveis arestas para cada vertice do subgrafo
        arestas_outro_filtradas: set[tuple[str, str]]

        if not isinstance(outro_grafo, Grafo):
            raise TypeError("Comparacao invalida")

        if not self.is_subgrafo(outro_grafo):
            return False

        arestas_outro = outro_grafo.get_arestas()
        arestas_outro_filtradas = set(
            filter(lambda aresta: (aresta[0] in self.get_vertices()
                                   and aresta[1] in self.get_vertices()),
                   arestas_outro))

        return arestas_outro_filtradas == set(self.get_arestas())

    # Atividade 4

    def is_isomorfo(self, outro_grafo: Grafo) -> bool:
        if not isinstance(outro_grafo, Grafo):
            raise TypeError("Comparacao invalida")

        if (self.numero_de_arestas() != outro_grafo.numero_de_arestas()
            or self.numero_de_vertices() != outro_grafo.numero_de_vertices()
            or self.sequencia_de_graus() != outro_grafo.sequencia_de_graus()):
            return False

        vertices_self: list[str] = self.get_vertices()
        vertices_outro: list[str] = outro_grafo.get_vertices()
        arestas_self: list[tuple[str, str]] = self.get_arestas()
        arestas_outro: list[tuple[str, str]] = outro_grafo.get_arestas()

        for perm in permutations(vertices_outro):
            possivel_aresta_outro: tuple[str, str]
            mapa: dict[str, str] = dict(zip(vertices_self, perm))

            for aresta_self in arestas_self:
                possivel_aresta_outro = tuple(sorted((mapa[aresta_self[0]],
                                                      mapa[aresta_self[1]])))

                if possivel_aresta_outro not in arestas_outro:
                    break
            else: # Todas as arestas batem para essa permutacao
                return True

        return False # Nenhuma permutacao funcionou

    # Atividade 5

    def colorir_grafo(self) -> tuple[int, dict[str, int]]:
        qtd_cores: int = 1
        vertices: list[str] = self.get_vertices()
        arestas: list[tuple[str, str]] = self.get_arestas()
        resultado: dict[str, int|None]
        resultado = self.__tentar_colorir_grafo(qtd_cores, vertices, arestas)

        while not all(val != None for val in resultado.values()):
            qtd_cores += 1
            resultado = self.__tentar_colorir_grafo(qtd_cores, vertices, arestas)

        return (qtd_cores, resultado)

    @staticmethod
    def __tentar_colorir_grafo(
        qtd_cores: int, vertices: list[str],
        arestas: list[tuple[str, str]]
    ) -> dict[str, int|None]:
        indice: int = 0 # aponta para vertices, serve para backtracking
        indice_max: int = len(vertices)
        cores: dict[str, int|None] = {vertice: None for vertice in vertices}

        while 0 <= indice < indice_max:
            cor: int = 0
            vertices_adj: list[str] = [
                vertice for vertice in vertices
                if tuple(sorted((vertices[indice], vertice))) in arestas
            ]
            cores_adj: list[int|None] = [
                cor for (vertice, cor) in cores.items()
                if vertice in vertices_adj
            ]

            while cor in cores_adj: # percorre cores disponiveis
                cor += 1

            if cor == qtd_cores: # nao ha mais cores, realiza backtracking
                indice -= 1

            else:
                if cores[vertices[indice]] != None: # houve backtracking
                    cores[vertices[indice]] += 1 # incrementa e testa

                    while cores[vertices[indice]] in cores_adj:
                        cores[vertices[indice]] += 1

                    if cores[vertices[indice]] == qtd_cores: # valor proibido
                        cores[vertices[indice]] = None
                        indice -= 1 # outro backtracking
                else:
                    cores[vertices[indice]] = cor
                    indice += 1

        return cores

    # def colorir(self) -> tuple[int, dict[str, int]]: # versao sem backtracking
    #     vertices: list[str] = self.get_vertices()
    #     arestas: list[tuple[str, str]] = self.get_arestas()
    #     cores: dict[str, int|None] = {v: None for v in vertices}

    #     for vertice in vertices:
    #         cor: int = 0
    #         vertices_adj: list[str] = [
    #             v for v in vertices if (vertice, v) in arestas
    #             or (v, vertice) in arestas
    #         ]
    #         cores_adj: dict[str, int|None] = {
    #             v: val for (v, val) in cores.items()
    #             if v in vertices_adj
    #         }

    #         while cor in cores_adj.values():
    #             cor += 1

    #         cores[vertice] = cor

    #     return (max(cores.values()) + 1, cores)
