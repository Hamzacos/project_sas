#include<stdio.h>
#include<string.h>
typedef struct{
    char CIN[10];
    char nom[20];
    char prenom[20];
    float montant;
}Compte;
/*********************fonction Ajoute *******************/
void ajoute_client(Compte T[])
{
        int i= 0;
        printf("CIN     :");
        scanf("%s",T[i].CIN);
        printf("Nom     :");
        scanf("%s",T[i].nom);
        printf("Prenom  :");
        scanf("%s",T[i].prenom);
        printf("Montant :");
        scanf("%f",&T[i].montant);
        /*printf("CIN     : %s \n",T[i].CIN);
        printf("Nome    : %s \n",T[i].nom);
        printf("Prenom  : %s \n",T[i].prenom);
        printf("Montant : %.2f \n",T[i].montant);*/
}
/*********************fonction plusieur Ajoute *******************/
void ajoute_plusieur_client(Compte T[],int nb)
{
    int i;
        printf("entrez le nombre de compte bancaire");
        scanf("%d",&nb);
        int c=1;
        for(i=0;i<nb;i++)
    {
        printf("Copmte N%d: \n",c);c++;
        printf("CIN     :");
        scanf("%s",T[i].CIN);
        printf("Nom     :");
        scanf("%s",T[i].nom);
        printf("Prenom  :");
        scanf("%s",T[i].prenom);
        printf("Montant :");
        scanf("%f",&T[i].montant);
        /*printf("CIN     : %s \n",T[i].CIN);
        printf("Nome    : %s \n",T[i].nom);
        printf("Prenom  : %s \n",T[i].prenom);
        printf("Montant : %.2f \n",T[i].montant);*/
    }
}
 /********************fonction recherche ****************/
 int recherche(Compte T[],int n)
 {
     char temp[20];
     printf("entrez le numero de CIN");
     scanf("%s",temp);
     for (int i=0;i<n;i++)
     {
         int c;
         c = strcmp(temp,T[i].CIN);
         if (c==0)
         {
             printf("votre compte existe");
             return i;
         }
     }
     printf("votre compte n'exsite pas");
     return -1;
 }
 /*************** fonction Retrait ********************/
 void retrait(Compte T[],int i)
 {
     float some;
     if (i>=0)
     {
       printf("entrez la somme");
       scanf("%f",&some);
       T[i].montant = T[i].montant - some; 
       printf("le solde apres le retrait est:%.2f",T[i].montant);
     }
 }
 /******************** fonction Depot *********************/
 void depot(Compte T[],int i)
 {
     float some;
     if(i>=0)
     {
         printf("entrez la somme");
         scanf("%f",&some);
         T[i].montant += some;
         printf("le solde apres le depot est:%.2f",T[i].montant);
     }
 }
/**************** menu principale *********************/
int main ()
{
    int n,chose ;
    Compte T[n];
    int f,a=1;
    while(a)
    {
        puts("                        Menu");
        puts("====================================================");
        puts("1) Ajouter un compte");
        puts("2) Ajouter plusieur compte");
        puts("3) Operation");
        puts("====================================================");
        printf("entrez votre choix");
        scanf("%d",&f);
        int i = 1;
        switch(f)
        {
           case 1:
           ajoute_client(T);
           break;
           case 2:
           ajoute_plusieur_client(T,n);
           break;
            case 3:
            puts("1) Retrait");
            puts("2) Depot");
            printf("entrez votre operation");
            scanf("%d",&chose);
            switch(chose)
            {
                case 1:
                i = recherche(T,n);
                retrait(T,i);
                break;
                case 2:
                i = recherche(T,n);
                depot(T,i);
                break;
            }
        }
    }
    return 0;
}
