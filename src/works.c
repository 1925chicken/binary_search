#include <stdio.h>

int n;
int k;
int A[100000];
int Can_or_not(int x){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(A[i] > x) return 0;
        else if(sum + A[i] <= x) sum += A[i];
        else{
            cnt++;
            sum = A[i];
        }
    }
    return (cnt <= k ? 1 : 0);
}
int main(){
  int i, lb = 0, ub = (int)1e9;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
      int mid= (lb + ub) / 2;
      if(Can_or_not(mid) == 1) ub = mid;
      else lb = mid;
  }
  printf("%d\n",ub);
  return 0;
}
