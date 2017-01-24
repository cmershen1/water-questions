#include <stdio.h>
#include <stdlib.h>
#define INFINITY 0x3f3f3f3f
int main() {
  char d[200005];//directions of particle
  int p[200005];//positions of particle
  int n,i;
  scanf("%d", &n);
  scanf("%s", d);
  for(i=0;i<n;i++)
    scanf("%d", &p[i]);
  int min=INFINITY;
  for(i=1;i<n;i++) {
    if(d[i-1]=='R' && d[i]=='L') {
      int time=(p[i]-p[i-1])/2;
      if(time<min)
        min=time;
    }
  }
  if(min==INFINITY)
    min=-1;
  printf("%d\n", min);
}
