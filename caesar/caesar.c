#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int key);

int main(int argc, char *argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key consists of only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char encrypted = rotate(plaintext[i], key);
        printf("%c", encrypted);
    }

    printf("\n");

    return 0;
}

char rotate(char c, int key)
{
    if (isalpha(c))
    {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + key) % 26 + base;
    }
    else
    {
        return c;
    }
}
