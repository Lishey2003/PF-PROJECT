#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>

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
};

void loading_scrn();
void gotoxy();
void welcome();

void create_account(struct account array[], FILE *file_pointer);
void create_account(struct account array[], FILE *file_pointer){
	file_pointer = fopen("Bank.txt", "a");
    if (file_pointer == NULL) {
        printf("Error in opening file:");
    } else {
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

int main(){
    loading_scrn();
    struct account array[1]; // Assuming only one account is created at a time
    FILE *file_pointer;
    file_pointer = fopen("Bank.txt", "w");
    fclose(file_pointer);
    int choice, opt;

    welcome();
    sleep(2);
    label1:{
        char p2[50];
        printf("\n\n\n\t\t\t\t\tEnter the password:  ");
        fflush(stdin);
        gets(p2);

        if(strcmp(p2, "ATF123") == 0){
            printf("\n\n\n\t\t\t\t\tPlease wait...\n");
            sleep(1);
            system("cls");
            while(choice != 8){
                label2:{
                    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter Your Choice:\n");
                    printf("\n\t\t\t\t\t1. Create New Account\n");
                    printf("\t\t\t\t\t2. Make transactions:\n");
                    printf("\t\t\t\t\t3. Update Information:\n");
                    printf("\t\t\t\t\t4. Check Details of Account:\n");
                    printf("\t\t\t\t\t5. Transaction History:\n");
                    printf("\t\t\t\t\t6. Delete Account:\n");
                    printf("\t\t\t\t\t7. Currency Converter?\n");
                    printf("\t\t\t\t\t8. Exit:\n");
                    printf("\n");
                    printf("\t\t\t\t\t");

                    scanf("%d", &choice);

                    switch(choice){
                        case 1:{
                            create_account(array, file_pointer);
                            break;
                        }

                        case 2:{
                            loading_scrn();
                            break;
                        }

                        case 3:{
                            loading_scrn();
                            break;
                        }
                        case 4:{
                            loading_scrn();
                            break;
                        }
                        case 5:{
                            loading_scrn();
                            break;
                        }
                        case 6:{
                            loading_scrn();
                            break;
                        }
                        case 7:{
                            loading_scrn();
                            break;
                        }
                        case 8:{
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
        } else {
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
    gotoxy(40, 3);
    printf("LOADING...");
    gotoxy(40, 4);
    for(a=1;a<=20;a++){
        for(b=0;b<=100000000;b++);
        printf("%c", 177);
    }
    system("cls");
}

void gotoxy(int x, int y){
    COORD coard;
    coard.X=x;
    coard.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coard);
}

void welcome(){
    printf("\n\n\n\n\n\n\t\t\t\t\tWELCOME TO ATF BANK:\n");
}

