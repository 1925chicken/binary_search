#include <stdio.h>
#include <math.h>
int n;
int k;
int A[100000];
int INF = (int)1e9 + 1;

int Can_or_not(int len){
    unsigned int res = 0;
    for(int i = 0; i < n; i++){
        res += A[i] / len;
    }
    return res >= k;
}

int main(){
  int i, lb = 0, ub = INF;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(Can_or_not(mid) == 1) lb = mid;
      else ub = mid;
  }
  printf("%d\n",lb);
  return 0;
}
