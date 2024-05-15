#include<stdio.h>
#include<string.h>

int account_no = 213450 ;
int i = 0 ;


struct date {
    int day;
    int month;
    int year;
};



struct account{
int account_number;
char name[50];
char date_of_birth[50];
float age;
char address[50];
char phone_number[20];
char account_type[50];
int deposit_amount;
int loan;
struct date loan_date;
struct date last_payment_date;
int has_loan;

};


void create_account(struct account array[],FILE *file_pointer);
void create_account(struct account array[],FILE *file_pointer){


    file_pointer = fopen("Bank.txt", "a");
    if (file_pointer == NULL) {
        printf("Error in opening file:");
    }
 else{
    printf("\nFile opened:");
  	printf("\n******WELCOME******");
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
 	gets(array[i].phone_number);
 	puts("Enter Your Account_Type : ");
 	gets(array[i].account_type);
 	printf("Enter How Much Money You Want To Deposit :");
 	scanf("%d",&array[i].deposit_amount);
 
 	
 	fprintf(file_pointer,"ACCOUNT NUMBER : %d\n",array[i].account_number);
 	fprintf(file_pointer,"NAME : %s\n",array[i].name);
 	fprintf(file_pointer,"DATE OF BIRTH : %s\n",array[i].date_of_birth);
 	fprintf(file_pointer,"AGE : %.1f\n",array[i].age);
 	fprintf(file_pointer,"HOME ADDRESS : %s\n",array[i].address);
 	fprintf(file_pointer,"MOBILE NO : %s\n",array[i].phone_number);
 	fprintf(file_pointer,"ACCOUNT TYPE : %s\n",array[i].account_type);
 	fprintf(file_pointer,"DEPOSIT AMOUNT : %d\n",array[i].deposit_amount);
 fclose (file_pointer);
}
i++;
	return;
} 




void loan(struct account array[],FILE *ptr){
	

	    int found=0;
	    int interest_amount;
		
         int choice;
         printf("ENTER WHAT YOU WANT:");
         printf("\n1.Take loan \n2.Pay loan");
         scanf("%d",&choice);
		
		switch(choice){
			
		case 1:
			printf("Enter your account number :");
			int account_number;
			scanf("%d",&account_number);
			
			int salary;
			int j;
			for( j=0 ; j<i ; j++){		
		if(account_number==array[j].account_number){
			if(array[j].has_loan==1){
				printf("already taken loan:");
		}
		else{
			found=1;
		printf("\nEnter Your Salary:");
		scanf("%d",&salary);
		
		
		if(salary<10000){
			printf("We Can Not Give You Loan Sorry:");
		}
		else{
		ptr = fopen("loan.txt", "a");
    if (ptr == NULL){
        printf("Error in opening file:");  
    }
    
    	printf("Enter Today Date (DD MM YYYY): ");
        scanf("%d %d %d", &array[j].loan_date.day, &array[j].loan_date.month, &array[j].loan_date.year);
			
			if(salary>=10000 && salary<=40000){
				array[j].loan = 100000;
				fprintf(ptr,"total amount of loan: %d \t take_loan_Date:%d %d %d",array[j].loan,array[j].loan_date.day, array[j].loan_date.month, array[j].loan_date.year);
			}
			else if(salary>40000 && salary<=70000){
				array[j].loan =  200000;
			fprintf(ptr,"total amount of loan: %d \t take_loan_Date:%d %d %d",array[j].loan,array[j].loan_date.day, array[j].loan_date.month, array[j].loan_date.year);
			}
			else if(salary>70000 && salary<=100000){
				array[j].loan = 300000;
			fprintf(ptr,"total amount of loan: %d \t take_loan_Date:%d %d %d",array[j].loan,array[j].loan_date.day, array[j].loan_date.month, array[j].loan_date.year);
			}
			else{
				array[j].loan = 500000;
				fprintf(ptr,"total amount of loan: %d \t take_loan_Date:%d %d %d",array[j].loan,array[j].loan_date.day, array[j].loan_date.month, array[j].loan_date.year);
				array[j].has_loan=1;
			}
	}
}
}
		break;	
	}
	
	if(found==0){
		printf("For Taking Loan Account Is Compulsory You Dont Have Any Account:");
	}

	
	fclose(ptr);
		break;
		
		case 2:
			
			printf("Enter your account number :");
			int account_verification;
			scanf("%d",&account_verification);
			
			int payment;
			int get = 0;
			for(int j=0 ; j<i ; j++){
		if(account_verification==array[j].account_number){
		get=1;
		
		ptr = fopen("loan.txt", "a+");
    if (ptr == NULL){
        printf("Error in opening file:");  
    }
    
    	printf("Enter loan payment :");
		scanf("%d",&payment);
		
		printf("Enter Today Date (DD MM YYYY): ");
        scanf("%d %d %d", &array[j].last_payment_date.day, &array[j].last_payment_date.month, &array[j].last_payment_date.year);
        
        fprintf(ptr,"\nyou payed: %d \t pay_loan_Date:%d %d %d",payment,array[j].last_payment_date.day, array[j].last_payment_date.month, array[j].last_payment_date.year);
        int monthsDiff = (array[j].last_payment_date.year - array[j].loan_date.year) * 12 +
         (array[j].last_payment_date.month - array[j].loan_date.month);
         
          if (monthsDiff > 1) {
        if(array[j].loan == 100000){
         interest_amount = array[j].loan * 0.1 * monthsDiff;
    }
    else if(array[j].loan == 200000){
    	interest_amount = array[j].loan * 0.2 * monthsDiff;
	}
	else if(array[j].loan == 300000){
		interest_amount = array[j].loan * 0.3 * monthsDiff;
	}
	else{
		interest_amount = array[j].loan * 0.5 * monthsDiff;
	}
        array[j].loan=payment-interest_amount;
        printf("\nNOW remaining loan is %d",array[j].loan);
        fprintf(ptr,"\nNOW remaining loan is %d %d %d %d",array[j].loan,array[j].last_payment_date.day, array[j].last_payment_date.month, array[j].last_payment_date.year);
        }
        else{
        array[j].loan=array[j].loan-payment;
    
        printf("\nNOW remaining loan is %d",array[j].loan);
        fprintf(ptr,"\nNOW remaining loan is Date:%d %d %d %d",array[j].loan,array[j].last_payment_date.day, array[j].last_payment_date.month, array[j].last_payment_date.year);	
		}
	}
	break;
    }
    	if(get==0){
		printf("Account Not Found !:");
	}	
		break;
			
		default:
		printf("incorrect choice: TRY AGAIN!");	
		}
}

int main(){
	struct account array[i];
	
	FILE *file_pointer;
    file_pointer = fopen("Bank.txt", "w");
    fclose(file_pointer);
	
	 FILE *ptr;
     ptr = fopen("Loan.txt", "w");
     fclose(ptr);
     
    
   create_account(array,file_pointer);
	
	loan(array,ptr);
	return 0;
}
