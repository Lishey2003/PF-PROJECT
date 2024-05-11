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

	
void create_account(struct account array[i],FILE *file_pointer);
void create_account(struct account array[i],FILE *file_pointer){


    file_pointer = fopen("Bank", "w");
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
i++;
}

	return;
} 

int main(){
	struct account array[i];
	
    FILE *file_pointer;
   create_account(array,file_pointer);
   fclose(file_pointer);
}
