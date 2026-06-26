#include <stdio.h>
#include <stdlib.h>

#define ROW 21
#define COL 50

#define FILA (ROW * COL)

typedef struct posicao {
	int linha;
	int coluna;
} Posicao;

Posicao fila[FILA];
Posicao pai [ROW][COL];
int visitado [ROW][COL];
int inicioFila = 0;
int finalFila = 0;

void entrarFila (Posicao p);
Posicao sairFila (void);
void marcarCaminho (Posicao e, Posicao s);

int bfs (Posicao e, Posicao s);

char labirinto [ROW][COL] = {
	"#################################################",
    "E.....#...........#.................#...........#",
    "#.###.#.#.#######.#.#####.#########.#.#####.###.#",
    "#...#.#.#.......#.#.....#.....#.....#.....#...#.#",
    "###.#.#.#######.#.#####.#####.#.#########.###.#.#",
    "#...#.#.......#.....#...#.....#.......#.....#...#",
    "#.###.#######.#######.###.###########.#.#####.###",
    "#.....#.....#.......#...#.....#.......#.....#...#",
    "#####.#.###.#######.###.###.#.#.###########.###.#",
    "#.....#...#.......#.....#...#.#.....#.......#...#",
    "#.#######.#######.#######.###.#####.#.#######.#.#",
    "#.......#.....#.........#...#.....#.#.......#.#.#",
    "#######.#####.#.#######.###.#####.#.#######.#.#.#",
    "#.....#.....#.#.....#...#.......#.#.....#...#.#.#",
    "#.###.#####.#.###.#.#.#########.#.#####.#.###.#.#",
    "#...#.......#.....#.#.........#.#.......#.....#.#",
    "###.###############.#########.#.###############.#",
    "#.................#.........#.#.................#",
    "#.#########################.#.#################.#",
    "#...........................#...................S",
    "#################################################"
};

void exibirLabirinto(void);
Posicao localizar(char alvo);



int main(void) {
	Posicao entrada = localizar('E');
	Posicao saida = localizar('S');
	
	exibirLabirinto();

	if(bfs(entrada,saida)) {
		marcarCaminho(entrada, saida);
		exibirLabirinto();
	} else {
		printf("Caminho não encontrado");
	}

	return 0;
}

void exibirLabirinto(void) {

	printf("\nExibindo Labirinto\n");
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("%c", labirinto[i][j]);
		}
		printf("\n");
	}	
}

Posicao localizar (char alvo) {
	Posicao p;
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (labirinto [i][j] == alvo) {
				p.linha = i;
				p.coluna = j;
				return p;
			}
		}
	}
	p.linha = -1;
	p.coluna = -1;
	return p;
}

void entrarFila (Posicao p) {
	fila[finalFila] = p;
	finalFila++;
}

Posicao sairFila (void) {
	return fila[inicioFila++];
}

int bfs (Posicao e, Posicao s) {
	int dRow[4] = {-1, 1, 0, 0};
	int dCol[4]   = { 0, 0, -1, 1};


	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			visitado[i][j] = 0;
		}
	}
	entrarFila(e);
	
	visitado[e.linha][e.coluna] = 1;
	pai [e.linha][e.coluna] = e;

	while (inicioFila != finalFila) {
		Posicao atual = sairFila();

		if (atual.linha == s.linha && atual.coluna == s.coluna) {
			return 1;
		}

		for (int i = 0; i < 4; i++) {
			Posicao vizinho; 
			vizinho.linha = atual.linha + dRow [i];
			vizinho.coluna = atual.coluna + dCol [i];

			if (vizinho.linha >= 0 && vizinho.linha < ROW &&
				vizinho.coluna >=0 && vizinho.coluna < COL &&
				labirinto[vizinho.linha][vizinho.coluna] != '#' &&
				visitado[vizinho.linha][vizinho.coluna] == 0) {

				visitado[vizinho.linha][vizinho.coluna] = 1;
				pai[vizinho.linha][vizinho.coluna] = atual;
				entrarFila(vizinho);	
			}
		}	
	}
	return 0;
}

void marcarCaminho (Posicao e, Posicao s) {
	Posicao atual = s;

	while (atual.linha != e.linha || atual.coluna != e.coluna) {
        if (labirinto[atual.linha][atual.coluna] != 'S' &&
            labirinto[atual.linha][atual.coluna] != 'E') {
            labirinto[atual.linha][atual.coluna] = '*';
        }
        atual = pai[atual.linha][atual.coluna];
    }
	
}