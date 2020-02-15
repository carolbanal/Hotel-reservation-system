#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<rlutil.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

int valid_date(int date, int mon, int year);

void book();
void view();
void customer();

//structure for Customer Details
/*struct customerbooking{
	char** fname[30];
};*/


void login(){//void login after greeting page
	
	int a=0,i=0;
    char username[10],c=' '; 
    char password[10],code[10];
    char correctuser[10]="admin";
    char correctpass[10]="password";
    
    
    do{
	
	system("cls");
	
	setColor(2); // green
    printf("\t\t\t\t\t\t--------------------------- \n");
	printf("\t\t\t\t\t\t|       LOGIN FORM        |\n");
	printf("\t\t\t\t\t\t--------------------------- \n\n");
	setColor(8); //setting color to drakgray for login of admin
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
	//struct customerbooking details;//structure
	FILE *fptr;
	FILE *fp;
	
	int indate, outdate, noAmenities, a[5], totalAmount;
	char rchoice, Single; //choices
	int typeRoom, price, amount;
	int i=0, j=0;
	int day1, mon1, year1,
        day2, mon2, year2;
 
    int days, mon_diff, year_diff;  
	
	
	fp =fopen("Records.txt", "r+");
	fptr = fopen("Receipt.txt", "w+");
	
	/*printf("\t\t\t\t                Loading information sheet                 \n");
	printf("\t\t\t\t                     (press enter)                        \n");
	gets(details.fname);
	
	getch();*/
	
	
	system("cls");
	printf("\t\t\t\t                 -----------------------                \n");
	printf("\t\t\t\t                      Enter Details                     \n");
	printf("\t\t\t\t                 -----------------------                \n");
	printf("\t\t\t\t                                                        \n");
	/*printf("\t\t\t\t                 Customer Name: \n");
	gets(details.fname);*/
	printf("\t\t\t\t                 Enter Check in Date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &mon1, &day1, &year1);
    
    printf("\t\t\t\t                 Enter out date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &mon2, &day2, &year2);
	
		if(!valid_date(day1, mon1, year1)){
	        printf("\t\t\t\t                 First date is invalid.\n");        
	    }
	    
	    if(!valid_date(day2, mon2, year2)){
	        printf("\t\t\t\t                 Second date is invalid.\n");
	        exit(0);
	    }       
	    
	    if(day2 < day1){      
	        // borrow days from february
	        if (mon2 == 3){
	            //  check whether year is a leap year
	            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
	                day2 += 29;
	            }
	            
	            else{
	                day2 += 28;
	            }                        
	        }
	        
	        // borrow days from April or June or September or November
	        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
	           day2 += 30; 
	        }
	                
	        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
	        else{
	           day2 += 31;
	        }
	        
	        mon2 = mon2 - 1;
	    }
	    
	    if (mon2 < mon1){
	        mon2 += 12;
	        year2 -= 1;
	    }       
	    
	    days = day2 - day1;
	    mon_diff = mon2 - mon1;
	    year_diff = year2 - year1;
	    
	    printf("\t\t\t\t                 You will be staying for: %2d days\n", days);
	    
	    
	
	printf("\t\t\t\t                 Type of room: [1] Single Room\n");
	printf("\t\t\t\t                               [2] Double Room\n");
	printf("\t\t\t\t                               [3] Deluxe\n");
	printf("\t\t\t\t                 Choice: ");
	scanf ("%i",&rchoice);
	
	
    switch (rchoice){
        case 1:
        	price = 1500;
        	typeRoom = 1;
        	
            if(typeRoom == 1){
		    	printf("\t\t\t\t                         Type of Room: Single\n");
			}
			printf("\t\t\t\t                         price per night: %i\n", price);
			amount = price*days;
			printf("\t\t\t\t                         amount: %i\n", amount);
            break;
        case 2:
        	price = 2500;
        	typeRoom = 2;
        	
            if(typeRoom == 2){
		    	printf("\t\t\t\t                         Type of Room: Double\n");
			}
			printf("\t\t\t\t                         price per night: %i\n", price);
			amount = price*days;
			printf("\t\t\t\t                         amount: %i\n", amount);
            break;
        case 3:
        	price = 3500;
        	typeRoom = 3;
            
            if(typeRoom == 3){
		    	printf("\t\t\t\t                         Type of Room: Deluxe\n");
			}
            printf("\t\t\t\t                         price per night: %i\n", price);
			amount = price*days;
			printf("\t\t\t\t                         amount: %i\n", amount);
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
	
	setColor(12);
	printf("\n\t\t\t\t**     **           ***                    ***\n\t\t\t\t**     **           ***                    ***\n\t\t\t\t**     **  *******  ***                    ***\n\t\t\t\t*********  *******  ********   **********  ***\n\t\t\t\t*********  **   **  ***        ***    ***  ***\n\t\t\t\t**     **  **   **  ***        **********  ***");
	printf("\n\t\t\t\t**     **  *******  *********  **          ******");
	printf("\n\t\t\t\t**     **  *******  *********  **********  ******");
	setColor(11);
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
	
	setColor(2);
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

int valid_date(int day, int mon, int year)    {
    int is_valid = 1, is_leap = 0;
    
    if (year >= 1800 && year <= 9999){
 
        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            is_leap = 1;
        }
        
        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12){
            // check for days in feb
            if (mon == 2){
                if (is_leap && day == 29){
                    is_valid = 1;
                }
                else if(day > 28) {
                    is_valid = 0;
                }
            }
            
            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
                if (day > 30){
                    is_valid = 0;
                }
            }
 
            // check for days in rest of the months 
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31){            
                is_valid = 0;
            }        
        }
        
        else{
            is_valid = 0;
        }
 
    }
    else{
        is_valid = 0;
    }
    
    return is_valid;
        
}
