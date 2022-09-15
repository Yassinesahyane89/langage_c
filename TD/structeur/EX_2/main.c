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
    str *s;
    int n, i;
    printf("n = ");
    scanf("%d",&n);
    getchar();
    s = (str*)malloc(n*sizeof(str));
    for(i=0;i<n;i++){
        printf("\nperssone %d\n",i+1);
        printf("nom : ");
        s[i].nom = saisirchaine();
        printf("prenom : ");
        s[i].prenom = saisirchaine();
        printf("numero : ");
        scanf("%d",&s[i].num);
        getchar();
    }
    for(i=0;i<n;i++){
         printf("%s    %s    %d",s[i].nom ,s[i].prenom ,s[i].num );
    }

}
