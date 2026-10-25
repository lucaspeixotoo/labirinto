# Labirinto

Programa em C que encontra o caminho mais curto em um labirinto usando busca em largura (BFS) em um grafo implícito. Atividade da disciplina de Estrutura de Dados.

## Como funciona

O labirinto é uma matriz de 21 linhas por 50 colunas, definida no código:

- `#` é parede
- `.` é caminho livre
- `E` é a entrada
- `S` é a saída

O programa localiza `E` e `S`, cada célula livre vira um nó do grafo e os movimentos são nas quatro direções (cima, baixo, esquerda, direita). A busca em largura, com fila implementada em vetor, explora o labirinto e guarda de onde veio cada posição. Ao chegar na saída, o caminho é reconstruído de trás para frente e marcado com `*`. Como o grafo não tem peso, a BFS garante o caminho mais curto.

Se não houver caminho, o programa imprime `Caminho não encontrado`.

## Como executar

```bash
gcc grafos.c -o grafos
./grafos
```

## Exemplo de saída (trecho)

```
E*****#...........#.................#...........#
#.###*#.#.#######.#.#####.#########.#.#####.###.#
#...#*#.#.......#.#.....#.....#.....#.....#...#.#
```

## Estrutura

- `grafos.c`: todo o código (fila, BFS, reconstrução do caminho e impressão)
