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