#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Prompt the user for the pyramid's height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print the left-aligned pyramid
    for (int row = 1; row <= height; row++)
    {
        // Print spaces
        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }

        // Print hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        // Print a new line
        printf("\n");
    }

    return 0;
}
