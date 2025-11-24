#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
  Jogo de xadrez simplificado em C.
  Regras implementadas (simplificadas):
  - Representação com matriz 8x8 de struct Piece.
  - Movimentação básica e validação de cada peça.
  - Validação de entrada no formato "e2 e4".
  - Promoção de peão -> rainha.
  - Não implementa roque, en-passant, nem verificação de xeque/xeque-mate.
  - Todo o código está dentro da função main() conforme solicitado.
*/

typedef struct {
    char type;   // 'P' pawn, 'R' rook, 'N' knight, 'B' bishop, 'Q' queen, 'K' king, '.' empty
    char color;  // 'w' white, 'b' black, '.' empty
    int moved;   // flag para saber se a peça já se moveu (poderia ser usado para roque)
} Piece;

int main() {
    Piece board[8][8];
    int i, j;
    char cmd[64];
    int running = 1;
    char turn = 'w'; // 'w' começa

    // --- Função auxiliar inline (comentada) ---
    // Não podemos criar funções externas; portanto todo o comportamento fica dentro do main.

    // Inicializa o tabuleiro com posições padrão
    for (i = 0; i < 8; ++i)
        for (j = 0; j < 8; ++j) {
            board[i][j].type = '.';
            board[i][j].color = '.';
            board[i][j].moved = 0;
        }

    // Peças brancas (linha 7 é a 1a fileira visível para jogador branco)
    board[7][0].type = 'R'; board[7][0].color = 'w';
    board[7][1].type = 'N'; board[7][1].color = 'w';
    board[7][2].type = 'B'; board[7][2].color = 'w';
    board[7][3].type = 'Q'; board[7][3].color = 'w';
    board[7][4].type = 'K'; board[7][4].color = 'w';
    board[7][5].type = 'B'; board[7][5].color = 'w';
    board[7][6].type = 'N'; board[7][6].color = 'w';
    board[7][7].type = 'R'; board[7][7].color = 'w';
    for (j = 0; j < 8; ++j) { board[6][j].type = 'P'; board[6][j].color = 'w'; }

    // Peças pretas
    board[0][0].type = 'R'; board[0][0].color = 'b';
    board[0][1].type = 'N'; board[0][1].color = 'b';
    board[0][2].type = 'B'; board[0][2].color = 'b';
    board[0][3].type = 'Q'; board[0][3].color = 'b';
    board[0][4].type = 'K'; board[0][4].color = 'b';
    board[0][5].type = 'B'; board[0][5].color = 'b';
    board[0][6].type = 'N'; board[0][6].color = 'b';
    board[0][7].type = 'R'; board[0][7].color = 'b';
    for (j = 0; j < 8; ++j) { board[1][j].type = 'P'; board[1][j].color = 'b'; }

    // ---------- helpers inline via labels and goto-like behavior avoided ----------
    // Vamos agora o loop do menu principal
    while (running) {
        printf("\n=== XADREZ SIMPLIFICADO ===\n");
        printf("Turno: %s\n", (turn == 'w') ? "Brancas" : "Pretas");
        printf("1 - Mostrar tabuleiro\n");
        printf("2 - Novo jogo (reiniciar)\n");
        printf("3 - Mover (formato: e2 e4) \n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        if (!fgets(cmd, sizeof(cmd), stdin)) { clearerr(stdin); continue; }
        int option = atoi(cmd);

        if (option == 1) {
            // Mostrar tabuleiro (com coordenadas)
            printf("   a b c d e f g h\n");
            for (i = 0; i < 8; ++i) {
                printf("%d  ", 8 - i);
                for (j = 0; j < 8; ++j) {
                    if (board[i][j].type == '.') {
                        printf(". ");
                    } else {
                        char c = board[i][j].type;
                        if (board[i][j].color == 'w') c = tolower(c); // brancas em minusculo (opcional)
                        else c = toupper(c); // pretas em maiusculo (opcional)
                        printf("%c ", c);
                    }
                }
                printf(" %d\n", 8 - i);
            }
            printf("   a b c d e f g h\n");
            continue;
        } else if (option == 2) {
            // Reiniciar o jogo: reatribuir posições iniciais
            for (i = 0; i < 8; ++i)
                for (j = 0; j < 8; ++j) {
                    board[i][j].type = '.';
                    board[i][j].color = '.';
                    board[i][j].moved = 0;
                }
            // Branco
            board[7][0].type = 'R'; board[7][0].color = 'w';
            board[7][1].type = 'N'; board[7][1].color = 'w';
            board[7][2].type = 'B'; board[7][2].color = 'w';
            board[7][3].type = 'Q'; board[7][3].color = 'w';
            board[7][4].type = 'K'; board[7][4].color = 'w';
            board[7][5].type = 'B'; board[7][5].color = 'w';
            board[7][6].type = 'N'; board[7][6].color = 'w';
            board[7][7].type = 'R'; board[7][7].color = 'w';
            for (j = 0; j < 8; ++j) { board[6][j].type = 'P'; board[6][j].color = 'w'; }
            // Preto
            board[0][0].type = 'R'; board[0][0].color = 'b';
            board[0][1].type = 'N'; board[0][1].color = 'b';
            board[0][2].type = 'B'; board[0][2].color = 'b';
            board[0][3].type = 'Q'; board[0][3].color = 'b';
            board[0][4].type = 'K'; board[0][4].color = 'b';
            board[0][5].type = 'B'; board[0][5].color = 'b';
            board[0][6].type = 'N'; board[0][6].color = 'b';
            board[0][7].type = 'R'; board[0][7].color = 'b';
            for (j = 0; j < 8; ++j) { board[1][j].type = 'P'; board[1][j].color = 'b'; }
            turn = 'w';
            printf("Novo jogo iniciado.\n");
            continue;
        } else if (option == 3) {
            printf("Digite o movimento (ex: e2 e4) ou 'menu' para voltar: ");
            if (!fgets(cmd, sizeof(cmd), stdin)) { clearerr(stdin); continue; }
            // trim newline
            size_t len = strlen(cmd);
            if (len > 0 && cmd[len-1] == '\n') cmd[len-1] = '\0';
            if (strcasecmp(cmd, "menu") == 0) continue;

            // Parse simples: esperamos algo como "e2 e4"
            char sfrom[8], sto[8];
            if (sscanf(cmd, "%7s %7s", sfrom, sto) != 2) {
                printf("Entrada invalida. Use o formato: e2 e4\n");
                continue;
            }
            // validar formato: letra + numero
            if (strlen(sfrom) < 2 || strlen(sto) < 2) { printf("Formato invalido.\n"); continue; }
            char file_from = tolower(sfrom[0]);
            char rank_from = sfrom[1];
            char file_to = tolower(sto[0]);
            char rank_to = sto[1];
            if (file_from < 'a' || file_from > 'h' || file_to < 'a' || file_to > 'h' ||
                rank_from < '1' || rank_from > '8' || rank_to < '1' || rank_to > '8') {
                printf("Coordenadas fora do tabuleiro. Use a-h e 1-8.\n");
                continue;
            }
            int col_from = file_from - 'a';
            int row_from = 8 - (rank_from - '0'); // row 0 é 8, row 7 é 1
            int col_to = file_to - 'a';
            int row_to = 8 - (rank_to - '0');

            // checar se existe peça na origem
            if (board[row_from][col_from].type == '.') {
                printf("Nao ha peça na casa de origem.\n");
                continue;
            }
            // checar se a peça é do jogador atual
            if (board[row_from][col_from].color != turn) {
                printf("A peça selecionada nao pertence a player atual.\n");
                continue;
            }
            // checar se destino tem peça da mesma cor
            if (board[row_to][col_to].color == turn) {
                printf("Destino ocupado por sua propria peça.\n");
                continue;
            }

            // determinar movimento válido dependendo do tipo
            char ptype = board[row_from][col_from].type;
            char pcolor = board[row_from][col_from].color;
            int dr = row_to - row_from;
            int dc = col_to - col_from;
            int absdr = (dr >= 0) ? dr : -dr;
            int absdc = (dc >= 0) ? dc : -dc;
            int valid = 0;
            int path_clear = 1;

            if (ptype == 'P') {
                // peão
                if (pcolor == 'w') {
                    // brancas se movem para cima (linha decresce)
                    if (dc == 0 && dr == -1 && board[row_to][col_to].type == '.') valid = 1;
                    else if (dc == 0 && dr == -2 && row_from == 6 && board[row_to][col_to].type == '.' && board[row_from-1][col_from].type == '.') valid = 1;
                    else if (absdc == 1 && dr == -1 && board[row_to][col_to].type != '.' && board[row_to][col_to].color == 'b') valid = 1; // captura
                } else {
                    // pretos se movem para baixo (linha incrementa)
                    if (dc == 0 && dr == 1 && board[row_to][col_to].type == '.') valid = 1;
                    else if (dc == 0 && dr == 2 && row_from == 1 && board[row_to][col_to].type == '.' && board[row_from+1][col_from].type == '.') valid = 1;
                    else if (absdc == 1 && dr == 1 && board[row_to][col_to].type != '.' && board[row_to][col_to].color == 'w') valid = 1; // captura
                }
            } else if (ptype == 'R') {
                // torre: move em linhas ou colunas, checar caminho
                if (dr == 0 && dc != 0) {
                    int step = (dc > 0) ? 1 : -1;
                    for (j = col_from + step; j != col_to; j += step)
                        if (board[row_from][j].type != '.') { path_clear = 0; break; }
                    if (path_clear) valid = 1;
                } else if (dc == 0 && dr != 0) {
                    int step = (dr > 0) ? 1 : -1;
                    for (i = row_from + step; i != row_to; i += step)
                        if (board[i][col_from].type != '.') { path_clear = 0; break; }
                    if (path_clear) valid = 1;
                }
            } else if (ptype == 'N') {
                // cavalo: L-shape
                if ((absdr == 2 && absdc == 1) || (absdr == 1 && absdc == 2)) valid = 1;
            } else if (ptype == 'B') {
                // bispo: move diagonais, checar caminho
                if (absdr == absdc && absdr != 0) {
                    int step_r = (dr > 0) ? 1 : -1;
                    int step_c = (dc > 0) ? 1 : -1;
                    int r = row_from + step_r, c = col_from + step_c;
                    while (r != row_to && c != col_to) {
                        if (board[r][c].type != '.') { path_clear = 0; break; }
                        r += step_r; c += step_c;
                    }
                    if (path_clear) valid = 1;
                }
            } else if (ptype == 'Q') {
                // rainha: combina torre + bispo
                if (dr == 0 && dc != 0) {
                    int step = (dc > 0) ? 1 : -1;
                    for (j = col_from + step; j != col_to; j += step)
                        if (board[row_from][j].type != '.') { path_clear = 0; break; }
                    if (path_clear) valid = 1;
                } else if (dc == 0 && dr != 0) {
                    int step = (dr > 0) ? 1 : -1;
                    for (i = row_from + step; i != row_to; i += step)
                        if (board[i][col_from].type != '.') { path_clear = 0; break; }
                    if (path_clear) valid = 1;
                } else if (absdr == absdc && absdr != 0) {
                    int step_r = (dr > 0) ? 1 : -1;
                    int step_c = (dc > 0) ? 1 : -1;
                    int r = row_from + step_r, c = col_from + step_c;
                    while (r != row_to && c != col_to) {
                        if (board[r][c].type != '.') { path_clear = 0; break; }
                        r += step_r; c += step_c;
                    }
                    if (path_clear) valid = 1;
                }
            } else if (ptype == 'K') {
                // rei: um passo em qualquer direção (roque não implementado)
                if (absdr <= 1 && absdc <= 1 && (absdr + absdc) > 0) valid = 1;
            }

            if (!valid) {
                printf("Movimento invalido para a peça %c.\n", ptype);
                continue;
            }

            // Executa o movimento (captura se houver)
            // Salva peça destino para possível desfazer (não implementado aqui)
            Piece movedPiece = board[row_from][col_from]; // struct copy
            board[row_to][col_to] = movedPiece;
            board[row_to][col_to].moved = 1;
            board[row_from][col_from].type = '.';
            board[row_from][col_from].color = '.';
            board[row_from][col_from].moved = 0;

            // Promoção de peão
            if (movedPiece.type == 'P') {
                if (movedPiece.color == 'w' && row_to == 0) {
                    board[row_to][col_to].type = 'Q'; // promove para rainha
                    printf("Peao branco promovido a rainha!\n");
                } else if (movedPiece.color == 'b' && row_to == 7) {
                    board[row_to][col_to].type = 'Q';
                    printf("Peao preto promovido a rainha!\n");
                }
            }

            // Trocar turno
            turn = (turn == 'w') ? 'b' : 'w';
            printf("Movimento executado: %s -> %s\n", sfrom, sto);
            continue;
        } else if (option == 4) {
            running = 0;
            printf("Encerrando o jogo. Ate logo!\n");
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }
    }

    return 0;
}
