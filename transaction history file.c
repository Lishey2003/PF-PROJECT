
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

void history(FILE *fptr);

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

int main(){
	
	history(fptr);
}

