#include <stdio.h>
#include <stdlib.h>
int T[10];
int n = 0;
void add(){
    T[n]=1;
    n++;
}
void afficher(){
    printf("%d       %d\n",T[0],T[1]);
}
int main()
{
    T[n];
    n++;
    add();
    afficher();
    printf("%d",n);
}
