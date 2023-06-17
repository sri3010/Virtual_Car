#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
                                   /*Structure Declaration*/
struct controls{
        char ac[15];
        char fan[15];
		char brakes[20];
		char clutch[20];
		char reply[5];
		char strdirection[20];
		char gear[15];
		int steering;
		int accelerator;
                };

struct battery{
		float currentkm;
		float tripkm;
		float batteryfortrip;
		float currentbattery;
		float batteryaftertrip;
		float kmaftertrip;
		float kmneededtotravel;
		char destination[13];

};


									/*Function Declaration*/
void batterystate(struct battery *,int);
char acsystem(struct controls *);
char fansystem(struct controls *);
char brakesystem(struct controls *);
char clutchsystem(struct controls *);
char sdirection(struct controls *);
char gearsystem(struct controls *);
void display(struct controls *);


char acsystem(struct controls *pt)       /*AC System Function*/
{
	if (!strcmp(pt->ac,"TOA"))
	{
		strcpy(pt->ac,"on");
	}
	else if(!strcmp(pt->ac,"TOFA"))
	{
		strcpy(pt->ac,"off");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}

char fansystem(struct controls *pt)      /*FAN System Function*/
{
	if (!strcmp(pt->fan,"TOF"))
	{
		strcpy(pt->fan,"on");
	}
	else if(!strcmp(pt->fan,"TOFF"))
	{
		strcpy(pt->fan,"off");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}

char brakesystem(struct controls *pt)      /*Brake System Function*/
{
	if(!strcmp(pt->brakes,"AB"))
	{
		strcpy(pt->brakes,"applied");
	}
	else if(!strcmp(pt->brakes,"NAB"))
	{
		strcpy(pt->brakes,"notapplied");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}

char clutchsystem(struct controls *pt)      /*Clutch System Function*/
{
	if(!strcmp(pt->clutch,"AC"))
	{
		strcpy(pt->clutch,"applied");
	}
	else if(!strcmp(pt->clutch,"NAC"))
	{
		strcpy(pt->clutch,"notapplied");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}

char sdirection(struct controls *pt)        /*Steering Direction System Function*/
{
	if(!strcmp(pt->strdirection,"CWC"))
	{
		strcpy(pt->strdirection,"clockwise");
	}
	else if(!strcmp(pt->strdirection,"ACWC"))
	{
		strcpy(pt->strdirection,"anticlockwise");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}


char gearsystem(struct controls *pt)         /*Gear System Function*/
{
	if(!strcmp(pt->gear,"N"))
	{
		strcpy(pt->gear,"neuter");
	}
	else if(!strcmp(pt->gear,"G1"))
	{
		strcpy(pt->gear,"1st");
	}
	else if(!strcmp(pt->gear,"G2"))
	{
		strcpy(pt->gear,"2nd");
	}
	else if(!strcmp(pt->gear,"G3"))
	{
		strcpy(pt->gear,"3rd");
	}
	else if(!strcmp(pt->gear,"G4"))
	{
		strcpy(pt->gear,"4th");
	}
	else if(!strcmp(pt->gear,"G5"))
	{
		strcpy(pt->gear,"5th");
	}
	else if(!strcmp(pt->gear,"R"))
	{
		strcpy(pt->gear,"reverse");
	}
	else
	{
		printf("Invalid Keyword\n");
	}
}


void display(struct controls *pt)          /*Display Function*/
{
	printf("The Current Actions of the Car Parts:\n");
	       printf("AC:%s\n",pt->ac) ;
	       printf("FAN:%s\n",pt->fan) ;
	       printf("Brakes:%s\n",pt->brakes) ;
	       printf("Clutch:%s\n",pt->clutch) ;
	       printf("Gear:%s\n",pt->gear) ;
	       printf("Steering Direction:%s\n",pt->strdirection) ;
	       printf("Steering Degree:%d\n",pt->steering) ;
	       printf("Accelerator Degree:%d\n",pt->accelerator) ;
}

void batterystate(struct battery *ery,int n)		/*Battery function*/
{
	int B=100,km=300;
	ery->currentbattery = n;
	ery->currentkm = km * ery->currentbattery / B;
	printf ("Your vehicle can go: %f kms", ery->currentkm);
	printf("\nSelect destination:\n\t1.random\n\t2.hometooffice\n\t3.hometohospital\n\t4.hometostore\n\t5.officetohome\n\t6.officetohospital\n\t7.officetostore\n\t8.hospitaltohome\n\t9.hospitaltooffice\n\t10.hospitaltostore\n\t11.storetohome\n\t12.storetooffice\n\t13.storetohospital\n");
	scanf ("%s", ery->destination);
	if (strcmp(ery->destination,"hometooffice")==0)
    {
    	printf ("Destination is 29 kms\n");
    }
	else if (strcmp(ery->destination,"hometostore")==0)
    {
    	printf ("Destination is 2 kms\n");
    }
	else if (strcmp(ery->destination,"hometohospital")==0)
    {
    	printf ("Destination is 8 kms\n");
    }
	else if (strcmp(ery->destination,"officetohome")==0)
    {
    	printf ("Destination is 29 kms\n");
    }
	else if (strcmp(ery->destination,"officetostore")==0)
    {
    	printf ("Destination is 21 kms\n");
    }
	else if (strcmp(ery->destination,"officetohospital")==0)
    {
    	printf ("Destination is 16 kms\n");
    }
	else if (strcmp(ery->destination,"hospitaltohome")==0)
    {
    	printf ("Destination is 8 kms\n");
    }
	else if (strcmp(ery->destination,"hospitaltooffice")==0)
    {
    	printf ("Destination is 16 kms\n");
    }
	else if (strcmp(ery->destination,"hospitaltostore")==0)
    {
    	printf ("Destination is 4 kms\n");
    }
	else if (strcmp(ery->destination,"storetohome")==0)
    {
    	printf ("Destination is 2 kms\n");
    }
	else if (strcmp(ery->destination,"storetooffice")==0)
    {
    	printf ("Destination is 21 kms\n");
    }
	else if (strcmp(ery->destination,"storetohospital")==0)
    {
    	printf ("Destination is 4 kms\n");
    }
	else if (strcmp(ery->destination,"random")==0)
    {
    	printf ("Enter km you need to travel : \n");
    	scanf ("%f", &ery->kmneededtotravel);
    	ery->tripkm = ery->kmneededtotravel;


	ery->batteryfortrip = (ery->currentbattery * ery->tripkm) / ery->currentkm;
	printf ("Battery used for current trip is %f percentage.\n", ery->batteryfortrip);
	if (ery->batteryfortrip < ery->currentbattery)
    {
    	printf ("You can travel\n");
    	ery->batteryaftertrip = ery->currentbattery - ery->batteryfortrip;
    	ery->kmaftertrip = ery->currentkm - ery->tripkm;
    	printf ("Battery after trip will be %f percentage.\n", ery->batteryaftertrip);
    	printf ("Your vehicle can go %f km after trip.\n", ery->kmaftertrip);
		printf("\n");
    }
	else
    {
    	printf ("your vehicle can't travel and it needs a charge\n ");
		printf("\n");
    }
	}
	else{
		printf("Invalid Option \n");
	}
}

void roofmusic(){				/*Audio and sunroof function*/
	int Sunroof,Musicplayer,Gear;
    char mode,a,b,c,d;
    printf("Sunroof : [OPEN-1,CLOSE-2]:\n");
    scanf("%d",&Sunroof);
    {
    if(Sunroof==1){
    printf("The sunroof is open\n");
    printf("Enter mode : [FULL OPEN-a,HALF OPEN-b,PARTIAL OPEN-c]\n");
    scanf("%s",&mode);
    if(mode=='a')
    printf("Now the sunroof is full open\n");
    else if(mode=='b')
    printf("now the sunroof is half open\n");
    else if(mode=='c')
    printf("Now the sunroof is partial open\n");
    else
    printf("Invalid keyword\n");
    }
    else if(Sunroof==2){
    printf("The Sunroof is close\n");
    }
    else
    printf("Invalid keyword\n");
    }
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("Musicplayer : [ON-1,OFF-2]:\n");
    scanf("%d",&Musicplayer);
    {
    if(Musicplayer==1){
    printf("The Musicplayer is on\n");
    printf("Enter mode : [CD MODE-a,RADIO MODE-b,BLUETOOTH MODE-c,USB MODE-d]\n");
    scanf("%s",&mode);
    if(mode=='a')
    printf("Now the musicplayer is in cd mode\n");
    else if(mode=='b')
    printf("Now the musicplayer is in radio mode\n");
    else if(mode=='c')
    printf("Now the musicplayer is in bluetooth mode\n");
    else if(mode=='d')
    printf("Now the musicplayer is in usb mode\n");
    else
    printf("invalid keyword\n");
    }
    else if(Musicplayer==2){
    printf("The Musicplayer is off\n");
    }
    else
    printf("invalid keyword\n");
    }
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
}

void portrunkwin()				/*Electricport Trunk window function*/
{
	int i;

    printf("condition for electric port:[OPEN-1,CLOSE-2]\n");

    scanf("%d", &i);
    if(i==1)
    {
        printf("the electric port is now open\n");
    }
    else if (i==2)
    {
        printf("the electric port is now close\n");
    }
    else{
    	printf("Invalid Options");
	}
    printf("condition for trunk:[OPEN-1,CLOSE-2]\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("the trunk is now open\n");

    }
    else if(i==2)
    {
        printf("the trunk is now close\n");
    }
    else{
    	printf("Invalid Options");
	}
     printf("condition for window:[OPEN-1,CLOSE-2,PARTIAL OPEN-3]\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("the window is now open\n");

    }
    else if(i==2)
    {
        printf("the window is now close\n");
    }

    else if(i==3)
    {
        printf("the window is now partially open\n");
    }
    else{
    	printf("Invalid Options");
	}
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
}

void enginemode()					/*Enginemode function*/
{
	char em,E1,E2,E3;
    printf("Which mode would u like to ride in:[SPORTS MODE-E1,ECONOMYMODE-E2]\n");
    scanf("%s",&em);
    if(em=E1)
    {
        printf("The engine is in sports mode.\n");
    }
    else if(em=E2)
    {
        printf("The engine is in economy mode.\n");
    }
    else{
    	printf("Invalid Options");
	}
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
}



int main()                             /*INT MAIN*/
{

                                       /*Structure Initialization & DMA*/

struct controls var,*ptr;
ptr=&var;
ptr=(struct controls *)malloc(sizeof(struct controls));
struct battery bat,*ery;
ery = &bat;
ery= (struct battery *)malloc(sizeof(struct battery));


strcpy(ptr->ac,"off");                 /*Assigning Initial States*/
strcpy(ptr->fan,"off");
strcpy(ptr->brakes,"not applied");
strcpy(ptr->clutch,"not applied");
strcpy(ptr->gear,"neuter");
strcpy(ptr->strdirection,"clockwise");
strcpy(ptr->reply,"no");
ptr->steering=0;
ptr->accelerator=0;

                                       /*User Information Display Panel*/
printf("\t\t\t\t\t\tVIRTUAL CAR CONTROL SYSTEM\n");
FILE *fp;
fp=fopen("display.txt","w");
char details[1000]="1.ACSystem 2.FanSystem 3.BrakeSystem 4.ClutchSystem 5.SteeringDirection 6.GearPostion 7.SteeringDegree 8.AcceleratorDegree 9.DisplayCurrentCarSituation\n";
fprintf(fp,"%s",details);
fclose(fp);
fp=fopen("display.txt","r");
while(fscanf(fp,"%s",details)!=EOF)
{
printf("%s\n",details);
}
fclose(fp);


int lower = 1,upper = 100,count = 1,num;
srand(time(0));
for(int i = 0;i<count;i++){
	num = (rand()%(upper-lower+1));
	printf("Avaliable battery percentage is %d\n",num);
}


batterystate(ery,num);
portrunkwin();
roofmusic();
enginemode();
int ch;                              /*Getting Input To Perform Actions*/
do
{
printf("Enter your Choice \n1.AC \n2.Fan \n3.Brake \n4.Clutch \n5.Steering \n6.Gear \n7.Steering Side \n8.Accelarator \n9.Display\n");
scanf("%d",&ch);
switch(ch)
  {
	case 1:printf("Enter the action to make changes on AC (TOA-turn on ac/TOFA-turn off ac)\n");
	      scanf("%s",&ptr->ac);
	      acsystem(ptr);
	      printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;

    case 2:printf("Enter the action to make changes on Fan (TOF-turn on fan/TOFF-turn off fan)\n");
	      scanf("%s",&ptr->fan);
	      fansystem(ptr);
	      printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;


    case 3:printf("Enter the action to perform in braking system(AB-apply brakes/NAB-dont apply brakes)\n");
          scanf("%s",&ptr->brakes);
          brakesystem(ptr);
          printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;


	case 4:printf("Enter the action to perform in clutch system(AC-apply clutch/NAC-dont apply clutch)\n");
          scanf("%s",&ptr->clutch);
          clutchsystem(ptr);
          printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;


	case 5:printf("Enter the direction to turn the steering(CWC-clockwise/ACWC-anticlockwise)\n");
          scanf("%s",&ptr->strdirection);
          sdirection(ptr);
          printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;


	case 6:printf("Enter which gear position you want to change to(N/G1/G2/G3/G4/G5/R)\n");
          scanf("%s",&ptr->gear);
          gearsystem(ptr);
          printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
		  break;


    case 7:do
		   {
				printf("Enter the degree for the steering to be turned\n");
				scanf("%d",&ptr->steering);
		   }while(ptr->steering < 0 || ptr->steering > 360);
		   printf("Do you want to continue selecting another option or exit(yes/no)\n");
	       scanf("%s",&ptr->reply);
		   break;


	case 8:do
		   {
			printf("Enter the degree for the accelerator to be pressed\n");
            scanf("%d",&ptr->accelerator);
		   }while(ptr->accelerator < 0 || ptr->accelerator > 90);
           printf("Do you want to continue selecting another option or exit(yes/no)\n");
	       scanf("%s",&ptr->reply);
		   break;

	case 9:
		  display(ptr);
	      printf("Do you want to continue selecting another option or exit(yes/no)\n");
	      scanf("%s",&ptr->reply);
	      break;

	default:printf("Invalid Option");
	        break;
  }
}while(!strcmp(ptr->reply,"yes"));

}
