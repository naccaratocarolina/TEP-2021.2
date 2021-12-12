#include <stdio.h>

int stk[1048576], sum[1048576];

int main(void) {
  int input;
  char c;

  while(scanf("%d%c", &input, &c) == 2) {
      int idx = -1, flag = 0;
      stk[++idx] = input, sum[idx] = 0;
        
      if(input > 0) flag = 1;
        
      while(c != '\n' && scanf("%d%c", &input, &c) == 2) {
          if(idx >= 0) {
              if (input < 0) {
                  sum[idx] += -input;
                  stk[++idx] = input, sum[idx] = 0;
              } 

              else {
                  if (stk[idx] == -input) {
                      if (sum[idx] >= input)
                          flag = 1;
                      idx--;
                  } else
                      flag = 1;
              }
          } else {
              if(input > 0) 
                flag = 1;

              stk[++idx] = input, sum[idx] = 0;
          }
      }

      if(idx >= 0)
        flag = 1;

      if(flag)
        puts(":-( Try again.");

      else
        puts(":-) Matrioshka!");
  }
  return 0;
}
