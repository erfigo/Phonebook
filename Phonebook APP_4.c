#include<stdio.h>
#include<conio.h>//for getch operations
#include<string.h>//for string comparison
#include<stdlib.h>
#include<malloc.h>//memory allocations inclusion
#include<windows.h>
#define BIO 50
/*THE DATA STRUCTURE*/
struct contact//data structures
{
    char name[BIO];//name identifier
    char address[BIO];//the rest is data acknowledgement
    long long int mobile;
    char sex[8];
    char mail[BIO];
    char citision_no[BIO];
    struct contact *next;//pointer for linked list

    };
    /*TYPEDEF TO RENAME THE STRUCT*/
    typedef struct contact data;//rename struct
    typedef data *contactptr;
    /*PROTOTYPES*/
void menu();//main menu option
void got();//got for stabilizing the scan function
void addrecord();//add data by File operations
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
data *newnode(char *name1, char *address1, long long int mobile1, char *gender, char *mail1, char *citizen);//creates nodes
data *middle(data *start, data *end);//to determine middle element
data *searchlink(data *head, char *loc);//binary search
void printresult(data *searched);//print function

int main()
{//main function
/*DYNAMIC MEMORY ALLOCATION*/
	data *info=(struct contact*)malloc(sizeof(struct contact));
	if(info==NULL)
	{
		printf("\n\nSorry there are no memory allocated.");
	}
    system("color B1");//cover for the app
    printf("\n\t\t\t=================================================\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|           = PHONEBOOK SIMULATOR =             |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|                  Designed by:                 |\n");
    printf("\t\t\t|           Erfigo Smaradheva A. M.             |\n");
    printf("\t\t\t|           Boby Bramantyo Yurismono            |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t=================================================\n\n\n");

    printf("\t\t\t    Enter any key to continue to main menu\n");
    getch();//to skip towards the main option
    system("cls");
    menu();//main option
    return 0;//for returning value 0
}
/*MAIN OPTION FUNCTIONS*/
void menu()
{

printf("\n\n\t\t\t  YOUR PHONEBOOK\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete");//options

switch(getch())//switch getch to immediately turn to the options
{//each options moved into respective functions
    case '1':
	addrecord();
    break;
   case '2': 
    listrecord();
    break;
    case '3': 
	exit(0);//exit with value zero
    break;
    case '4': 
	modifyrecord();
    break;
    case '5': 
	searchrecord();
    break;
    case '6': 
	deleterecord();
    break;
    default:
                system("cls");
                printf("\nPlease enter number 1 to 6 only.");
                printf("\n Enter any key to continue");
                getch();

menu();//return back to options
//end options
}
}
void addrecord()/*ADDING DATA FOR THE PHONEBOOK FUNCTION*/
{/*DYNAMIC MEMORY ALLOCATION*/
	data *info=(struct contact*)malloc(sizeof(struct contact));
	contactptr newptr;
	char name[BIO],address[BIO],sex[8];
	char mail[BIO],citision_no[BIO];
	long long int mobile;
	//newptr=newnode(name,address,mobile,sex,mail,citision_no);
	if(info==NULL)
	{
		printf("\n\nSorry there are no memory allocated.");
	}
        system("cls");
        FILE *f;/*FILE OPERATIONS*/
        struct contact p;//rename the contact structures
        f=fopen("project","ab+");//open files by file operations
        //ab+:to open new files in binary mode
        printf("\n(Enter (-) for skip)");
        printf("\n Enter name: ");
        /*GOT FUNCTIONS TO UPGRADE SCAN FUNCTIONS*/
        got(p.name);//function got is applied to upgrade the scan
        printf("\nEnter the address: ");
        got(p.address);
        printf("\nEnter phone no.(+62):");
        scanf("%lld",&p.mobile);
        printf("Enter sex:");
        got(p.sex);
        printf("\nEnter e-mail:");
         got(p.mail);
        printf("\nEnter citizen no:");
        got(p.citision_no);
        fwrite(&p,sizeof(p),1,f);//write information to files
        fflush(stdin);//to prevent buffer
        printf("\nrecord saved");

fclose(f);//closing file operations

    printf("\n\nEnter any key to continue");

	 getch();
    system("cls");
    menu();//return to options
}
/*LIST FUNCTION*/
void listrecord()
{
    struct contact p;
    FILE *f;
f=fopen("project","rb");//open file operations rb:reading binary
if(f==NULL)
{
	//no list yet from the phonebook
printf("\nThere is no list yet. Add yours soon!");

getch();
}
while(fread(&p,sizeof(p),1,f)==1)//succesfully read the file
{
	//display the data recorded
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAddress=%s\nMobile no(+62)=%lld\nSex=%s\nE-mail=%s\nCitizen no=%s",p.name,p.address,p.mobile,p.sex,p.mail,p.citision_no);
}
fclose(f);//close the file operations
 printf("\n Enter any key");
 getch();
    system("cls");
menu();//return to main options
}
/*SEARCH FUNCTIONS*/
void searchrecord()
{
	//identify name as the search input
FILE *f;
struct contact p;
char name[BIO];
f=fopen("project","rb");//read binary from file operations FILE *f
if(f==NULL)
{
    printf("\n error in opening");
    exit(1);

}
printf("\nEnter name of contact to search\n");
got(name);
/*data *head=newnode;
if(searchlink(head,name)==NULL)
printf("\n\nNo contact name %s",name);
else
printresult(head);*/
while(fread(&p,sizeof(p),1,f)==1)//read files
{/*STRING LIBRARY*/
    if(strcmp(p.name,name)==0)//compare string of the searched and listed name
    {
    	//display searched data
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nMobile no(+62):%lld\nsex:%s",p.name,p.address,p.mobile,p.sex);
		printf("\nE-mail:%s\nCitision no:%s",p.mail,p.citision_no);
    }
        else
        //there is not any data that being founded
        printf("file not found");

}
 fclose(f);//close files
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();//return to main option
}

/*start LINKED LIST*/
/*LINKED LIST to enter nodes*/
data *newnode(char *name1, char *address1, long long int mobile1, char *gender, char *mail1, char *citizen)
{ contactptr newptr=(data *)malloc(sizeof(data));
	data *temp= newptr;
	strcpy(temp->name, name1);
	strcpy(temp->address,address1);
	strcpy(temp->sex,gender);
	temp->mobile=mobile1;
	strcpy(temp->mail,mail1);
	strcpy(temp->citision_no,citizen);
	temp->next=NULL;
	return temp;
	
}
/*TO PLACE MIDDLE ELEMENT IN THE LINKED LIST*/
data *middle(data *start, data *end)
{
	if(start==NULL)
	{
		return NULL;
	}
	data *slow=start;
	data *fast= start->next;
	
	while(fast!=end)
	{
		fast=fast->next;
		if(fast!=end)
		{
			slow=slow->next;
			end=end->next;
		}
	}
	return slow;
}
/*BINARY SEARCH LINKED LIST*/
data* searchlink(data *head, char *name1)
{
	data *start=head;
	data *end=NULL;
do
	{	data* mid=middle(start,end);
		if(mid==NULL)
		{
			return NULL;
		}
		if(mid->name==name1)
		{
			return mid;
		}
		else if(mid->name<name1)
		{
			start=mid->next;
		}
		else
		{
			end=mid;
		}
	}
	while(end==NULL||end!=start);
	return NULL;
}
/*PRINT FUNCTION*/
void printresult(data *searched)
{
	data *temp= searched;
	printf("\nName=%s\nGender=%s\nAddress=%s\nPhone Number=%s",temp->name,temp->sex,temp->address,temp->mobile);
		printf("\nE-mail=%s\nCitizen Number=%s",temp->mail,temp->citision_no);
			
}

/*END LINKED LIST*/
/*DELETE FUNCTION*/
void deleterecord()
{
    struct contact p;
    FILE *f,*ft;//file operations
	int flag;//for initializer
	char name[100];
	f=fopen("project","rb");//read binary from file operations
	if(f==NULL)
		{

			printf("Sorry contact not yet added.");

		}
	else
	{//ft initialize for deleting the contacts
		ft=fopen("temp","wb+");//to open binary to read and write by file operations
		if(ft==NULL)
		
            printf("file opening error");
		else

        {
		printf("\n\nEnter Contact's Name:");
		got(name);

		fflush(stdin);//buffer prevention
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)//defined as there are no contact with the searched name
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)//defined as there are contact to be deleted
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\n\nNO CONTACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");//to delete contact database in the project
			printf("\n\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key to continue");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;//file operations
    int flag=0;
    struct contact p,s;
	char  name[50];//name initializers
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("\n\nContact's not available to modify.");
			getch();
		}
	else
	{
	    system("cls");
		printf("\nContact's name to modify:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)//contact name is found
                {



                    printf("\n Enter name:");
                    got(s.name);
                    printf("\nEnter the address:");
                    got(s.address);
                    printf("\nEnter phone no(+62):");
                    scanf("%lld",&s.mobile);
                    printf("\nEnter sex:");
                    got(s.sex);
                    printf("\nEnter e-mail:");
                    got(s.mail);
                    printf("\nEnter citizen no\n");
                    got(s.citision_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);//prevent buffering


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);//close file operations
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");//return to main option
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
