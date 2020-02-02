# readability
<img src="images/github-logo-octocat-1.jpg" width = 250 align="right">

Computing the approximate (U.S.) grade level needed to comprehend a text using the Coleman-Liau index

The Coleman-Liau index is a "readability" test represented by the following equation:
```
index = 0.0588 * L - 0.296 * S - 15.8
```
Where L is the average letters per 100 words and S is the average number of sentences per 100 words within the text. With this algorithm we can determine the approximate reading level using the traits of the provided text.

**Quick overview of how readability.c works (without diving into the helper functions):**
```c
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
```

Example:
```console
~/readability/ $ make readability
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    readability.c  -lcrypt -lcs50 -lm -o readability
~/readability/ $ ./readability 
Text: She had a wasp tattoo about an inch long on her neck, a tattooed loop around the biceps of her left arm and another around her left ankle. On those occasions when she had been wearing a tank top, Armansky also saw that she had a dragon tattoo on her left shoulder blade. She was a natural redhead, but she dyed her hair raven black.
262 letter(s)
65 word(s)
3 sentence(s)
Grade 7
```
