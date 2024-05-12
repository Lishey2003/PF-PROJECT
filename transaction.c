#include<stdio.h>
#include<string.h>

int account_no = 213450 ;
int i = 0 ;

struct account{
int account_number;
char name[50];
char date_of_birth[50];
float age;
char address[50];
int phone_number;
char account_type[50];
int deposit_amount;
};


   
	
void create_account(struct account array[],FILE *file_pointer);
void transaction(struct account array[],FILE *fptr,FILE *file_pointer);



void create_account(struct account array[],FILE *file_pointer){


    file_pointer = fopen("Bank.txt", "a");
    if (file_pointer == NULL) {
        printf("Error in opening file:");
    }
 else{
    printf("\nFile opened:");
  	printf("\n*****************WELCOME*******************");
  	printf("\nFor Creating Account Provide The Following Information :");
 	array[i].account_number = account_no + i;
 	getchar();
 	puts("\nEnter Your Full Name : ");
 	gets(array[i].name);
 	puts("Enter Your Date Of Birth");
 	gets(array[i].date_of_birth);
 	printf("Enter Your Age :");
 	scanf("%f",&array[i].age);
 	getchar();
 	puts("Enter Your Full Address : ");
 	gets(array[i].address);
 	printf("Enter Your Mobile Number :");
 	scanf("%d",&array[i].phone_number);
 	getchar();
 	puts("Enter Your Account_Type : ");
 	gets(array[i].account_type);
 	printf("Enter How Much Money You Want To Deposit :");
 	scanf("%d",&array[i].deposit_amount);
 	
 	fprintf(file_pointer,"ACCOUNT NUMBER : %d\n",array[i].account_number);
 	fprintf(file_pointer,"NAME : %s\n",array[i].name);
 	fprintf(file_pointer,"DATE OF BIRTH : %s\n",array[i].date_of_birth);
 	fprintf(file_pointer,"AGE : %.1f\n",array[i].age);
 	fprintf(file_pointer,"HOME ADDRESS : %s\n",array[i].address);
 	fprintf(file_pointer,"ACCOUNT TYPE : %s\n",array[i].account_type);
 	fprintf(file_pointer,"DEPOSIT AMOUNT : %d\n",array[i].deposit_amount);
 	fclose(file_pointer);

}
    i++;
    FILE *fptr;
   fptr = fopen("transaction history.txt", "w");
   fclose(fptr);
    transaction(array,fptr,file_pointer);
	return;
	
} 


void transaction(struct account array[],FILE *fptr,FILE *file_pointer){
	
	int account_verifaction;
	printf("\n\n***** WELCOME *****");
	printf("\nEnter Your Account Number For Transaction :");
	scanf("%d",&account_verifaction);
	
	file_pointer = fopen("Bank.txt", "r");
	fptr = fopen("transaction history.txt", "a");
	
	
    if (file_pointer == NULL || fptr == NULL) {
        printf("Error opening file.");
        return;
    }
	
	 fseek(file_pointer, 0, SEEK_END);
	 
	 int found=0;
	
	for(int j=0 ; j<i ; j++ ){
	if(account_verifaction==array[j].account_number){
		found=1;
		int payment_choice;
		printf("Enter : 1.FOR DEPOSIT \t 2.FOR WITHDRAW");
		scanf("%d",&payment_choice);
		switch(payment_choice){
		case 1:
		printf("\n\nIn your account current balance is : %d\n",array[j].deposit_amount);
		printf("Enter How Much Money You Want To deposit :");
		int money;
		scanf("%d",&money);
		getchar();
		char deposit_date[40];
		printf("Enter deposit date :");
		gets(deposit_date);
		
	    array[j].deposit_amount = array[j].deposit_amount + money ;
	    
	    printf("\n\nyou deposit %d money on this date:%s\n",money,deposit_date);
	    printf("Now your total amount in account is : %d",array[j].deposit_amount); 
	    
	    fprintf(fptr,"**** DEPOSIT MONEY ****\tDate:%s\n",deposit_date);
	    fprintf(fptr,"you deposit %d money on this date:%s\n",money,deposit_date);
	    fprintf(fptr,"Now your total amount in account is : %d\n",array[j].deposit_amount); 
		break;
			
		case 2:	
		printf("\n\nIn your account current balance is : %d",array[j].deposit_amount);
		printf("\nEnter How Much Money You Want To withdraw :");
		int withdraw_money;
		scanf("%d",&withdraw_money);
		getchar();
		char withdraw_date[40];
		printf("Enter withdraw date :");
		gets(withdraw_date);
		
	    array[j].deposit_amount = array[j].deposit_amount - withdraw_money ;
	    
		printf("\n\nyou withdraw %d money on this date:%s\n",withdraw_money,withdraw_date);
	    printf("Now your remaining total amount in account is  %d",array[j].deposit_amount); 
	    		
	  
	    fprintf(fptr,"**** withdraw MONEY ****\tDate:%s\n",withdraw_date);
	    fprintf(fptr,"you withdraw %d money on this date:%s\n",withdraw_money,withdraw_date);
	    fprintf(fptr,"Now your remaining total amount in account is  %d\n",array[j].deposit_amount); 
	    
	
		break;
				
		default:
		printf("Wrong Payment choice Try Again :");
		}
		break;
	}
}

if(found==0){
	printf("****SORRY INCORRECT ACCOUNT NUMBER TRY AGAIN****");
}
	fclose(file_pointer); 
    fclose(fptr);
    
}


int main(){
	struct account array[i];
	
    FILE *file_pointer;
     file_pointer = fopen("Bank.txt", "w");
     fclose(file_pointer);
   create_account(array,file_pointer);
  
	return 0;
}
