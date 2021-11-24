#include<stdio.h>
#include<stdlib.h>

// Tamanho maximo da string
#define MAX_LENGHT 128

// Pilha de caracteres
char pilha[MAX_LENGHT];

// Quantidade de elementos na pilha
int t;

/*
 * Inicializa a estrutura da pilha e a variavel
 * auciliar de controle do tamanho da pilha. Note
 * que t corresponde ao numero de elementos presentes
 * na pilha, de forma que se t = 0, a pilha esta vazia;
 * Se t = MAX_LENGHT, a pilha esta cheia.
 */
void inicializaPilha (void) {
  t = 0;
}

/*
 * Empilha um novo elemento no inicio da pilha.
 */
void empilha (char c) {
  pilha[t++] = c;
}

/*
 * Desempilha o ultimo caractere na pilha.
 *
 * @return caractere removido da pilha.
 */
char desempilha (void) {
  return pilha[--t];
}

/*
 * Verifica se a pilha esta vazia.
 *
 * @return 1 se a pilha estiver vazia, 0 c.c.
 */
int pilhaVazia (void) {
  return t <= 0;
}

/*
 * Verifica se a sequencia esta bem formada.
 *
 * @return 1 se a pilha estiver vazia, 0 c.c.
 */
int stringBemFormada (char s[]) {
  // Inicializa a pilha
  inicializaPilha();

  // Percorre a string de entrada
  for (int i=0; s[i]!='\n'; ++i) {
    char c;

    switch (s[i]) {
      case ')':
        if (pilhaVazia()) return 0;
        c = desempilha();
        if (c != '(') return 0;
        break;
      
      case ']':
        if (pilhaVazia()) return 0;
        c = desempilha();
        if (c != '[') return 0;
        break;

      default:
        empilha(s[i]);
    }
  }

  return pilhaVazia();
}

int main (int argc, char *argv[]) {
  int n; // quantidade de linhas a serem lidas
 
  // Le a quantidade de linhas
  scanf("%d", &n);
  getc(stdin);

  // Le as demais linhas do arquivo de entrada
  while (n--) {
    char tmp[MAX_LENGHT]={0x0};
    fgets(tmp, sizeof(tmp), stdin);

    if (!stringBemFormada(tmp)) printf("No\n");
    else printf("Yes\n");  
  }

  printf("\n");

  return 0;
}
