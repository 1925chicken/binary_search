#include <stdio.h>

int n;
int k;
int A[100000];
int INF = (int)(1e9);
int Can_Or_Not(int mid){
    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += (A[i] + mid - 1) / mid;
    return sum <= k;
}

int main(){
  int i, lb, ub;
  lb= 0;
  ub = INF;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(Can_Or_Not(mid)){
          ub = mid;
      }else{
          lb = mid;
      }
  }
  printf("%d\n",ub);
  return 0;
}
