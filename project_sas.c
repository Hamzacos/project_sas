#include<stdio.h>
#include<string.h>
typedef struct{
    char CIN[10];
    char nom[20];
    char prenom[20];
    float montant;
}Compte;
int num = 0;
/*********************fonction Ajoute *******************/
void ajoute_client(Compte T[])
{
        int i= num;
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
        for(i=num;i<nb+num;i++)
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
    num = num + nb;
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
 /************************Affichage ***********************/
 void affichCompte(Compte T[],int n)
 {
    int c=1;
    for(int i=0;i<n;i++)
    {
        printf("Copmte N%d: \n",c);c++;
        printf("CIN     : %s \n",T[i].CIN);
        printf("Nome    : %s \n",T[i].nom);
        printf("Prenom  : %s \n",T[i].prenom);
        printf("Montant : %.2f \n",T[i].montant);
    }
}
 void triA(Compte T[],int n)
 {
     Compte temp;
     int i,j;
     for(i=0;i<n;i++)
         for(j=0;j<n;j++)
             if(T[i].montant<T[j].montant)
             {
                 temp = T[i];
                 T[i] = T[j];
                 T[j] = temp;
             }
 }
 void triD(Compte T[],int n)
 {
     Compte temp;
     int i,j;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(T[i].montant>T[j].montant)
            {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
 }
 void RtriA(Compte T[])
 {
    Compte temp[20];
    int i, j = 0;
    float nb ;
    printf("enter le chiffre pivot: ");
    scanf("%f",&nb);
    for(i=0;i<num;i++)
    {
      if(T[i].montant >= nb)
      {
        temp[j]=T[i];
        j++;
     } 
    }
      triA(temp,j);
      affichCompte(temp,j);
 }
 void RtriD(Compte T[])
 {
    Compte temp[20];
    int i, j = 0;
    float nb ;
    printf("enter le chiffre pivot: ");
    scanf("%f",&nb);
    for(i=0;i<num;i++)
    {
      if(T[i].montant >= nb)
      {
        temp[j]=T[i];
        j++;
     } 
    }
      triD(temp,j);
      affichCompte(temp,j);
 }
/**************** menu principale *********************/
int main ()
{
    int n,chose,p ;
    Compte T[n];
    int f,a=1;
    while(a)
    {
        puts("                        Menu");
        puts("====================================================");
        puts("1) Ajouter un compte");
        puts("2) Ajouter plusieur compte");
        puts("3) Operation");
        puts("4) Affichage");
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
            break;
            case 4:
            puts("1)Tri Par Ordre Ascendant");
            puts("2) Tri Par Ordre Descendant");
            puts("3) Par Ordre Ascendant ayant un montant supérieur à un chiffre introduit");
             puts("4) Par Ordre Descendant ayant un montant supérieur à un chiffre introduit");
            printf("entrez votre type de tri");
            scanf("%d",&p);
            switch(p)
            {
                case 1:
                triA(T,num);
                affichCompte(T,num);
                break;
                case 2:
                triD(T,num);
                affichCompte(T,num);
                break;
               case 3:
                RtriA(T);
                break;
                case 4:
                RtriD(T);
                break;
            }
            break;
        }
    }
    return 0;
}

