#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Mogamad Saeed Solomon"
#define DATE "2024"

char* Dec2RadixI(int decValue, int radValue) {
    int i = trunc((log(decValue) / log(radValue)) + 1);     // i is used as a placeholder for how many bits is needed

    int index = i - 1;          // Helps us assign values to the end before the null pointer (\0)
    int remainder = 0;          // this will be the number added to the string or converted if >10

    if (decValue == 0) {
        // for our 0 instance
        char* charArray = (char*)malloc(2 * sizeof(char));      // this sets out char* array to only 2 char sizes (0 and \0)
        charArray[0] = '0';
        charArray[1] = '\0';            // this marks the end of our array
        return charArray;           // so that the code does not continue with the rest of the function
    }

    char* charArray = (char*)malloc((i) * sizeof(char));        // if decValue is not 0 it sets the size of our array to i char sizes

    do {
        remainder = decValue % radValue;

        if (remainder < 10) charArray[index--] = remainder + '0';   // converts our remainder to a char on the ASCII table
        else charArray[index--] = remainder - 10 + 'A';     // converts remainder to the corresponding char letter

        decValue /= radValue;           // sets decValue for next iteration
    } while (decValue != 0);

    charArray[i] = '\0';        // marks the end of the string to ensure the right length of the conversion

    return charArray;
}

int main() {
    printf("*****************************\n" 
            " %s\n"
            " Written by: %s\n"         // The %s is the place holder for the #define constants declared earlier
            " Date: %s\n" 
            "*****************************", TITLE, AUTHOR, DATE);   // puts TITLE, AUTHOR and DATE in the places allocated for it (the %s)

    double logBase = 0;
    int radix = 0, decimal = 0, divResult = 0, divRemainder = 0;

    do {
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimal);
        if (decimal<0) break;           // if user enters -1 code exits the while loop
        printf("The number you have entered is %d", decimal);  

        printf("\nEnter a radix for the converter between 2 and 16: ");     //\n begins every sentence to make sure its on the next line
        scanf("%d", &radix);
        printf("The radix you have entered is %d", radix);

        logBase = log2(decimal);
        printf("\nThe log2 of the number is %.2f", logBase);         // formats the output to 2 decimal places

        divResult = trunc(decimal/radix);           // only takes the int part and discards the decimal
        printf("\nThe integer result of the number divided by %d is %d", radix, divResult);

        divRemainder = decimal % radix;
        printf("\nThe remainder is %d", divRemainder);

        char* result = Dec2RadixI(decimal, radix);      // initializes result and calls our function Dec2RadixI
        printf("\nThe radix-%d value is %s", radix, result);
        free(result);           // frees the memory allocated to result
    }
    while (decimal >= 0);       // continue the loop till decValue = -1
    
    printf("EXIT");
    
    return 0;
}