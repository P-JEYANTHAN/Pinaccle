#include<stdio.h>
#include<stdlib.h>

int add(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int subtract(int b[],int n){
    int sub=b[0];
    for(int i=1;i<n;i++){
        sub-=b[i];
    }
    return sub;
}
int multiply(int c[],int n){
    int mul=1;
    for(int i=0;i<n;i++){
        mul*=c[i];
    }
    return mul;
}

float division(int d[],int n){
    float div=d[0];
    for(int i=1;i<n;i++){
        if (d[i] == 0) {
            printf("Error: Division by zero is not allowed.\n");
            exit(1);
        }
        div/=d[i];
    }
    return div;
}

int main() {
    while (1) {
        printf("Welcome to Basic Calculator \n");
        printf("Enter your choice to proceed \n\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        printf("\n-------------------------------------------------------------------\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("\nYou have entered a wrong choice\n");
            printf("\n-------------------------------------------------------------------\n");
            continue;
        }
        if (choice == 5) {
            printf("Thank you for using our Calculator.\n");
            break;
        }

        int n;
        printf("Enter the number of elements: ");
        scanf("%d",&n);
        int *arr=(int*)calloc(n,sizeof(int));
        if(arr==NULL){
            printf("Memory is not allocated\n");
            return 1;
        }
        printf("Enter %d elements : ",n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        switch(choice) {
            case 1:
                printf("\nYou entered choice 1 to perform Addition\n");
                printf("\nYour Result is: %d ",add(arr,n));
                printf("\n-------------------------------------------------------------------\n");
                free(arr);
                break;
            case 2:
                printf("\nYou entered choice 2 to perform Subtraction\n");
                printf("\nYour Result is: %d ",subtract(arr,n));
                printf("\n-------------------------------------------------------------------\n");
                free(arr);
                break;
            case 3:
                printf("\nYou entered choice 3 to perform Multiplication\n");
                printf("\nYour Result is: %d ",multiply(arr,n));
                printf("\n-------------------------------------------------------------------\n");
                free(arr);
                break;
            case 4:
                printf("\nYou entered choice 4 to perform Division\n");
                printf("\nYour Result is: %.2f ",division(arr,n));
                printf("\n-------------------------------------------------------------------\n");
                free(arr);
                break;
        }
    }
    return 0;
}
