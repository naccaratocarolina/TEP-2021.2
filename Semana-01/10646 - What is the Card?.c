#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CARDS 52

bool done[NUM_CARDS];
char card[NUM_CARDS][3];

int main (void) {
  int n;
  int c, i, j, pos;
  
  scanf("%d", &n);

  for (c=1; c<=n; ++c) {
    for (i=0; i<NUM_CARDS; ++i) 
      scanf("%s", card[i]);

    memset(done, false, sizeof(done));
    
    int Y = 0;

    for (i=0, pos=26; i<3; ++i) {
      int X = (card[pos][0] >= '2' && card[pos][0] <= '9'? card[pos][0] - '0' : 10);
      Y += X;

      done[pos] = true;
      --pos;

      for (j=0; j<10-X; ++j) {
        done[pos] = true;
        --pos;
      }
    }

    printf("Case %d: ", c);

    for (i=0, j=0;;++i) {
      if (!done[i]) ++j;

      if (j == Y) {
        puts(card[i]);
        break;
      }
    }
  }

  return 0;
}
