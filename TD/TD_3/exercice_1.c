#include <stdio.h>
#include <stdlib.h>

void main(){
  int n,i,*p,a;
  printf("donner nbrs de donnes stoke");
  scanf("%d",&n);
  p=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    printf("entrer nombre %d : ",i+1);
    scanf("%d",p+i);
  }
  for(i=0;i<n;i++){
    printf("nombre %d : %d\n",i+1,*(p+i));
  }
}
