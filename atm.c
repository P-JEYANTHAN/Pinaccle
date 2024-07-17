#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
    long int accountnum;
    char name[100];
    double balance;
} user;

int verify_user(user *u1, char *name, long int accountnum) {
    return (strcmp(u1->name, name) == 0 && u1->accountnum == accountnum);
}

void getuser(long int *accountnum, char *name) {
    printf("Enter the Account Holder name: ");
    scanf(" %[^\n]%*c", name);
    printf("Enter the Account num: ");
    scanf("%ld", accountnum);
    printf("\n-------------------------------------------------------------------\n");
}

void checkbalance(user *u1) {
    printf("Account Status\n");
    printf(" Account holder  : %s\n ", u1->name);
    printf("Account number  : %ld\n ", u1->accountnum);
    printf("Account Balance : %.2lf\n", u1->balance);
    printf("\n-------------------------------------------------------------------\n");
}

void depoamount(user *u1, double dpa) {
    if (dpa > 0) {
        u1->balance += dpa;
        printf("\nSuccessfully added to your account. Current Balance \n");
        printf(" Account holder  : %s\n ", u1->name);
        printf("Account number  : %ld\n ", u1->accountnum);
        printf("Account Balance : %.2lf\n", u1->balance);
        printf("\n-------------------------------------------------------------------\n");
    } else {
        printf("Invalid amount\n");
    }
}

void withamount(user *u1, double wda) {
    if (wda > 0 && wda <= u1->balance - 500) {
        u1->balance -= wda;
        printf("\nSuccessfully withdrawn from your account. Current Balance \n");
        printf(" Account holder  : %s\n ", u1->name);
        printf("Account number  : %ld\n ", u1->accountnum);
        printf("Account Balance : %.2lf\n", u1->balance);
        printf("\n-------------------------------------------------------------------\n");
    } else {
        printf("Insufficient Balance or Invalid amount.\n");
    }
}

void online_transfer(user *u1, user *u2, double amount) {
    if (amount > 0 && amount <= u1->balance - 500) {
        u1->balance -= amount;
        u2->balance += amount;
        printf("\nSuccessfully transferred $%.2lf from %s to %s\n", amount, u1->name, u2->name);
        printf("%s's Current Balance: %.2lf\n", u1->name, u1->balance);
        printf("\n-------------------------------------------------------------------\n");
    } else {
        printf("Invalid amount or Insufficient Balance.\n");
    }
}

int main() {
    user User = {1234, "jeyanthan", 1000.00};
    user u3[3] = {
        {2345, "arun", 2000.00},
        {5678, "ram", 1500.00},
        {8901, "valls", 2500.00}
    };

    while (1) {
        printf("Welcome to SBI BANK \n");
        printf("Enter your choice to proceed \n\n1. To Check balance\n2. To Deposit amount\n3. To Withdraw amount\n4. To Online Transfer\n5. To Exit\n");
        printf("\n-------------------------------------------------------------------\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You entered choice 1 to check balance\n");
                long int accountnum;
                char name[100];
                getuser(&accountnum, name);
                if (verify_user(&User, name, accountnum)) {
                    checkbalance(&User);
                } else {
                    printf("Account not found.\n");
                    printf("\n-------------------------------------------------------------------\n");
                }
                break;
            case 2:
                printf("You entered choice 2 to Deposit amount\n");
                getuser(&User.accountnum, User.name);
                double depositamount;
                printf("Please Enter the Deposit amount: ");
                scanf("%lf", &depositamount);
                depoamount(&User, depositamount);
                break;
            case 3:
                printf("You entered choice 3 to withdraw amount\n");
                getuser(&User.accountnum, User.name);
                double withdrawamount;
                printf("Please Enter the Withdraw amount: ");
                scanf("%lf", &withdrawamount);
                withamount(&User, withdrawamount);
                break;
            case 4:
                printf("You entered choice 4 to Online Transaction\n");
                getuser(&User.accountnum, User.name);
                char transfer_name[100];
                long int transfer_accountnum;
                double transfer_amount;
                printf("Enter the Transfer Account Holder name: ");
                scanf(" %[^\n]%*c", transfer_name);
                printf("Enter the Transfer Account number: ");
                scanf("%ld", &transfer_accountnum);
                printf("Enter the Transfer amount: ");
                scanf("%lf", &transfer_amount);

                int found = 0;
                for (int i = 0; i < 3; i++) {
                    if (strcmp(u3[i].name, transfer_name) == 0 && u3[i].accountnum == transfer_accountnum) {
                        online_transfer(&User, &u3[i], transfer_amount);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            case 5:
                printf("Thank You for using SBI ATM\n");
                exit(0);
            default:
                printf("You have entered wrong choice\n");
        }
    }
    return 0;
}
