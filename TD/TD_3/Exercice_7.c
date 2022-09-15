/*
Ecrire un programme C qui demande un nombre de départ, et qui ensuite affiche les dix
nombres suivants. Par exemple, si l'utilisateur entre le nombre 17, le programme affichera les nombres de 18
à 27
*/


#include <stdio.h>
#include <stdlib.h>
void main() {
    int n,i=1;
    printf("entrer le nombre de depart :");
    scanf("%d",&n);
    while(i<=10){
        printf("%d\n",n+i++);
    }
}
