#include <stdio.h>
#include <math.h>

char arithmeticChoice();
int baseChoice();
int numInput(int base1);
int baseConversion(int num, int inputBase);
int calculation(char choice, int num1, int num2);
void printResult(char choice, int num1, int num2, int base1, int base2, int baseConverstedNum1, int baseConvertedNum2, int result);

int main()
{
    char choice;
    int base1;             // Input Base
    int num1;              // Numeral 1 in Base 1
    int num2;              // Numeral 2 in Base 1
    int base2;             // Output Base
    int baseConvertedNum1; // Numeral 1 converted to Base 10
    int baseConvertedNum2; // Numeral 2 converted to Base 10
    int result;            // Result in Base 10

    while (1)
    {
        printf("Give input ($ to stop): ");

        choice = arithmeticChoice();

        if (choice == '$')
        {
            printf("Stopping.\n");
            break;
        }

        base1 = baseChoice();

        num1 = numInput(base1);

        num2 = numInput(base1);

        base2 = baseChoice();

        // Function that convert input numbers (Base1) to Base 10
        baseConvertedNum1 = baseConversion(num1, base1);
        baseConvertedNum2 = baseConversion(num2, base1);

        // Function that perform calculation on Base 10 numbers
        result = calculation(choice, baseConvertedNum1, baseConvertedNum2);

        // Function that prints result, including conversion of Base 10 result to Base 2
        printResult(choice, num1, num2, base1, base2, baseConvertedNum1, baseConvertedNum2, result);
    }

    return 0;
}

char arithmeticChoice()
{
    char choice;
    do
    {
        scanf(" %c", &choice);
        if (choice == '$')
        {
            break;
        }
        else if (choice != '+' && choice != '-' && choice != '*' && choice != '/')
        {
            printf("Invalid operator\n");
        }
    } while (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != '$');
    return choice;
}

int baseChoice()
{
    int base = 0;
    do
    {
        scanf("%d", &base); // Scan at the beginning of the loop
        if (base < 2 || base > 10)
        {
            printf("Invalid base\n");
        }
    } while (base < 2 || base > 10);
    return base;
}

int numInput(int base)
{
    int num = 0;
    int div = 0;
    int status = 0;

    do
    {
        scanf("%d", &num);

        status = 0;
        div = num;

        while (div > 0)
        {
            int mod = div % 10;
            if (mod >= base)
            {
                printf("Invalid digits in operand\n");
                status = 1;
                break;
            }
            div = div / 10;
        }
    } while (status == 1);
    return num;
}

// Function to convert a number (represented as a decimal integer) from  the variable inputBase to Base 10
int baseConversion(int num, int inputBase)
{
    int quotient = 0; // This will hold the Base 10 result
    int remainder = 0;
    int count = 0;

    if (num == 0)
        return 0;

    while (num > 0)
    {
        remainder = num % 10; // Get the rightmost digit of the number as a string
        // quotient = quotient + remainder * (int)pow(base2, count);
        quotient = quotient + remainder * (int)pow(inputBase, count);
        num = num / 10;
        count++;
    }
    return quotient;
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
                 int baseConverstedNum1, int baseConvertedNum2, int result)
{
    int original_num1 = num1;
    int original_num2 = num2;

    // The result in base 2 (output base to user)
    int converted_result_baseN = 0;
    int multiplier = 1;

    int temp_base10_result = result;

    if (temp_base10_result == 0)
    {
        converted_result_baseN = 0;
    }
    else
    {
        while (temp_base10_result > 0)
        {
            int remainder = temp_base10_result % base2; // Get the remainder in the output base
            converted_result_baseN = converted_result_baseN + remainder * multiplier;
            temp_base10_result = temp_base10_result / base2;
            multiplier = multiplier * 10; // This creates the result as a decimal number
        }
    }

    // Order of the variables in order to ensure readability
    // Print format: [BaseN Num1][Op][BaseN Num2] (base Base1) = [Base10 Num1][Op][Base10 Num2] = [BaseM Result] (base Base2)
    printf("%d%c%d (base %d) = %d%c%d = %d (base %d)\n",
           original_num1, choice, original_num2, base1,
           baseConverstedNum1, choice, baseConvertedNum2,
           converted_result_baseN, base2);
}