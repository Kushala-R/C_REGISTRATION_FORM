#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team
{
    char team_name[25];
    char leader_name[25];
    int number;
    int Registration_ID;
    struct team *link;
};

typedef struct team NODE;
NODE *start=NULL;


void New_Registration(char team_name[25],char leader_name[25],int number);
void Check_Registration(char team_name[25],char leader_name[25],int number);

int main()
{
    int number,choice;
    char team_name[25],leader_name[25];



    printf("********************************************************************************\n");
    printf("                              ----------------------                            \n");
    printf("                              |  WELCOME  TO  SIT  |                            \n");
    printf("                              ----------------------                            \n");
    printf("********************************************************************************\n\n");

    printf("                              ```````````````````````                          \n");
    printf("                            !!!!   HALCYON  2K19   !!!!                        \n");
    printf("                              ```````````````````````                          \n\n");

    printf("                             EVENT NAME : DANCING STAR                          \n");
    printf("                            ---------------------------                         \n\n\n");

    printf("@@  REGISTRATION FORM  @@ \n");
    printf("--------------------------\n\n");
    while(1)
    {
        printf("Choices : \n   1.New Registration\n   2.Check Your Registration, For Your Registration ID \n   3.Exit To Go \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :  printf("Enter your team name : ");
                      scanf("%s",team_name);

                      printf("Enter the name of a team leader : ");
                      scanf("%s",leader_name);

                      printf("Enter the number of participants in your team : ");
                      scanf("%d",&number);

                      printf("\n");

                      New_Registration(team_name,leader_name,number);
                      break;

             case 2 : printf("Enter your team name : ");
                      scanf("%s",team_name);

                      printf("Enter the name of a team leader : ");
                      scanf("%s",leader_name);

                      printf("Enter the number of participants in your team : ");
                      scanf("%d",&number);

                      printf("\n");

                      Check_Registration(team_name,leader_name,number);
                      break;

             case 3: printf("\n\n******************        THANK YOU       ***********************\n\n");
                     exit(0);

             default : printf("Enter the valid choice\n\n");
        }
    }
    return 0;
}


void New_Registration(char team_name[25],char leader_name[25],int number)
{
    NODE *temp = NULL,*p = NULL;

    if((temp = (NODE*)malloc(sizeof(NODE)))==NULL)
    {
        printf("No allocation of memory");
        exit(0);
    }
    strcpy(temp->team_name,team_name);
    strcpy(temp->leader_name,leader_name);
    temp->number = number;
    temp->link = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        p = start;
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link = temp;
        temp->link = NULL;
    }

    printf("       ---------------------------------------------------------------\n");
    printf("                       Registration Submitted!!!! \n             Check Your Registration ID , By Entering Choice 2\n");
    printf("       ---------------------------------------------------------------\n\n\n");
}


void Check_Registration(char team_name[25],char leader_name[25],int number)
{
    NODE *p=NULL;
    p = start;
    int Registration_ID;
    while(p!=NULL)
    {
        if(((strcmp(p->team_name,team_name))==0)&&((strcmp(p->leader_name,leader_name))==0)&&(p->number==number))
        {
            Registration_ID = rand();
            printf("       ----------------------------------------------------------------\n");
            printf("                           ***  WELCOME DANCERS  ***\n");
            printf("                      Your Registration ID  :  %d\n",Registration_ID);
            printf("                    You can go Inside, By Entering Choice 3 \n");
            printf("       -----------------------------------------------------------------\n\n\n");
            p->Registration_ID = Registration_ID;
            break;
        }
        else
        {
            printf("       ----------------------------------------------------------------\n");
            printf("                      You have not registered, Do Register \n\n\n");
            printf("       ----------------------------------------------------------------\n\n\n");
        }
        p=p->link;
    }
}
