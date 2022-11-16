#include <stdio.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
	char college[50];
	char branch[50];
	char regno[50];
	
}usr;


void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}
int main(){
	FILE *fp;
	int opt,usrFound = 0;
	char password2[50];
	char usern[100];
	char pword[100];
	
	printf("\n\t\t\t\t----------Welcome to authentication system----------");
	printf("\nPlease choose your operation");
	printf("\n1.Registration");
	printf("\n2.Login");
	printf("\n3.Exit");
	printf("\n\nYour choice:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	switch(opt){
		case 1:
			system("cls");
			printf("\nEnter your full name:\t");
			gets(usr.fullName);
			usr.fullName[strlen(usr.fullName)]=0;
			
			printf("Enter your email:\t");
			gets(usr.email);
			usr.email[strlen(usr.email)]=0;
			
			printf("Enter your contact no:\t");
			gets(usr.phone);
			usr.phone[strlen(usr.phone)]=0;
			
			printf("Enter your college:\t");
			gets(usr.college);
			usr.college[strlen(usr.college)]=0;
			
			printf("Enter your branch:\t");
			gets(usr.branch);
			usr.branch[strlen(usr.branch)]=0;
			
			printf("Enter your reg. no:\t");
			gets(usr.regno);
			usr.regno[strlen(usr.regno)]=0;
			
			printf("Enter your username:\t");
			gets(usr.username);
			usr.username[strlen(usr.username)]=0;
			
			printf("Enter your password:\t");
			takepassword(usr.password);

			printf("\nConfirm your password:\t");
			takepassword(password2);
			
																			
			if(!strcmp(usr.password,password2)){
				fp = fopen("Users.dat","a+");
				fwrite(&usr,sizeof(struct user),1,fp);
				if(fwrite != 0)
					printf("\n\nUser resgistration success, Your username is %s",usr.username);
				else
					printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nPassword donot matched");
			}
			break;
		case 2:			
			printf("\nEnter your username:\t");
			gets(usern);
			printf("Enter your password:\t");
			takepassword(pword);
			fp = fopen("Users.dat","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,usern)){
					if(!strcmp(usr.password,pword)){
						system("cls");
						printf("\n\t\t\t\t\t\tWelcome %s",usr.fullName);
						printf("\n\n|Full Name:\t%s",usr.fullName);
						printf("\n|Email:\t\t%s",usr.email);
						printf("\n|Username:\t%s",usr.username);
						printf("\n|Contact no.:\t%s",usr.phone);
						printf("\n|College.:\t%s",usr.college);
						printf("\n|Branch :\t%s",usr.branch);
						printf("\n|Reg. no.:\t%s",usr.regno);	
					}
					else {
						printf("\n\nInvalid Password!");
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			break;
		case 3:
			printf("\t\t\tBye Bye :)");
			return 0;
			
	}
	
	
	
	return 0;
}
