/*
Ecrire un programme C qui demande un nombre de d�part, et qui ensuite �crit la table de
multiplication de ce nombre, pr�sent�e comme suit (cas o� l'utilisateur entre le nombre 7) :
*/


#include <stdio.h>
#include <stdlib.h>
void main() {
    int n,i;
   printf("entrer un nombre n: ");
   scanf("%d",&n);
   for(i=1;i<=10;i++){
    printf("%2d x %2d = %2d\n",n,i,n*i);
   }
}
