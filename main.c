#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char first_name[50];
    char second_name[50];
    char surname[50];
    char date_of_birth[11];
    char gender[10];
    int age;
    char occupation[50];
} User;

int main() {
    int option = 0;
    float balance = 0;
    int deposit = 0;
    int loan_amount = 0;
    int is_new_user = 1;

    User user;

    printf("Welcome to the Bank!\n");

    while (1) {
        if (is_new_user) {
            printf("\nRegistration Form\n");
            printf("First Name: ");
            scanf("%s", user.first_name);
            printf("Second Name: ");
            scanf("%s", user.second_name);
            printf("Surname: ");
            scanf("%s", user.surname);
            printf("Date of Birth (dd/mm/yyyy): ");
            scanf("%s", user.date_of_birth);
            printf("Gender: ");
            scanf("%s", user.gender);
            printf("Age: ");
            scanf("%d", &user.age);
            printf("Occupation: ");
            scanf("%s", user.occupation);

            printf("\nRegistration successful!\n");
            is_new_user = 0;
        } else {
            printf("\nMenu\n");
            printf("1. Check Balance\n");
            printf("2. Deposit\n");
            printf("3. Request Loan\n");
            printf("4. Quit\n");

            printf("Enter an option: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("Your balance is: %lf\n", balance);
                    break;

                case 2:
                    printf("Enter the amount to deposit: ");
                    scanf("%d", &deposit);
                    balance += deposit;
                    printf("Your new balance is: %d\n", balance);
                    break;

                case 3:
                    if (balance >= 5000) {
                        printf("Enter the loan amount: ");
                        scanf("%d", &loan_amount);
                        if (loan_amount <= balance) {
                            balance -= loan_amount;
                            printf("Loan approved! Your new balance is: %d\n", balance);
                        } else {
                            printf("Loan request denied.\n");
                        }
                    } else {
                        printf("You must deposit at least 5000 to request a loan.\n");
                    }
                    break;

                case 4:
                    printf("Thank you for using our service.\n");
                    exit(0);

                default:
                    printf("Invalid option. Please try again.\n");
            }
        }
    }
    return 0;
}

