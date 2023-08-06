#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for their name
    string name = get_string("What's your name? ");

    // Print the personalized greeting
    printf("Hello, %s!\n", name);

    return 0;
}