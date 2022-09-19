#include <stdio.h>
#include <stdlib.h>

void afficher(int P[]){
    P[0]=123;
    printf("%d       %d\n",P[0],P[1]);
}
int main()
{
    int T[10];
    int n = 0;
    T[0]=12;
    T[1]=33;
    afficher(T);
    printf("%d       %d\n",T[0],T[1]);
}
