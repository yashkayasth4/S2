#include <stdio.h>
#include <cs50.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

// Function to convert a decimal number to an 8-bit binary string
string decimal_to_binary(int decimal)
{
    string binary = "00000000";

    for (int i = 7; decimal > 0; i--)
    {
        int remainder = decimal % 2;
        decimal /= 2;
        binary[i] = '0' + remainder;
    }

    return binary;
}

// Function to convert a message to binary instructions for the light bulbs
void convert_message(string message)
{
    for (int i = 0; i < strlen(message); i++)
    {
        int decimal = (int)message[i];
        string binary = decimal_to_binary(decimal);
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int bit = binary[j] - '0';
            print_bulb(bit);
        }
        printf("\n");
    }
}

int main(void)
{
    // Get the message from the user
    string message = get_string("Message: ");

    // Convert the message to binary instructions
    convert_message(message);

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
