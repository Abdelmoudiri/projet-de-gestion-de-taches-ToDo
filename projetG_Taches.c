#include<stdio.h>
#include<string.h>
#include <windows.h>
#include<stdbool.h>
bool find=false;
int i,j,count=0;
typedef struct{
int jour,mois;
int anne;
}Date;
typedef struct {
int id;
char titre[100],description[100];
Date deadline;
int statu;
}Tache;
int main()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    Tache taches[100],tem;
    int x;
    int choix3;
    int choix;
    do{

        printf("Choisissez un chiffre :\n");
        printf("1. Ajouter .\n");
        printf("2. Afficher .\n");
        printf("3. Rechercher . \n");
        printf("4. modifier. \n");
        printf("5. Supprimer . \n");
        printf("6. Quitter\n");
        scanf("%d", &choix);

    switch(choix) {
        case 1:     printf("Saisir le id du tache : ");
                    scanf("%d",&taches[i].id);

                    printf("Saisir titre : ");
                    scanf(" %[^\n]s",taches[count].titre);

                    printf("Saisir la description : ");
                    scanf(" %[^\n]s",taches[count].description);

                    printf("Saisir jour : ");
                    scanf("%d",&taches[count].deadline.jour);

                    printf("Saisir la mois: ");
                     scanf("%d",&taches[count].deadline.mois);

                    printf("Saisir l annee : ");
                     scanf("%d",&taches[count].deadline.anne);

                    printf("Saisir la statu :");
                    scanf("%d",&taches[count].statu);
                    count++;
                    break;
       case 2 :
                     printf("1 : pour tri en alpha  \n2 : pour tri en deadline \n3 : pour tri en deadline est dans 3 jours ou moins ");
                     int choix2;
                     scanf("%d",&choix2);
                     switch(choix2)
                     {
                         case 1:
                            for(i=0;i<count;i++)
                            {
                                for(j=0;j<count-i-1;j++)
                                {
                                    if(strcmp(taches[j].titre,taches[j+1].titre)>0){
                                        tem=taches[j];
                                        taches[j]=taches[j+1];
                                        taches[j+1]=tem;
                                    }
                                }
                            }
                            for(i=0;i<count;i++)
                            {
                                printf("%d | %s | %s | %d/%d/%d | %d \n",taches[i].id,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.anne,taches[i].statu);

                            }
                            break;
                         case 2:
                                    for(i=0;i<count;i++)
                                    {
                                        for(j=0;j<count-i-1;j++)
                                        {
                                            if(taches[j].deadline.jour > taches[j+1].deadline.jour){
                                                tem=taches[j];
                                                taches[j]=taches[j+1];
                                                taches[j+1]=tem;
                                            }
                                        }
                                    }
                                    for(i=0;i<count;i++)
                                    {
                                        printf("%d | %s | %s | %d/%d/%d | %d \n",taches[i].id,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[count].deadline.anne,taches[i].statu);
                                    }
                                    break;
                            case 3:
                                    for(i=0;i<count;i++){
                                    if(st.wDay-taches[i].deadline.jour<=3 && st.wDay-taches[i].deadline.jour>=0)
                                    printf("%d | %s | %s | %d/%d/%d | %d \n",taches[i].id,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.anne,taches[i].statu);
                                    }
                                    }
                                    break;
            case 4:
                    printf("1 : pour modifier description  \n2 : pour modifier statu \n3 : pour modifier le deadline ");
                    scanf("%d",&choix3);
                    switch(choix3){
                        case 1:
                                printf("entrer Id tu veux ");
                                scanf("%d",&x);
                                for(i=0;i<count;i++){

                                    if(taches[i].id==x)
                                    {
                                        printf("elntrer la nouvelle desciption :");
                                        scanf(" %[^\n]s",taches[i].description);
                                        printf("changée avec succes :");
                                        find=true;
                                    }
                                }
                                if(!find)printf(" id introuvable \n ");
                                break;
                        case 2:
                                printf("entrer Id tu veux ");
                                scanf("%d",&x);
                                for(i=0;i<count;i++){

                                    if(taches[i].id==x)
                                    {
                                        printf("elntrer la nouvelle statu :");
                                        scanf("%d",&taches[i].statu);
                                        find=true;
                                    }
                                }
                                 if(find==false)printf(" id introuvable \n ");
                                break;
                        case 3:
                                printf("entrer Id tu veux ");
                                scanf("%d",&x);
                                for(i=0;i<count;i++){

                                    if(taches[i].id==x)
                                    {
                                        printf("elntrer la nouvelle dea :");
                                        scanf("%d",taches[i].deadline.jour);
                                        find=true;
                                        break;
                                    }
                                    break;
                                }
                                if(!find)printf(" id introuvable \n ");
                                break;
            }
    }
     }while(choix!=0);
   return 0;
}
