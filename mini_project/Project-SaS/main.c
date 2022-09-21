#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

// déclaration de la structure Produit
struct Produit{
   int code;
   char *nom;
   int quantite;
   float prixTTC;
   float prix;
};
typedef struct Produit produit;

struct date{
   int annee;
   int mois;
   int jours;
};
typedef struct date Date;

struct produitAcheter{
   int code;
   float prixTTC;
   int quantite;
   float prixTotal;
   Date date;
};
typedef struct produitAcheter PA;

// fonction pour saisir un chaîne de caractère
char *saisierChain(){
   int i=0;
   char *CH, c;
   CH = malloc(sizeof(char));
   while((c=getchar())!='\n'){
    CH[i]=c;
    i++;
    CH = realloc(CH , (i+1)*sizeof(char));
   }
   CH[i]='\0';
   return CH;

}

// fonction pour afficher les produit
void afficher(int size , produit *T){
    int i ;
    printf("  |     code      |      Nom      |    Quantite   |     Prix      |    PrixTTC    |\n");
    printf("  |_______________|_______________|_______________|_______________|_______________|\n");
    for( i = 0 ; i < size ; i++){
        printf("  |%15d|%15s|%15d|%15.2f|%15.2f|\n",T[i].code, T[i].nom , T[i].quantite, T[i].prix, T[i].prixTTC);
    }
    printf("  |_______________|_______________|_______________|_______________|_______________|\n");
}

// fonction pour afficher les Achter
void afficherProduitAcheter(int size , PA *T){
    printf("%d\n\n",size);
    int i ;
    printf("  |     code      |    prixTTC    |    Quantite   |   PrixTotal   |     date      |\n");
    printf("  |_______________|_______________|_______________|_______________|_______________|\n");
    for( i = 0 ; i < size ; i++){
        printf("  |%15d|%15.2f|%15d|%15.2f|   %2d-%2d-%4d  |\n",T[i].code, T[i].prixTTC , T[i].quantite, T[i].prixTotal , T[i].date.jours,T[i].date.mois,T[i].date.annee);
    }
    printf("  |_______________|_______________|_______________|_______________|_______________|\n");
}

// fonction Ajouter un nouveau produit:
produit *ajouterProduit(int *size,produit *T){
   int i=0,n;
   n = (*size)++;
   T = realloc(T,(*size)*sizeof(produit));
   getchar();
   if(n ==  0)
   {
       T[0].code=1;
   }else{
       T[n].code=T[n-1].code+1;
   }

   printf("   nom de produit :");
   T[n].nom=saisierChain();

   printf("   quantite de produit :");
   scanf("%d",&T[n].quantite);

   printf("   prix de produit :");
   scanf("%f",&T[n].prix);

   T[n].prixTTC=T[n].prix*1.15;

   return T;
}

// fonction Ajouter plusieurs nouveau produit:
void *ajouterPlusieurProduit(int *size,produit *T){
    system("cls");
    printf("============  Ajouter plusieurs nouveaux produits ============");
    int n,i;
    printf("\n combien produit vous voulez ajouter : ");
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++){
        printf("\n Produit %d\n",i+1);
        T=ajouterProduit(size,T);
    }
  return T;
}

//lister tous les produits selon l’ordre alphabétique  croissant du nom.
void ListLordreAlphabetique(int size , produit *T){
    system("cls");
    printf("======            list produits l'ordre alphabetique  croissant du nom            ======\n\n");
    int i, j;
    produit p;
    for(i = 0 ; i < size ; i++){
        for(j = i+1 ; j < size ; j++){
            if((strcmp(T[i].nom,T[j].nom))==1)
            {
                p = T[i];
                T[i]=T[j];
                T[j]  = p;
            }
        }
    }
    afficher(size,T);
}

//lister tous les produits selon l’ordre  décroissant du prix.
void ListLordrePrix(int size,produit *T){
    system("cls");
    printf("======            list produits l'ordre decroissant du prix            ======\n\n");
    int i, j;
    produit p;
    for(i = 0 ; i < size ; i++){
        for(j = i+1 ; j < size ; j++){
            if(T[i].prix<T[j].prix)
            {
                p = T[i];
                T[i] = T[j];
                T[j]  = p;
            }
        }
    }
    afficher(size,T);
}

//fonction Lister tous les produits (Nom, prix, prix TTC)
void listProduit(int size,produit *T){
    system("cls");
    printf("======            Liste tous les produit             ======\n");
    int n;
    printf("    1 - List les produits selon lordre alphabetique croissant du nom.\n");
    printf("    2 - List les produits selon lordre  decroissant du prix.\n");
    printf("      entrer votre choix de type de list:");
    scanf("%d",&n);
    switch(n){
       case 1 : ListLordreAlphabetique(size,T);
                break;
       case 2 : ListLordrePrix(size,T);
                break;
    }


}
// fonction recherch par code
int recherchParCode(int code, int size, produit *T){
    int  i;
    for(i = 0 ; i < size ; i++){
        if(T[i].code == code)
        {
            return i;
        }
    }
  return -1;
}

// fonction qui obtenir date dans mon systèm
void getDate(Date *d){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  d->annee = tm.tm_year + 1900;
  d->mois = tm.tm_mon + 1;
  d->jours = tm.tm_mday;
}

// fonction Acheter produit
PA *acheterProduit(int *size, produit *T, PA *A, int *sizeA){
   system("cls");
   printf("======            Acheter produit             ======\n");
    int n,q, i, m=(*sizeA);

    afficher(*size , T);

    printf("\n   entrez le code du produit que vous souhaitez acheter : ");
    scanf("%d",&n);

    while(recherchParCode(n,*size,T)==-1){
        char c;
        getchar();

        printf("Nous n'avons pas cette produit veuillez enter un autre code ou quite  (Y/Q) : ");
        scanf("%c",&c);

        if(c == 'Q'){
            return A;
        }

        printf("\n   entrez le code du produit que vous souhaitez acheter : ");
        scanf("%d",&n);

    }

    printf("\n   entrez la quantite que vous souhaitez acheter : ");
    scanf("%d",&q);

    while(q>T[n-1].quantite){
        printf("Nous n'avons pas cette quantite en stock veuillez entrer un autre quantite : ");
        scanf("%d",&q);
    }
    (*sizeA)++;
    A = realloc(A,(m+1)*sizeof(PA));

    for(i = 0 ; i < (*size) ; i++){
        if(n ==  T[i].code){
            T[i].quantite-=q;
            A[m].code=T[i].code;
            A[m].quantite=q;
            A[m].prixTTC=T[i].prixTTC;
            A[m].prixTotal=T[i].prixTTC*q;
            getDate(&A[m].date);
            break;
        }
    }
  return A;
}

//Rechercher les produits par Code
void recherchProduitCode(int size, produit *T){
    system("cls");
    printf("======            Rechercher les produits par Code            ======\n");

    int n, k=0 , m=0, i;
    produit *V;
    V = malloc(sizeof(produit));

    printf("entrer le code de produits :");
    scanf("%d",&n);

    if(recherchParCode(n,size,T)!=-1){
            V[k]=T[i];
            k++;
            V = realloc(V,(k+1)*sizeof(produit));
            m=1;
    }

    if(m==1)
        afficher(k,V);
    else
        printf("\n    Nous n'avons pas aucun produit en stock avec ce code  : \n");
}

//Rechercher les produits par Quantite
void recherchProduitQuantite(int size, produit *T){
    system("cls");
    printf("======            Rechercher les produits par Quantite            ======\n");

    int n, k=0, m = 0, i;
    produit *V;
    V = malloc(sizeof(produit));

    printf("entrer la quantite de produits :");
    scanf("%d",&n);

    for(i = 0 ; i < size ; i++){
        if(T[i].quantite == n){
            V[k]=T[i];
            k++;
            m = 1;
            V = realloc(V,(k+1)*sizeof(produit));
        }
    }

    if(m==1)
        afficher(k,V);
    else
        printf("\n    Nous n'avons pas aucun produit en stock avec ce quantite  : \n");
}

//Rechercher les produit
void recherchProduit(int size, produit *T){
   system("cls");
   printf("======            Rechercher les produits            ======\n");
   int n;
   printf("   1 - Rechercher les produits par Code :\n");
   printf("   2 - Rechercher les produits par Quantite :\n");
   printf("\n     entrer votre choix :");
   scanf("%d",&n);
   switch(n){
     case 1 : recherchProduitCode(size,T);
              break;
     case 2 : recherchProduitQuantite(size,T);
              break;
   }
}

// Etat du stock
void etatStock(int size, produit *T){
    system("cls");
    printf("   ======            Etat du stock            ======\n");

    int i, m = 0 , k = 0;
    produit *V;
    V = malloc(sizeof(produit));

    for( i = 0 ; i < size ; i++){
       if(T[i].quantite<3)
         {
            V[k]=T[i];
            k++;
            m = 1;
            V = realloc(V,(k+1)*sizeof(produit));
         }
    }

    if(m==1)
        afficher(k,V);
    else
        printf("\n    Nous n'avons pas aucun produit en stock avec quantite  inferieur 3 : \n");
}

// Alimenter le stock
void alimenterStock(int size, produit *T){
    system("cls");
    printf("======            Alimenter le stock            ======\n");
    int i, n, m;

    printf("entrer la code de produit :");
    scanf("%d",&n);

    int index = recherchParCode(n , size , T);
    if(index==-1)
    {
        printf("\n    Nous n'avons pas aucun produit en stock avec ce code  : \n");
    }else
    {
        printf("entrer la quantite de produit :");
        scanf("%d",&m);

         T[index].quantite+=m;
    }
}

// fonction Supprimer les produits par Code
void supprimerProduit(int *size, produit *T){
    system("cls");
    printf("======            Supprimer les produits par Code            ======\n");
    int i, n, m;

    printf("entrer la code de produit :");
    scanf("%d",&n);

    int index = recherchParCode(n , *size , T);
    if(index==-1)
    {
        printf("\n    Nous n'avons pas aucun produit en stock avec ce code pour le supprimer : \n");
    }else{

        for(i = index  ; i < *size ; i++){
           T[i]=T[i+1];
        }
        T = realloc(T,(--(*size))*sizeof(produit));
    }
}

// fonction Statistique de vente
void statiqueVente(int sizeA, PA *A){
    system("cls");
    Date d;
    getDate(&d);
    printf("======            Statistique de vente:  %d - %d - %d             ======\n",d.jours,d.mois,d.annee);

    int i ,n=0 , q=0;
    float s, max ,min;

    max = A[0].prixTTC;
    min = A[0].prixTTC;

    for(i = 0 ; i < sizeA ; i++){
      if(A[i].date.annee == d.annee && A[i].date.mois == d.mois && A[i].date.jours == d.jours )
          {
              s+=A[i].prixTotal;
              q+=A[i].quantite;
              n++;
          }
      if(A[i].prixTTC>max)
      {
          max = A[i].prixTotal;
      }
      if(A[i].prixTTC<min)
      {
          min = A[i].prixTotal;
      }
    }
    printf("total des prix des produits vendus   :%.2f\n",s);
    printf("moyenne des prix des produits vendus :%.2f\n",(float)s/(float)q);
    printf("Max des prix des produits vendus     :%.2f\n",max);
    printf("Min des prix des produits vendus     :%.2f\n",min);
}

int main()
{

    //declaration
    int n, size=0, i, sizeA=0;
    produit *T;
    PA *A;
    char choix;

    // Allocation dynamique de tableau
    T=malloc(sizeof(produit));
    A=malloc(sizeof(PA));

    while(choix != 'N'){
    printf("      ================Gestion de Pharmacie================\n\n");
    //Menu
    printf("   1  - Ajouter un nouveaux produit :\n");
    printf("   2  - Ajouter plusieur nouveaux produit :\n");
    printf("   3  - Afficher tableau de produit :\n");
    printf("   4  - List tous les produits :\n");
    printf("   5  - Acheter produit :\n");
    printf("   6  - Recherch les produit \n");
    printf("   7  - Etat de stock \n");
    printf("   8  - Alimenter le stock \n");
    printf("   9  - Supprimer les produit \n");
    printf("   10 - Statique de vente \n");
    printf("   11 - Afficher tableau de produit Acheter :\n\n");

    //choix
    printf("     entrer votre choix :");
    scanf("%d",&n);
    printf("\n");

    //Switch
    switch(n){
      case 1: system("cls");
              printf("======            Ajouter un nouveau produit            ======\n");
              T=ajouterProduit(&size,T);
              break;
      case 2 : T=ajouterPlusieurProduit(&size,T);
              break;
      case 3 : afficher(size, T);
              break;
      case 4 : listProduit(size,T);
              break;
      case 5 : A=acheterProduit(&size,T,A,&sizeA);
              break;
      case 6 : recherchProduit(size,T);
              break;
      case 7 : etatStock(size,T);
              break;
      case 8 : alimenterStock(size,T);
              break;
      case 9 : supprimerProduit(&size,T);
              break;
      case 10: statiqueVente(sizeA,A);
              break;
      case 11: afficherProduitAcheter(sizeA,A);
              break;

    }
    getchar();
    printf("\n\n   voulez-vous continuer l'opération (Y/N) :");
    scanf("%c",&choix);
    system("cls");
    printf("\n\n");

 }

}
