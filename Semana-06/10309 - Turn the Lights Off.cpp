#include <stdio.h>
#include <string.h>

char grid[10][10];
int tc[10][10];
int cont;

void interruptor (int x, int y) {
    tc[x][y] = !tc[x][y];

    if (x-1 >= 0) tc[x-1][y] = !tc[x-1][y];
    if (x+1 < 10) tc[x+1][y] = !tc[x+1][y];
    if (y-1 >= 0) tc[x][y-1] = !tc[x][y-1];
    if (y+1 < 10) tc[x][y+1] = !tc[x][y+1];
}

void dfs(int x, int y, int passo) {
    if (y == 10)  x++, y = 0;

    if (passo >= cont) return;

    if (x == 0) {
        dfs(x, y+1, passo);
        interruptor(x, y);
        dfs(x, y+1, passo+1);
        interruptor(x, y);
    } 

    else if (x < 10) {
        if(tc[x-1][y] == 1) {
            interruptor(x, y);
            dfs(x, y+1, passo+1);
            interruptor(x, y);
        } else
            dfs(x, y+1, passo);
    } 

    else {
        int i;
        for (i = 0; i < 10; i++)
            if (tc[x-1][i])
                return;
        if(passo < cont)  cont = passo;
    }
}

int main (void) {
    char nome[50];
    int i, j;

    while (gets(nome)) {
        if (!strcmp(nome, "end"))
            break;

        for (i = 0; i < 10; i++)
            gets(grid[i]);

        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                tc[i][j] = grid[i][j] == 'O';
            }
        }

        cont = 0xffff;
        dfs(0, 0, 0);
        printf("%s %d\n", nome, cont);
    }

    return 0;
}
