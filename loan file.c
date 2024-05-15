#include<stdio.h>

int account_no = 213450;
int i = 0;

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

};


void (struct account array[]);


void loan(struct account array[]) {
  int interest_amount;
    int found = 0;
    printf("Enter your account number: ");
    int acc;
    scanf("%d", &acc);

    for (int j = 0; j < i; j++) {
        if (acc == array[j].account_number) {
            found = 1;
            
            printf("ENTER WHAT YOU WANT:\n");
            printf("1. Take loan\n");
            printf("2. Pay loan\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                	
            if (array[j].loan != 0) {
                printf("You already have an outstanding loan. Please repay it before taking another loan.\n");
                return; 
            }
            else{
                	 printf("Enter Your Salary: ");
                      int salary;
                    scanf("%d", &salary);
                    
        printf("Enter Today Date (DD MM YYYY): ");
        scanf("%d %d %d", &array[j].loan_date.day, &array[j].loan_date.month, &array[j].loan_date.year);
    
    if (salary < 10000) {
        printf("We Cannot Give You a Loan. Salary Too Low.\n");
    } else {
        if (salary >= 10000 && salary <= 40000) {
            array[j].loan = 100000;
        } else if (salary > 40000 && salary <= 70000) {
            array[j].loan = 200000;
        } else if (salary > 70000 && salary <= 100000) {
            array[j].loan = 300000;
        } else {
            array[j].loan = 500000;
        }
        printf("Loan has been successfully granted!\n");
    }
	}
    break;

                case 2:
                 if (array[j].loan == 0) {
        printf("You do not have an outstanding loan to repay.\n");
    } else {
        printf("Enter Loan Payment: ");
        int payment;
        scanf("%d", &payment);
        
        printf("Enter Today Date (DD MM YYYY): ");
        scanf("%d %d %d", &array[j].last_payment_date.day, &array[j].last_payment_date.month, &array[j].last_payment_date.year);
        
        int monthsDiff = (array[j].last_payment_date.year - array[j].loan_date.year) * 12 +
         (array[j].last_payment_date.month - array[j].loan_date.month);
        
        
        if (payment > array[j].loan) {
            printf("Payment amount exceeds the remaining loan. Please enter a valid payment.\n");
        } else {
          if (monthsDiff > 1 && array[j].loan == 100000 ) {
         interest_amount = array[j].loan * 0.1 * monthsDiff;
         array[j].loan=payment-interest_amount;
        printf("\nNOW remaining loan is %d",array[j].loan);
    }
    else if( monthsDiff > 1 && array[j].loan == 200000){
    	interest_amount = array[j].loan * 0.2 * monthsDiff;
    	array[j].loan=payment-interest_amount;
        printf("\nNOW remaining loan is %d",array[j].loan);
	}
	else if(monthsDiff > 1 && array[j].loan == 300000){
		interest_amount = array[j].loan * 0.3 * monthsDiff;
		array[j].loan=payment-interest_amount;
        printf("\nNOW remaining loan is %d",array[j].loan);
	}
	else if(monthsDiff > 1 && array[j].loan == 500000){
		interest_amount = array[j].loan * 0.5 * monthsDiff;
		array[j].loan=payment-interest_amount;
        printf("\nNOW remaining loan is %d",array[j].loan);
	}	
        else{
        array[j].loan=array[j].loan-payment;
        printf("\nNOW remaining loan is %d",array[j].loan);
		} 
            
        }
    }  
                  break;

                default:
                    printf("Incorrect choice!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }
}

int main(){
	
	loan(array);
	
	return 0;
}
