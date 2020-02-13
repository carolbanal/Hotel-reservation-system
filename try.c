#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<rlutil.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

void book();
void view();
void customer();

//structure for Customer Details
/*struct customerbooking{
	char* indate;
	char* outdate;
};*/


void login(){//void login after greeting page
	
	int a=0,i=0;
    char username[10],c=' '; 
    char password[10],code[10];
    char correctuser[10]="admin";
    char correctpass[10]="password";
    
    
    do{
	
	system("cls");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //setting color to drakgray for login of admin
    printf("\t\t\t\t\t\t-------------------------- \n");
	printf("\t\t\t\t\t\t|       LOGIN FORM        |\n");
	printf("\t\t\t\t\t\t-------------------------- \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    printf("\t\t\t\t\t\tENTER USERNAME:-");
	scanf("%s", &username); 
	printf("\n\t\t\t\t\t\tENTER PASSWORD:-");
	while(i<10){
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';

	i=0;
		if(strcmp(username,correctuser)==0 && strcmp(password,correctpass)==0){
	printf("\n\n\n\t\t\t\t\t\ttWELCOME !!!! LOGIN IS SUCCESSFUL");
	
	break;
	}
	else{
		printf("\n\n\n\t\t\t\t\t\tSORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
	}
}
	while(a<4);
	if (a>3){
		printf("\n\t\t\tSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
	}
	
	system("cls");	
	
}

void book(){
	
	FILE *fptr;
	FILE *fp;
	int indate, outdate, days, noAmenities, a[5], totalAmount;
	char rchoice;
	int single=1500, doubl=2500, deluxe=3500, amount;
	int i=0, j=0;
	
	fp =fopen("Records.txt", "r+");
	fptr = fopen("Receipt.txt", "w+");
	
	/*printf("\t\t\t\t                Loading information sheet                 \n");
	printf("\t\t\t\t                     (press enter)                        \n");
	gets(details.indate);
	
	getch();*/
	
	
	system("cls");
	printf("\t\t\t\t                 -----------------------                \n");
	printf("\t\t\t\t                      Enter Details                     \n");
	printf("\t\t\t\t                 -----------------------                \n");
	printf("\t\t\t\t                                                        \n");
	printf("\t\t\t\t                 Check-in date(dd): ");
	scanf ("%i",&indate);
	printf("\t\t\t\t                 Check-out date(dd): ");
	scanf ("%i",&outdate);
	
	days = outdate-indate;//formula for days
	printf("\t\t\t\t                 Days: %i\n", days);
	printf("\t\t\t\t                 Type of room: [1] Single Room\n");
	printf("\t\t\t\t                               [2] Double Room\n");
	printf("\t\t\t\t                               [3] Deluxe\n");
	printf("\t\t\t\t                 Choice: ");
	scanf ("%i",&rchoice);
	
	
    switch (rchoice){
        case 1:
            printf("\t\t\t\t                         price per night: 1500\n");
			amount = single*days;
			printf("\t\t\t\t                         amount: %i\n", amount);
            break;
        case 2:
        	printf("\t\t\t\t                            price per night: 2500\n");
			amount = doubl*days;
			printf("\t\t\t\t                            amount: %i\n", amount);
        	break;
        case 3:
        	printf("\t\t\t\t                            price per night: 3500\n");
			amount = deluxe*days;
			printf("\t\t\t\t                            amount: %i\n", amount);
			break;
        default:
            printf("\t\t\t\t                 Invalid Input\n");
    }
	
		printf("\t\t\t\t                 Amenities: [1] Pool\n");
		printf("\t\t\t\t                            [2] Spa\n");
		printf("\t\t\t\t                            [3] Gym\n");
		printf("\t\t\t\t                 No. of Amenities: ");
		scanf ("%i",&noAmenities);
		
		
		
		for(i=0;i<noAmenities;i++){
			printf("\t\t\t\t                                   choice[%i]: ", i+1);
			scanf ("%i",&a[i]);
		}
		
		noAmenities *= 700;
		totalAmount = amount+noAmenities;
		
		printf("\t\t\t\t                 Total Amenities: %i\n", noAmenities);
		//totalAmount = noAmenities+amount;
		printf("\t\t\t\t                 Total Amount: %i\n", totalAmount);
	
	
	
	/*switch (achoice){
        case 1:
            printf("\t\t\t\t                         price: 500\n");
			amount = single*days;
			printf("\t\t\t\t                         amount: %i", amount);
            break;
        case 2:
        	printf("\t\t\t\t                            price per night: 2500\n");
			amount = doubl*days;
			printf("\t\t\t\t                            amount: %i", amount);
        	break;
        case 3:
        	printf("\t\t\t\t                            price per night: 3500\n");
			amount = deluxe*days;
			printf("\t\t\t\t                            amount: %i", amount);
        default:
            printf("\t\t\t\t                 Invalid Input ");
    }*/
    
    fclose;
}

int main(){
	int i=0;
	time_t t;
	time(&t);
	char customername;
	char menuchoice;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\n\t\t\t\t**     **           ***                    ***\n\t\t\t\t**     **           ***                    ***\n\t\t\t\t**     **  *******  ***                    ***\n\t\t\t\t*********  *******  ********   **********  ***\n\t\t\t\t*********  **   **  ***        ***    ***  ***\n\t\t\t\t**     **  **   **  ***        **********  ***");
	printf("\n\t\t\t\t**     **  *******  *********  **          ******");
	printf("\n\t\t\t\t**     **  *******  *********  **********  ******");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n ********************                                                                          ***********************");
	printf("\n ********************                ********************                                      ***********************");
	printf("\n **   ***          **                ********************                                      **    ***            **");
	printf("\n **   * *          **                **  ***           ***********************                 **    * *            **");
	printf("\n **   ***   ***    ********************  * *           ***********************                 **    ***     ***    **");
	printf("\n **         * *    ********************  ***     ***   **             ***   *********************            * *    **");
	printf("\n **   ***   ***    **  ***           **          * *   **             * *   *********************    ***     ***    **");
    printf("\n **   * *          **  * *           **  ***     ***   **    ***      ***   **   ***           **    * *            **");
	printf("\n **   ***   ***    **  ***     ***   **  * *           **    * *            **   * *           **    ***     ***    **");
    printf("\n **         * *    **          * *   **  ***     ***   **    ***      ***   **   ***     ***   **            * *    **");
	printf("\n **   ***   ***    **  ***     ***   **          * *   **             * *   **           * *   **    ***     ***    **");
    printf("\n **   * *          **  * *           **  ***     ***   **   ***       ***   **    ***    ***   **    * *            **");
    printf("\n **   ***          **  ***           **  ***           **   ***             **    ***          **    ***            **");
    
    printf("\n\n\t\t\t\t\t\tPress any key...");
    getch();
    system("cls");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\n\n\t\t\t\t**********************************************************\n");
	printf("\t\t\t\t*                   _________________                    *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                     BSCS 1A2-1's                       *\n");
	printf("\t\t\t\t*                   Hotel Reservation                    *\n");
	printf("\t\t\t\t*                         System                         *\n");
	printf("\t\t\t\t*                   _________________                    *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t**********************************************************\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*           	   By: Jushua Valencia                   *\n");
	printf("\t\t\t\t*                      Carolyn Banal                     *\n");
	printf("\t\t\t\t*                      Jessa Abenoja                     *\n");
	printf("\t\t\t\t*                    Maricel Marcelino                   *\n");
	printf("\t\t\t\t*                      Myrtle Crosa                      *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t    Current date and time : %s ",ctime(&t));
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t**********************************************************\n");
	
	printf("\n\n\n\t\t\t\tPress any key to continue...");		
	getch();
	system("cls");
	login();
	system("cls");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("\n\n\t\t\t\t**********************************************************\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                    Welcome Admin!                      *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t**********************************************************\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                 -----------------------                *\n");
	printf("\t\t\t\t*                  [1] Book a Room                       *\n");
	printf("\t\t\t\t*                 -----------------------                *\n");
	printf("\t\t\t\t*                  [2] View Transactions                 *\n");
	printf("\t\t\t\t*                 -----------------------                *\n");
	printf("\t\t\t\t*                  [3] Search Customer                   *\n");
	printf("\t\t\t\t*                 -----------------------                *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t*                                                        *\n");
	printf("\t\t\t\t**********************************************************\n");
	
	printf("\n\n\t\t\t\tEnter your Choice: ");
	scanf ("%i",&menuchoice);
	
	if (menuchoice = 1){
			book();
	/*	case '2':
			view();
			break;	
		case '3':
			customer();
			break;
		case '4':
			system("cls");
			printf("\n\n\t\t\t--------THANK YOU--------\n");
			printf("\t\t\t       COME AGAIN         ");
			break;*/
	}
	
	
	
}
