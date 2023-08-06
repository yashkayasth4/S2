#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size, end_size;

    // Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    int years = 0;
    int population = start_size;

    while (population < end_size)
    {
        int births = population / 3;
        int deaths = population / 4;
        population = population + births - deaths;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
