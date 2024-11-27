#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float score;
float multiplier = 100;
int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    printf("Number of Letters %i\n",letters);

    int words = count_words(text);
    printf("Number of Words %i\n", words);

    int sentences = count_sentences(text);
    printf("Number of Sentences %i\n", sentences);

    // Compute the Coleman-Liau index (val = .0588 * letters/100 - .296 * sentences/100 - 15.8)
    score = .0588 * ((letters/(float)words) * multiplier) - .296 * ((sentences /(float)words) * multiplier) - 15.8;
    // Print the grade level
    printf("Score: %f\n",round(score));
}


int count_letters(string text)                              // def function for counting letters
{
    int letter_amt = 0;

    for (int i = 0; i <= strlen(text); i++)                  // loop for each letter in text
    {
        if (isalpha(text[i]))                               // only want to loop/include if it is alpha
        {
            letter_amt += 1;                                // count each alpha
        }
    }
    return letter_amt;                                      // return number of letters in text
}

int count_words(string text)
{
    int word_amt = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i] == 1))
        { // if alphabetical then we are within a word
            word_amt += 0;
        }
        else if (ispunct(text[i+1]) == 1 || isblank(text[i+1]) == 1)
        { // if the next character is a punctuation or space
            word_amt += 1;
        }
        else if (text[i] == '\0')
        { // if currenlty alpha and next character is empty 'unfinished'
            word_amt += 1;
        }

    }
    return word_amt;
}

int count_sentences(string text)
{
    int sentence_amt = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_amt += 1;
        }
        else if (text[i+1] == '\0' && isalpha(text[i]))
        {
            sentence_amt += 1;
        }
        else
        {
            sentence_amt += 0;
        }
    }
    return sentence_amt;
}