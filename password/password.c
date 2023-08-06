#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool has_lowercase(string password);
bool has_uppercase(string password);
bool has_number(string password);
bool has_symbol(string password);

bool valid(string password)
{
    return has_lowercase(password) && has_uppercase(password) && has_number(password) && has_symbol(password);
}

bool has_lowercase(string password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (islower(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool has_uppercase(string password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool has_number(string password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isdigit(password[i]))
        {
            return true;
        }
    }
    return false;
}

bool has_symbol(string password)
{
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (ispunct(password[i]))
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    string password = get_string("Enter your password: ");

    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number, and symbol!\n");
    }
}
