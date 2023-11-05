/*
We're going to need to create some functions:
strcat
*/

#include <string.h>

// Here are some arrays of words that we'll use to convert numbers to words
const char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
const char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char *thousands[] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion"};

// Here are some function prototypes
void hundreds(int *nbr, char *result);
void fttens(int *nbr, char *result);
void teens_units(int *nbr, char *result);
void to_words_main(int nbr, char *result, int segment);

// This function handles the hundreds place of the number
void hundreds(int *nbr, char *result)
{
    if (*nbr >= 100) // If the number is 100 or more...
    {
        strcat(result, units[*nbr / 100]); // Add the word for the hundreds place to the result
        strcat(result, " hundred"); // Add " hundred" to the result
        if (*nbr % 100 > 0) // If there's anything left over...
            strcat(result, " and "); // Add " and " to the result
        *nbr %= 100; // Update the number to the remainder when divided by 100
    }
}

// This function handles the tens place of the number
void fttens(int *nbr, char *result)
{
    if (*nbr >= 20) // If the number is 20 or more...
    {
        strcat(result, tens[*nbr / 10]); // Add the word for the tens place to the result
        if (*nbr % 10 > 0) // If there's anything left over...
            strcat(result, " "); // Add a space to the result
        *nbr %= 10; // Update the number to the remainder when divided by 10
    }
}

// This function handles the teens and units place of the number
void teens_units(int *nbr, char *result)
{
    if (*nbr >= 11 && *nbr <= 19) // If the number is between 11 and 19...
    {
        strcat(result, teens[*nbr - 10]); // Add the word for the teens to the result
        *nbr = 0; // Update the number to 0
    }
    if (*nbr > 0) // If the number is more than 0...
        strcat(result, units[*nbr]); // Add the word for the units place to the result
}

// This function is the main function that calls the other functions to convert the number into words
void to_words_main(int nbr, char *result, int segment)
{
    hundreds(&nbr, result); // Handle the hundreds place
    fttens(&nbr, result); // Handle the tens place
    teens_units(&nbr, result); // Handle the teens and units place
    if (segment > 0) // If the segment is more than 0...
    {
        strcat(result, " "); // Add a space to the result
        strcat(result, thousands[segment]); // Add the word for the thousands place to the result
    }
}