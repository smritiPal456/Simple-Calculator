#include <stdio.h>
#include <math.h>

double division(double, double);
double modulus(int, int);
void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (1) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 7) {
            printf("Exiting Calculator...\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            fprintf(stderr, "Invalid Menu choice.\n");
            continue;
        }

        printf("\nPlease enter the first number: ");
        scanf("%lf", &first);

        printf("Please enter the second number: ");
        scanf("%lf", &second);

        switch (choice) {
            case 1:
                result = first + second;
                break;

            case 2:
                result = first - second;
                break;

            case 3:
                result = first * second;
                break;

            case 4:
                result = division(first, second);
                break;

            case 5:
                result = modulus((int)first, (int)second);
                break;

            case 6:
                result = pow(first, second);
                break;
        }

        if (!isnan(result)) {
            printf("\nResult of operation is: %.2f\n", result);
        }
    }

    return 0;
}

double division(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for Division\n");
        return NAN;
    }
    return a / b;
}

double modulus(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Invalid Argument for Modulus\n");
        return NAN;
    }
    return a % b;
}

void print_menu() {
    printf("\n------------------------------------");
    printf("\nWelcome to Simple Calculator");
    printf("\nChoose one of the following options:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow, enter your choice: ");
}
