#include<stdio.h>
#include<conio.h>
int main(){
	float amount,result;
	int choice;
	printf("|*Currency Converter*| \n");
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
	return 0;
	
}
