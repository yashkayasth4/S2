#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include the <stdlib.h> header file

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string convertedWord = replace(argv[1]);
    printf("%s\n", convertedWord);

    free(convertedWord); // Free the dynamically allocated memory

    return 0;
}

string replace(string input)
{
    string output = malloc(strlen(input) + 1); // Allocate memory for output string

    if (output == NULL)
    {
        return NULL; // Return NULL if memory allocation fails
    }

    strcpy(output, input); // Copy input string to output string

    for (int i = 0, n = strlen(output); i < n; i++)
    {
        switch (output[i])
        {
            case 'a':
                output[i] = '6';
                break;
            case 'e':
                output[i] = '3';
                break;
            case 'i':
                output[i] = '1';
                break;
            case 'o':
                output[i] = '0';
                break;
        }
    }

    return output;
}
