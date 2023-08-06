#include <ctype.h>
#include <stdio.h>
#include <cs50.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_grade_level(int letters, int words, int sentences);

int main(void)
{
    // Get text input from the user
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the grade level using the Coleman-Liau index
    int grade_level = compute_grade_level(letters, words, sentences);

    // Print the grade level
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade_level);
    }

    return 0;
}

int count_letters(string text)
{
    int count = 0;

    // Count the number of letters in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 1;

    // Count the number of words in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    // Count the number of sentences in the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int compute_grade_level(int letters, int words, int sentences)
{
    // Calculate the average number of letters per 100 words
    float L = (float) letters / words * 100;

    // Calculate the average number of sentences per 100 words
    float S = (float) sentences / words * 100;

    // Compute the grade level using the Coleman-Liau index formula
    int grade_level = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5);

    return grade_level;
}
