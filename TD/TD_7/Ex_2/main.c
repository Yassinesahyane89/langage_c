/*
Définir une structure de données Heure permettant de représenter une
heure au format

hh/mm/ss, puis écrire les fonctions suivantes :

     1. conversion d'un élément de type Heure en nombre de secondes (entier)
     2. conversion d'un nombre de secondes (entier) en un élément de type Heure
     3. addition de deux éléments de type Heure

*/

#include <stdio.h>
#include <stdlib.h>

struct Heure{
    int H, M, S;
};
typedef struct Heure heure;

int HeureenSecond(heure h){
     int sec;
     sec = h.H*3600 + h.M*60 + h.S;
     return sec;
}

heure SecondHeureen(int s){
     heure X;
     X.H = s/3600;
     s%=3600;
     X.M=s/60;
     X.S=s%60;
     return X;
}

heure addition(heure X, heure Y){
    int XS, YS;
    heure H;
    XS = HeureenSecond(X);
    YS = HeureenSecond(Y);
    H  = SecondHeureen(XS + YS);
    return H;
}

int main()
{
    heure h1, h2, SH;
    printf("donner le temp 1 :");
    scanf("%d %d %d",&h1.H,&h1.M,&h1.S);
    printf("donner le temp 2 :");
    scanf("%d %d %d",&h2.H,&h2.M,&h2.S);

}
