from __future__ import annotations
from collections.abc import Iterable

type edge = tuple[str | int, str | int, int]

class GrafoEsparsoKruskal:
    def __init__(self, vertices: Iterable[str | int]):
        self.__conexoes: dict[str | int, set[tuple[str | int, int]]]
        self.__conexoes = {i: set() for i in vertices}

    def __repr__(self) -> str:
        return str(self.__conexoes)

    def __str__(self) -> str:
        return str(self.__conexoes)

    def add_vert(self, vert: str | int | Iterable[str | int]) -> None:
        if not isinstance(vert, Iterable):
            if vert in self.vertices:
                return

            self.__conexoes[vert] = set()
        else:
            for i in vert:
                self.add_vert(i)

    def add_arest(self, u: str | int, v: str | int, peso: int = 1) -> None:
        if not (u in self.vertices and v in self.vertices):
            return

        self.__conexoes[u].add((v, peso))
        self.__conexoes[v].add((u, peso))

    @property
    def arestas(self) -> list[edge]:  # [(vertice1, vertice2, peso), ...]
        arestas_ret: set = set()
        vertices_processados: set = set()
        vertice: str | int
        conexao: set[tuple[str | int, int]]

        for (vertice, conexoes) in self.__conexoes.items():
            if vertice in vertices_processados: continue

            for conexao in conexoes:
                if conexao[0] not in vertices_processados:
                    arestas_ret.add((vertice, conexao[0], conexao[1]))

            vertices_processados.add(vertice)

        arestas_ret = sorted(arestas_ret, key=lambda n: n[2])

        return arestas_ret

    @property
    def vertices(self) -> list[str | int]:
        return list(self.__conexoes.keys())

    def kruskal(self) -> GrafoEsparsoKruskal:
        aresta: edge
        arestas: list[edge] = self.arestas
        floresta: list[GrafoEsparsoKruskal] = [GrafoEsparsoKruskal([i]) 
                                                for i in self.vertices]

        for aresta in arestas:
            # lista de indices da lista de grafos (floresta)
            to_connect: list[int] = list()
            ind: int
            arvore: GrafoEsparsoKruskal

            for (ind, arvore) in enumerate(floresta):
                # ignora aresta caso ja exista em alguma arvore
                if (aresta[0] in arvore.vertices
                    and aresta[1] in arvore.vertices):
                    break

                # apensa na lista de indices o indice da arvore na floresta
                if aresta[0] in arvore.vertices:
                    to_connect.append(ind)
                elif aresta[1] in arvore.vertices:
                    to_connect.append(ind)
            else: # sem arvores com a aresta testada
                arvore_1: GrafoEsparsoKruskal = floresta[to_connect[0]]

                # tira arvore da floresta
                # e adiciona seus vertices e arestas na 1a arvore
                arvore_2: GrafoEsparsoKruskal = floresta.pop(to_connect[1])
                arvore_1.add_vert(arvore_2.vertices)

                aresta2: edge
                for aresta2 in arvore_2.arestas:
                    arvore_1.add_arest(*aresta2)

                arvore_1.add_arest(*aresta) # adiciona aresta do teste
                floresta[to_connect[0]] = arvore_1

        return floresta[0] # sobra apenas 1 item na lista, que é retornado
