/*
We're going to need to create some functions:
strlen
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Here's a function we'll define somewhere else
void wordcitcut(char *nbr, int length, int numSegments);

// This is the main function where our program starts
int main(int argc, char *argv[])
{
    int i; // We'll use this to loop through the arguments

    // If there are less than 2 or more than 3 arguments, print an error and exit
    if (argc < 2 || argc > 3)
    {
        write(1, "Error\n", 30);
        return 1;
    }

    // Start with the first argument
    i = 1;
    // For each argument...
    while (i < argc)
    {
        // Get the argument as a string
        char *nbr = argv[i];
        // Get the length of the string
        int length = strlen(nbr);
        // Calculate the number of segments we'll need
        int numSegments = (length + 2) / 3;
        // Cut the number into segments and convert each one to words
        wordcitcut(nbr, length, numSegments);
        // Move on to the next argument
        i++;
    }
    // We're done, so return 0 to indicate success
    return 0;
}