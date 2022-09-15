#include <stdio.h>
#include <stdlib.h>

char *saisirchaine(){

   char *CH, c;
   int i = 0;
   CH = (char*)malloc(sizeof(char));
   while((c = getchar())!='\n'){
    CH[i]=c;
    i++;
    CH = (char*)realloc(CH, (i+1)*sizeof(char));
   }
   CH[i]='\0';
   return CH;
}

struct personne{
   char *nom;
   char *prenom;
   int num;
};
typedef struct personne str;

int main()
{
    str s;
    printf("nom : ");
    s.nom = saisirchaine();
    printf("prenom : ");
    s.prenom = saisirchaine();
    printf("numero : ");
    scanf("%d",&s.num);
    printf("%s    %s    %d",s.nom ,s.prenom ,s.num );

}
