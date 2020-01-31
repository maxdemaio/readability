#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calc_index(string text, int letters, int words, int sentences);

int main(void)
{

    // Get user input for text to analyze
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index of the text
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);
    if(round(calc_index(text, letters, words, sentences)) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(round(calc_index(text, letters, words, sentences)) <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(calc_index(text, letters, words, sentences)));
    }


}

// Get the amount of letters in the string
int count_letters(string text)
{
    int i;
    int letters = 0;
    int total_len = strlen(text);

    for(i = 0; i < total_len; i++)
    {
        if(isalnum(text[i]))
        {
            letters++;
        }
    }
    return(letters);
}

// Get the amount of words in the string
int count_words(string text)
{
    int i;
    int words = 0;
    int total_len = strlen(text);

    for(i = 0; i < total_len; i++)
    {
        if(text[i] != ' ' && text[i] != '\t')
        {
            words++;
            while(text[i] != ' ' && text[i] != '\t' && text[i] != '\0')
            {
                i++;
            }
        }
    }
    return(words);
}

// Get the amount of sentences in the string
int count_sentences(string text)
{
    char end_punc[3] = {'!', '?', '.'};
    int sentences = 0;
    int i;
    int j;
    int total_len = strlen(text);

    for(i = 0; i < total_len; i++)
    {
        for(j = 0; j < sizeof(end_punc); j++)
        {
            if(text[i] == end_punc[j])
            {
                sentences++;
            }
        }
    }
    return(sentences);
}

// Calculate the Coleman-Liau index of the string
float calc_index(string text, int letters, int words, int sentences)
{
    float cl_index = 0.0588 * (float)letters/words * 100 - 0.296 * (float)sentences/words * 100 - 15.8;
    return(cl_index);
}
