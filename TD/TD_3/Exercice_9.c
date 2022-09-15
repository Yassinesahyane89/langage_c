/*
Ecrire un programme C qui demande un nombre de départ, et qui ensuite écrit la table de
multiplication de ce nombre, présentée comme suit (cas où l'utilisateur entre le nombre 7) :
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
