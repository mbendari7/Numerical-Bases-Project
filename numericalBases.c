#include <stdio.h>
#include <math.h>

char arithmeticChoice();
int baseChoice();
int numInput(int base1);
int baseConversion(int num, int base2);
int calculation(char choice, int num1, int num2);
void printResult(char choice, int num1, int num2, int base1, int base2, int baseConverstedNum1, int baseConvertedNum2, int result);

int main()
{

    char choice = arithmeticChoice();
    int base1 = baseChoice();
    int num1 = numInput(base1);
    int num2 = numInput(base1);
    int base2 = baseChoice();
    int baseConvertedNum1 = baseConversion(num1, base2);
    int baseConvertedNum2 = baseConversion(num2, base2);
    int result = calculation(choice, baseConvertedNum1, baseConvertedNum2);
    printResult(choice, num1, num2, base1, base2, baseConvertedNum1, baseConvertedNum2, result);

    return 0;
}

char arithmeticChoice()
{
    char choice = "";
    do
    {
        printf("Give input ($ to stop): ");
        scanf(" %c", &choice);
        if (input == '$')
        {
            printf("Stopping.\n");
            break;
        }
        else if (choice != '+' || choice != '-' || choice != '*' || choice != '/')
        {
            printf("Invalid operator.");
        }
    } while (choice != '+' || choice != '-' || choice != '*' || choice != '/' || choice != '$');
    return choice;
}

int baseChoice()
{
    int base = 0;
    do
    {
        scanf("%d", &base);
        if (base < 2 || base > 10)
        {
            printf("Invalid base.");
        }
    } while (base < 2 || base > 10);
    return base;
}

int numInput(int base)
{
    int num = 0;
    int div = 0;
    do
    {
        scanf("%d", &num);
        int mod = num % 10;
        div = num / 10;
        if (div < base)
        {
            printf("Invalid digits in operand.");
        }
    } while (div < base || div != 0);
    return num,
}

int baseConversion(int num, int base2)
{
    int quotient = 0;
    int remainder = 0;
    int count = 0;
    int num1 = 0;
    do
    {
        quotient = num / base2;
        remainder = quotient % base2;
        num1 = remainder * pow(10, count);
        count++;
    } while (num > 0);
    return num1;
}

int calculation(char choice, int num1, int num2)
{
    int result = 0;
    switch (choice)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }
    return result;
}

void printResult(char choice, int num1, int num2, int base1, int base2,
                 int baseConvertedNum1, int baseConvertedNum2, int result)
{

    printf("%d %c %d (base %d) = %d %c %d = %d (base %d)", num1, choice, num2,
           base1, baseConvertedNum1, choice, baseConvertedNum2, result, base2);
}
