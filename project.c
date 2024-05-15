#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>

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



void loading_scrn();
void gotoxy();
void welcome();

void create_account(struct account array[], FILE *file_pointer);
void transaction(struct account array[],FILE *fptr);
void show_details(int account_number);
void history(FILE *fptr);
void delete_account(struct account array[],FILE *fp);
void loan(struct account array[]);
void currencyconverter();
void update_account(struct account array[]);




int main(){
    loading_scrn();
    
    struct account array[i]; 
    FILE *file_pointer;
    file_pointer = fopen("Bank.txt", "w");
    fclose(file_pointer);
    
    FILE *fptr;
    fptr = fopen("Transaction history.txt", "w");
    fclose(fptr);
   
    int choice,opt;
       
    welcome();
    sleep(2);
    label1:{
        char p2[50];
        printf("\n\n\n\t\t\t\t\tEnter the password:  ");
        fflush(stdin);
        gets(p2);

        if(strcmp(p2,"ATF123")==0){
            printf("\n\n\n\t\t\t\t\tPlease wait...\n");
            sleep(1);
            system("cls");
            while(choice!=9){
                label2:{
                    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter Your Choice:\n");
                    printf("\n\t\t\t\t\t1. Create New Account\n");
                    printf("\t\t\t\t\t2. Make transactions:\n");
                    printf("\t\t\t\t\t3. Update Information:\n");
                    printf("\t\t\t\t\t4. Check Details of Account:\n");
                    printf("\t\t\t\t\t5. Transaction History:\n");
                    printf("\t\t\t\t\t6. Delete Account:\n");
                    printf("\t\t\t\t\t7. Currency Converter?\n");
                    printf("\t\t\t\t\t8. Qarz Lena hai?:\n");
                    printf("\t\t\t\t\t9. Exit:\n");
                    printf("\n");
                    printf("\t\t\t\t\t");

                    scanf("%d",&choice);

                    switch(choice){
                        case 1:{
                            loading_scrn();
                            create_account(array, file_pointer);
                            break;
                        }

                        case 2:{
                        loading_scrn();
                        transaction(array,fptr);
                            break;
                        }

                        case 3:{
                            loading_scrn();
                              update_account(array);
                            break;
                        }
                        case 4:{
                            loading_scrn();
                            int account_number;
                             printf("Enter the Account Number to View Details: ");
                             scanf("%d",&account_number);
                             show_details(account_number);
                            break;
                        }
                        case 5:{
                            loading_scrn();
                            history(fptr);
                            break;
                        }
                        case 6:{
                            loading_scrn();
                            delete_account(array, file_pointer);
                            break;
                        }
                        case 7:{
                            loading_scrn();
                            currencyconverter();
                            break;
                        }
                        case 8:{
                            loading_scrn();
                        loan(array);
                            break;
                        }
                        case 9:{
                            loading_scrn();
                            break;
                        }
                        default:{
                            printf("You Enterd Wrong Option:\n");
                            system("cls");
                            goto label2;
                            break;
                        }
                    }
                }
            }
        } 
		else{
            printf("\t\t\t\t\tPassword Wrong...!\n");
            label3:{
                printf("\n\t\t\t\t\t1.Enter Correct Password:\n\t\t\t\t\t2.Exit:\n\t\t\t\t\t");
                scanf("%d",&opt);
                if(opt==1){
                    goto label1;
                } else if(opt==2){
                    printf("\t\t\t\t\tThanks for using the bank:\n");
                } else {
                    goto label3;
                }
            }
        }
    }
    return 0;
}

void loading_scrn(){
    int a, b;
    system("cls");
    gotoxy(40,3);
    printf("LOADING...");
    gotoxy(40,4);
    for(a=1;a<=20;a++){
        for(b=0;b<=100000000;b++);
        printf("%c",219);
    }
    system("cls");
}

void gotoxy(int x,int y){
    COORD coard;
    coard.X=x;
    coard.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coard);
}

void welcome(){
    printf("\n\n\n\n\n\n\t\t\t\t\tWELCOME TO ATF BANK:\n");
}

void create_account(struct account array[], FILE *file_pointer){
	file_pointer = fopen("Bank.txt", "a");
    if (file_pointer == NULL) {
        printf("Error in opening file:");
    } else {
        printf("\nFile opened:");
        printf("\n*WELCOME*");
        printf("\nFor Creating Account Provide The Following Information :");
        array[i].account_number = account_no + i;
        getchar();
        puts("\nEnter Your Full Name : ");
        gets(array[i].name);
        puts("Enter Your Date Of Birth");
        gets(array[i].date_of_birth);
        printf("Enter Your Age :");
        scanf("%f", &array[i].age);
        getchar();
        puts("Enter Your Full Address : ");
        gets(array[i].address);
        printf("Enter Your Mobile Number :");
        gets(array[i].phone_number);
        puts("Enter Your Account_Type : ");
        gets(array[i].account_type);
        printf("Enter How Much Money You Want To Deposit :");
        scanf("%d", &array[i].deposit_amount);

        fprintf(file_pointer, "ACCOUNT NUMBER : %d\n", array[i].account_number);
        fprintf(file_pointer, "NAME : %s\n", array[i].name);
        fprintf(file_pointer, "DATE OF BIRTH : %s\n", array[i].date_of_birth);
        fprintf(file_pointer, "AGE : %.1f\n", array[i].age);
        fprintf(file_pointer, "HOME ADDRESS : %s\n", array[i].address);
        fprintf(file_pointer, "MOBILE NO : %s\n", array[i].phone_number);
        fprintf(file_pointer, "ACCOUNT TYPE : %s\n", array[i].account_type);
        fprintf(file_pointer, "DEPOSIT AMOUNT : %d\n", array[i].deposit_amount);
        fclose(file_pointer);
    }
    i++;
    return;
}	    

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

void show_details(int account_number){
    FILE *fp;
    fp=fopen("Bank.txt","r");

    if(fp==NULL){
        printf("Error opening file.");
        return;
    }

    int found=0;
    struct account acc;

    while(fscanf(fp,"ACCOUNT NUMBER : %d\n",&acc.account_number)!=EOF){
        fscanf(fp,"NAME : %[^\n]\n",acc.name);
        fscanf(fp,"DATE OF BIRTH : %[^\n]\n",acc.date_of_birth);
        fscanf(fp,"AGE : %f\n",&acc.age);
        fscanf(fp,"HOME ADDRESS : %[^\n]\n",acc.address);
        fscanf(fp,"MOBILE NO : %[^\n]\n",acc.phone_number);
        fscanf(fp,"ACCOUNT TYPE : %[^\n]\n",acc.account_type);
        fscanf(fp,"DEPOSIT AMOUNT : %d\n",&acc.deposit_amount);
        fscanf(fp,"\n");

        if(acc.account_number==account_number){
            found=1;
            printf("The Account Details Are:\n\n");
            printf("\nAccount Number: %d\n",acc.account_number);
            printf("Name: %s\n",acc.name);
            printf("Date of Birth: %s\n",acc.date_of_birth);
            printf("Age: %.1f\n",acc.age);
            printf("Address: %s\n",acc.address);
            printf("Phone Number: %s\n",acc.phone_number);
            printf("Account Type: %s\n",acc.account_type);
            printf("Deposit Amount: %d\n",acc.deposit_amount);
            break;
        }
    }

    if(!found){
        printf("Account not found.\n");
    }

    fclose(fp);
}

void history(FILE *fptr){
	
	 int account_verification;
	printf("\nEnter Your Account Number For checking Transaction history :");
	scanf("%d",&account_verification);
	
	int account;
	
	char detail[500];
	
	fptr = fopen("transaction history.txt", "r");
	
	if (fptr == NULL) {
        printf("Error opening file");
    }
    
    int verify=0;
    
    while(fscanf(fptr,"%d",&account) != EOF) {
    	if(account==account_verification){
    	fgets(detail, sizeof(detail), fptr);
    	printf("%s",detail);
        verify=1;	
        }
		}
        
        if(verify==0){
			printf("account not found");
		}
	

    fclose(fptr);
}

void delete_account(struct account array[],FILE *file_pointer){
    int acc_delete;
    printf("\nEnter the Account Number to Delete: ");
    scanf("%d",&acc_delete);

    FILE *tempo;
    tempo=fopen("temp.txt","w");
    if(tempo==NULL){
        printf("Error creating temporary file.");
        return;
    }

    int found=0;
    for(int j=0;j<i;j++){
        if(array[j].account_number==acc_delete){
            found=1;
            printf("\nAccount Found Deleting Account...\n");
            printf("Please Wait Bruhh...\n");
            sleep(2);
        }
		else{
            fprintf(tempo,"ACCOUNT NUMBER : %d\n",array[j].account_number);
            fprintf(tempo,"NAME : %s\n",array[j].name);
            fprintf(tempo,"DATE OF BIRTH : %s\n",array[j].date_of_birth);
            fprintf(tempo,"AGE : %.1f\n",array[j].age);
            fprintf(tempo,"HOME ADDRESS : %s\n",array[j].address);
            fprintf(tempo,"MOBILE NO : %s\n",array[j].phone_number);
            fprintf(tempo,"ACCOUNT TYPE : %s\n",array[j].account_type);
            fprintf(tempo,"DEPOSIT AMOUNT : %d\n",array[j].deposit_amount);
            fprintf(tempo,"\n");
        }
    }

    fclose(tempo);

    if(found){
        remove("Bank.txt");
        rename("temp.txt","Bank.txt");
        printf("Account with Account Number %d deleted successfully.\n",acc_delete);

        
        for(int k=0;k<i;k++){
            if(array[k].account_number==acc_delete){
                for(int l=k;l<i-1;l++){
                    array[l]=array[l+1];
                }
                i--;
                break;
            }
        }
    }
	 else{
        printf("Account not found.\n");
        remove("temp.txt");
    }
}


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



void currencyconverter(){
	float amount,result;
	int choice;
	printf("|Currency Converter| \n");
	printf("1.For Dollar\n");
	printf("2.For Dinar\n");
	printf("3.For Riyal\n");
	printf("4.For Euro(EUR)\n");
	printf("5.For Indian Rupees(INR)\n");
	printf("6.For Chinese Yuan(CNY)\n");
	printf("7.Mexican peso\n");
	printf("8.For Russian Ruble\n");
	printf("9.For South African Rand(ZAR)\n");
	printf("10.For Brazilian Real(BRL)\n");
	printf("Enter the amount in rupees:");
	scanf("%f",&amount);
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
    case 1:
    	result=amount/2.78;
    	printf("Amount is equal to $%.3f Dollar.",result);
    	break;
    case 2:
    	result=amount/2.1;
    	printf("Amount is equal to %.3f Dinar.",result );
    	break;
    case 3:
    	result=amount/74.25;
    	printf("Amount is equal to %.3f Riyal.",result);
    	break;
    case 4:
    	result=amount/299.87;
    	printf("Amount is equal to %.3f Euro.",result);
    	break;
    	
    case 5:
    	result=amount/3.34;
    	printf("Amount is equal to %.3f Indian Rupees.",result);
    	break;
    	
    case 6:	
           result=amount/38.48;
           printf("Amount is equal to %.3f Chinese Yuan.",result);
           break;
    
    case 7:
    	result=amount/16.41;
    	printf("Amount is equal to %.3f Mexican Peso.",result);
    	break;
    	
    case 8:
    	
    	result=amount/3.04;
    	printf("Amount is equal to %.3f Russian Ruble.",result);
    	break;
    case 9:	
         result=amount/15.04;
         printf("Amount is equal to %.3f South African Rand.",result);
         break;
    
    case 10:
    	result=amount/54.93;
    	printf("Amount is equal to %.3f Brazilian Real.",result);
    	break;
    default:
    	printf("Invalid choice.");
	}
	return;
	
}	




void update_account(struct account array[]){
    int acc_update;
    printf("\nEnter the Account Number to Update: ");
    scanf("%d",&acc_update);

    FILE *fp;
    FILE *tempo;
    tempo=fopen("temp.txt","w");
    if(tempo==NULL){
        printf("Error creating temporary file.");
        return;
    }

    int found=0;
    for(int j=0;j<i;j++){
        if(array[j].account_number==acc_update){
            found=1;
            printf("\nAccount Found Updating Account...\n");
            printf("Please Wait...\n");
            sleep(2);
            printf("\nWhat do you want to update?\n");
            printf("1. Name\n");
            printf("2. Date of Birth\n");
            printf("3. Age\n");
            printf("4. Address\n");
            printf("5. Mobile Number\n");
            printf("6. Account Type\n");
            printf("Enter your choice: ");
            int update_choice;
            scanf("%d",&update_choice);

            switch(update_choice){
                case 1:
                    printf("Enter new name: ");
                    getchar(); 
                    gets(array[j].name);
                    break;
                case 2:
                    printf("Enter new date of birth: ");
                    getchar(); 
                    gets(array[j].date_of_birth);
                    break;
                case 3:
                    printf("Enter new age: ");
                    scanf("%f", &array[j].age);
                    break;
                case 4:
                    printf("Enter new address: ");
                    getchar();
                    gets(array[j].address);
                    break;
                case 5:
                    printf("Enter new mobile number: ");
                    getchar();
                    gets(array[j].phone_number);
                    break;
                case 6:
                    printf("Enter new account type: ");
                    getchar(); 
                    gets(array[j].account_type);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
        fprintf(tempo,"ACCOUNT NUMBER : %d\n",array[j].account_number);
        fprintf(tempo,"NAME : %s\n",array[j].name);
        fprintf(tempo,"DATE OF BIRTH : %s\n",array[j].date_of_birth);
        fprintf(tempo,"AGE : %.1f\n",array[j].age);
        fprintf(tempo,"HOME ADDRESS : %s\n",array[j].address);
        fprintf(tempo,"MOBILE NO : %s\n",array[j].phone_number);
        fprintf(tempo,"ACCOUNT TYPE : %s\n",array[j].account_type);
        fprintf(tempo,"DEPOSIT AMOUNT : %d\n",array[j].deposit_amount);
        fprintf(tempo,"\n");
    }

    fclose(tempo);

    if(found){
        remove("Bank.txt");
        rename("temp.txt","Bank.txt");
        printf("Account with Account Number %d updated successfully.\n",acc_update);
    } 
	else{
        printf("Account not found.\n");
        remove("temp.txt");
    }
}
