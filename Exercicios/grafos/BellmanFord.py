from math import inf
from typing import NoReturn


type Graph = dict[str, dict[str, int]]
type Table = dict[str, tuple[int|float, str]]


def relax(graph: Graph, table: Table) -> Table:
    # Evita cópia rasa da tabela
    temp: Table = {k: (v[0], v[1]) for (k, v) in table.items()}

    for (curr, edges) in graph.items():
        for (vert, weight) in edges.items():
            # peso(adjacente) = peso(atual) + peso(aresta)
            vert_weight: int = temp[curr][0] + weight

            # Mínimo entre o que está na tabela e o novo peso
            if temp[vert][0] <= vert_weight: continue
            temp[vert] = (vert_weight, curr)

    return temp


def bellman_ford(graph: Graph, init: str) -> Table:
    table: Table = {vert: (inf, "") for vert in graph.keys()}
    nulls: Table = {vert: (inf, "") for vert in graph.keys()}

    if init not in graph: return nulls

    table[init] = (0, "")

    # Certifica que init é o 1º item a ser iterado
    graph = {init: graph[init]} | {k: v for (k, v) in graph.items()
                                   if k != init}

    # |V| - 1 relaxamentos
    for _ in range(len(graph) - 1): table = relax(graph, table)

    # |V|-ésimo relaxamento de teste
    # Condição de erro: ciclo de peso negativo a partir de init
    if table != relax(graph, table): table = nulls

    return table


@lambda autoexec: __name__ == "__main__" and autoexec()
def main() -> NoReturn:
    GRAFO_TESTE: Graph = {
        "S": {"A": 6, "B": 7},
        "A": {"C": 5, "D": -4},
        "B": {"A": -2, "C": 8, "D": 9},
        "C": {"D": -3},
        "D": {"S": 2}
    }

    GRAFO_EXERCICIO: Graph = {
        "S": {"A": 3, "B": 5},
        "A": {"C": -5, "D": 8},
        "B": {"A": 6, "C": 8, "D": -9},
        "C": {"D": -3},
        "D": {"S": 2}
    }

    print(f"{GRAFO_TESTE = }",
          f"{bellman_ford(graph=GRAFO_TESTE, init="S") = }",
          "",
          f"{GRAFO_EXERCICIO = }",
          f"{bellman_ford(graph=GRAFO_EXERCICIO, init="S") = }",
          sep='\n')

    exit(0)
