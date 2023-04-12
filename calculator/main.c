#include <stdio.h>
#include <stdlib.h>


void printMenu() {
    printf("1.) Addition\n2.) Subtraction\n3.) Multiplication\n4.) Division\n5.) Quit\n");
}

void printAnswer(int choice, float num1, float num2) {
    float ans;
    switch(choice) {
        case 1:
            ans = num1 + num2;
            printf("The operation %f + %f = %f\n", num1, num2, ans);
            break;
        case 2:
            ans = num1 - num2;
            printf("The operation %f - %f = %f\n", num1, num2, ans);
            break;
        case 3:
            ans = num1 * num2;
            printf("The operation %f * %f = %f\n", num1, num2, ans);
            break;
        case 4:
            ans = num1 / num2;
            printf("The operation %f / %f = %f\n", num1, num2, ans);
            break;
        default:
            printf("Incorrect option!!");
            break;
    }
}


int main()
{
    float num1, num2;
    int choice;
    printf("Welcome to the calculator!\n");
    while(choice != 5) {
        printf("Please choose an action to perform: \n");
        printMenu();
        scanf("%i", &choice);
        if(choice == 5) {
            printf("Quitting application...\n");
            break;
        }
        printf("Please enter two numbers.\n");
        printf("First number: \n");
        scanf("%f", &num1);
        printf("Second number: \n");
        scanf("%f", &num2);

        printAnswer(choice, num1, num2);
        printf("Operation complete.\n");
    }
    printf("Application closed.");
    return 0;
}
