#include<stdio.h>


int account_no = 213450;
int i = 0;

struct account{
int account_number;
char name[50];
char date_of_birth[50];
float age;
char address[50];
char phone_number[20];
char account_type[50];
int deposit_amount;
}

void transaction(struct account array[],FILE *fptr);

void transaction(struct account array[],FILE *fptr){
	
	int account_verifaction;
	printf("\n\n** WELCOME **");
	printf("\nEnter Your Account Number For Transaction :");
	scanf("%d",&account_verifaction);
	
	fptr = fopen("transaction history.txt", "a");
	
	
    if (fptr == NULL) {
        printf("Error opening file.");
        return;
    }
	 
	 int found=0;
	for(int j=0 ; j<i ; j++ ){
	if(account_verifaction==array[j].account_number){
		fprintf(fptr,"%d\n",array[j].account_number);
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
	    
	    
	    fprintf(fptr,"* DEPOSIT MONEY *\tDate:%s\n",deposit_date);
	    fprintf(fptr,"you deposit %d\n",money);
	    fprintf(fptr,"current amount in account is : %d\n",array[j].deposit_amount); 
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
		
		if(withdraw_money<array[j].deposit_amount){
		
	    array[j].deposit_amount = array[j].deposit_amount - withdraw_money ;
	    
		printf("\n\nyou withdraw %d \tmoney on this date:%s\n",withdraw_money,withdraw_date);
	    printf("Now your remaining total amount in account is  %d\n",array[j].deposit_amount); 
	    		
	    fprintf(fptr,"* withdraw MONEY *\tDate:%s\n",withdraw_date);
	    fprintf(fptr,"you withdraw %d\n",withdraw_money);
	    fprintf(fptr,"Now your remaining  amount in account is  %d\n",array[j].deposit_amount); 
		}
		else{
			printf("your current balance is less than withdraw money :");
		}
	
		break;
				
		default:
		printf("Wrong Payment choice Try Again :");
		}
		break;
	}
}

if(found==0){
	printf("SORRY INCORRECT ACCOUNT NUMBER TRY AGAIN");
}
    fclose(fptr);
    
}


int main(){
	
	  
    FILE *fptr;
    fptr = fopen("Transaction history.txt", "w");
    fclose(fptr);
    
    transaction(array,fptr);
	
	
	return 0;
}
