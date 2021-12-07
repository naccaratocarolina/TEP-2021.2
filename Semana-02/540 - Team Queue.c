#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT_SON(i) (2 * i + 1)
#define RIGHT_SON(i) (2 * i + 2)

#define MAX_SIZE 1000
static int pq[MAX_SIZE + 1]; // Priority Queue
static int t; // Quantidade de elementos na PQ

void upheap (int k) { // fix the heap condition violation
  int v;
  v = pq[k];
  pq[0] = INT_MIN;
  while (pq[k/2] >= v) {
    pq[k] = pq[k/2];
    k = k/2;
  }
  pq[k] = v;
}

void downheap (int k) {
  int j, v;
  v = pq[k];
  while (k <= t/2) {
    j = k + k;
    if (j < t && pq[j] > pq[j + 1]) j++;
    if (v <= pq[j]) break;
    pq[k] = pq[j]; k = j;
  }
  pq[k] = v;
}

void enqueue (int v) {
  pq[++t] = v;
  upheap(t);
}

int dequeue () {
  int v = pq[1];
  pq[1] = pq[t--];
  downheap(1);
  return v;
}

int main (int argc, char *argv[]) {
  int nteams; // numero de times
  int scenario;

  scenario = 1;
  do { // loop principal
    scanf("%d", &nteams); // armazena o numero de times
    
    if (nteams == 0) break; // condicao de parada
    
    printf("Scenario #%d\n", scenario);

    // loop de comandos
    char command[256];
    do {
      scanf("%s", command);

      if (strcmp(command, "ENQUEUE") == 0) {
        int v;
        scanf("%d", &v);
        enqueue(v);
      }
      else if (strcmp(command, "DEQUEUE") == 0)
        printf("%d\n", dequeue());
    } while (strcmp(command, "STOP") != 0);

    scenario++;
    puts("");
  } while (nteams != 0);

  printf("\n");

  return 0;
}
