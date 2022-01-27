#include<stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

#define tam 12
char grid[tam][tam], nome[20];
int min;

int main(void) {
	int i, j;

	freopen("input.txt", "r", stdin);
 
	while (scanf("%s", nome)){
		if(!strcmp(nome, "end")) break;

		else if (nome[5] == 'f') min = 0;

		else if (nome[5] == 'n') min = 44;

    for (i = 0; i < 10; i++)
	  	scanf("%s", grid[i]);
	}
}
