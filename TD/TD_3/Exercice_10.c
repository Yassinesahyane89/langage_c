/*
Ecrire un programme C qui demande un nombre de d�part, et qui calcule la somme des
entiers jusqu�� ce nombre. Par exemple, si l�on entre 5, le programme doit calculer :
1 + 2 + 3 + 4 + 5 = 15
NB : l�affichage doit �tre :
Donner le nombre x : 5
La somme est : 1 + 2 + 3 + 4 + 5 = 15
*/


#include <stdio.h>
#include <stdlib.h>
void main() {
    int n,i,s=0;;
   printf("Donner le nombre x : ");
   scanf("%d",&n);
   for(i=1;i<n;i++){
    printf("%d + ",i);
    s+=i;
   }
   printf("%d = %d",n,s+n);
}
