#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// déclaration de la structure Produit
struct Produit{
   int code;
   char *nom;
   int quantite;
   int prix;
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
   char *nom;
   int prix;
   float prixTTC;
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
    printf("  |     code      |      Nom      |    Quantite   |     Prix      |\n");
    printf("  |_______________|_______________|_______________|_______________|\n");
    for( i = 0 ; i < size ; i++){
        printf("  |%15d|%15s|%15d|%15d|\n",T[i].code, T[i].nom , T[i].prix , T[i].quantite);
    }
    printf("  |_______________|_______________|_______________|_______________|\n");
}

// fonction pour afficher les Achter
void afficherProduitAcheter(int size , PA *T){
    printf("%d\n\n",size);
    int i ;
    printf("  |     code      |     Prix      |    prixTTC    |     date      |\n");
    printf("  |_______________|_______________|_______________|_______________|\n");
    for( i = 0 ; i < size ; i++){
        printf("  |%15d|%15d|%15f|   %2d-%2d-%2d    |\n",T[i].code, T[i].prix ,T[i].prixTTC ,T[i].date.jours,T[i].date.mois,T[i].date.annee);
    }
    printf("  |_______________|_______________|_______________|_______________|\n");
}

// fonction Ajouter un nouveau produit:
produit *ajouterProduit(int *size,produit *T){
   int i=0,n;
   n = (*size)++;
   T = realloc(T,(*size)*sizeof(produit));
   getchar();
   printf("   code de produit :");
   scanf("%d",&T[n].code);
   getchar();

   printf("   nom de produit :");
   T[n].nom=saisierChain();

   printf("   quantite de produit :");
   scanf("%d",&T[n].quantite);

   printf("   prix de produit :");
   scanf("%d",&T[n].prix);
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
ListLordreAlphabetique(int *size,produit *T){
    int i, j;
    produit p;
    for(i = 0 ; i < *size ; i++){
            for(j = i+1 ; j < *size ; j++){
                if((strcmp(T[i].nom,T[j].nom))==1)
                {
                    p = T[i];
                    T[i]=T[j];
                    T[j]  = p;
                }
            }
    }
    for(i = 0 ; i < *size ; i++){
        printf("%s    %d     %f\n",T[i].nom,T[i].prix,T[i].prix*1.5);
    }
}

//lister tous les produits selon l’ordre  décroissant du prix.
ListLordrePrix(int *size,produit *T){
    int i, j;
    produit p;
    for(i = 0 ; i < *size ; i++){
            for(j = i+1 ; j < *size ; j++){
                if(T[i].prix<T[j].prix)
                {
                    p = T[i];
                    T[i]=T[j];
                    T[j]  = p;
                }
            }
    }
    for(i = 0 ; i < *size ; i++){
        printf("%s    %d     %f\n",T[i].nom,T[i].prix,T[i].prix*1.5);
    }
}

//fonction Lister tous les produits (Nom, prix, prix TTC)
void listProduit(int *size,produit *T){
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

// fonction Acheter produit
PA *acheterProduit(int *size, produit *T, PA *A, int *sizeA){
   system("cls");
   printf("======            Acheter produit             ======\n");
    printf("*sizeA=%d\n",*sizeA);
    int n, i, m=(*sizeA)++;
    printf("*sizeA=%d\n",*sizeA);
    printf("m=%d\n",m);
    A = realloc(A,(m+1)*sizeof(PA));
    afficher(*size , T);
    printf("\n   entrez le code du produit que vous souhaitez acheter : ");
    scanf("%d",&n);
    for(i = 0 ; i < (*size) ; i++){
        if(n ==  T[i].code){
            printf(" T   %d     %s      %d\n",T[i].code,T[i].nom,T[i].prix);
            printf("%d\n",T[i].quantite);A
            T[i].quantite-=1;
            printf("%d\n",T[i].quantite);
            A[m].code=T[i].code;
            A[m].nom=T[i].nom;
            A[m].prix=T[i].prix;
            A[m].prixTTC=T[i].prix * 1.15;
            getDate(&A[m].date);
            printf("A    %d     %s      %d\n",A[m].code,A[m].nom,A[m].prix);
            break;
        }

    }
  return A;
}

//Enregistrer produit Achter
void  enregProduitAcheter(int i, produit *T,PA *A, int *sizeA){
    int n = *sizeA;
//    Date d = getDate();
    A[n].code=T[i].code;
    A[n].nom=T[i].nom;
    A[n].prix=T[i].prix;
    A[n].prixTTC=T[i].prix * 1.15;
    getDate(&A[n].date);
}

// fonction qui obtenir date dans mon systèm
void getDate(Date *d){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  d->annee = tm.tm_year + 1900;
  d->mois = tm.tm_mon + 1;
  d->jours = tm.tm_mday;
}


//Rechercher les produit
void recherchProduit(int *size, produit *T){
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

//Rechercher les produits par Code
void recherchProduitCode(int *size, produit *T){
    system("cls");
    printf("======            Rechercher les produits par Code            ======\n");
    int n, k=0, i;
    printf("entrer le code de produits :");
    scanf("%d",&n);
    for(i = 0 ; i < *size ; i++){
        if(T[i].code == n){
            k++;
            printf(" %d   %s   %d    %d\n",T[i].code,T[i].nom,T[i].quantite,T[i].prix);
        }
    }
    if(k == 0){
        printf("error!! il n'y a aucun produit avec ce code\n");
    }

}

//Rechercher les produits par Quantite
void recherchProduitQuantite(int *size, produit *T){
    system("cls");
    printf("======            Rechercher les produits par Quantite            ======\n");
    int n, k=0, i;
    printf("entrer la quantite de produits :");
    scanf("%d",&n);
    for(i = 0 ; i < *size ; i++){
        if(T[i].quantite == n){
            k++;
            printf(" %d   %s   %d    %d\n",T[i].code,T[i].nom,T[i].quantite,T[i].prix);
        }
    }
    if(k == 0){
        printf("error!! il n'y a aucun produit avec ce Quantité\n");
    }

}

// Etat du stock
void etatStock(int *size, produit *T){
    system("cls");
    printf("======            Etat du stock            ======\n");
    int i;
    for(i = 0 ; i < *size ; i++){
        if(T[i].quantite<3){
             printf(" %d   %s   %d    %d\n",T[i].code,T[i].nom,T[i].quantite,T[i].prix);
        }
    }
}

// Alimenter le stock
void alimenterStock(int *size, produit *T){
    system("cls");
    printf("======            Alimenter le stock            ======\n");
    int i, n, m;
    printf("entrer la code de produit :");
    scanf("%d",&n);
    printf("entrer la quantite de produit :");
    scanf("%d",&m);
    for(i = 0 ; i < *size ; i++){
        if(T[i].code == n){
             T[i].quantite+=m;
        }
    }
}

// fonction Supprimer les produits par Code
void supprimerProduit(int *size, produit *T){
  system("cls");
  printf("======            Supprimer les produits par Code            ======\n");
  int i, n, m;
  printf("entrer la code de produit :");
  scanf("%d",&n);
   for(i = 0 ; i < *size ; i++){
        if(T[i].code == n){
             m=i;
             break;
        }
    }
    for(i = m  ; i < *size ; i++){
       T[i]=T[i+1];
    }

    *size = (*size) -1;

}

// fonction Statistique de vente
statiqueVente(int *sizeA, PA *A){
    system("cls");
    Date d;
    getDate(&d);
    printf("======            Statistique de vente:  %d - %d - %d             ======\n",d.jours,d.mois,d.annee);
    int n=0;
    int i , max ,min ;
    float s;
    max = A[0].prix;
    min = A[0].prix;
    for(i = 0 ; i < *sizeA ; i++){
      if(A[i].date.annee == d.annee && A[i].date.mois == d.mois && A[i].date.jours == d.jours )
          {
              s+=A[i].prix;
              n++;
          }
      if(A[i].prix>max)
      {
          max = A[i].prix;
      }
      if(A[i].prix<min)
      {
          min = A[i].prix;
      }
    }
    printf("total des prix des produits vendus   :%d\n",s);
    printf("moyenne des prix des produits vendus :%f\n",(float)s/(float)n);
    printf("Max des prix des produits vendus     :%d\n",max);
    printf("Min des prix des produits vendus     :%d\n",min);
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
    printf("   1 - Ajouter un nouveaux produit :\n");
    printf("   2 - Ajouter plusieur nouveaux produit :\n");
    printf("   3 - Afficher tableau de produit :\n");
    printf("   4 - List tous les produits :\n");
    printf("   5 - Acheter produit :\n");
    printf("   6 - Recherch les produit \n");
    printf("   7 - Etat de stock \n");
    printf("   8 - Alimenter le stock \n");
    printf("   9 - Supprimer les produit \n");
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
      case 2: T=ajouterPlusieurProduit(&size,T);
              break;
      case 3: afficher(size, T);
              break;
      case 4: listProduit(&size,T);
              break;
      case 5: A=acheterProduit(&size,T,A,&sizeA);
              break;
      case 6: recherchProduit(&size,T);
              break;
      case 7: etatStock(&size,T);
              break;
      case 8: alimenterStock(&size,T);
              break;
      case 9: supprimerProduit(&size,T);
              break;
      case 10: statiqueVente(&sizeA,A);
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
