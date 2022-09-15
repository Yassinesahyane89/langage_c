#include <stdio.h>
#include <stdlib.h>
void main() {
    int a , b, n;
   do{
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    printf("entrer un nombre entre %d est %d  : ",a,b);
    scanf("%d",&n);

   }while(n<a || n>b);
   printf("bravo!!!!!!");
}
