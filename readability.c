// Includes
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// Declare Functions
float get_grad(string text) ;
int  chars_num(string text);
int words_num(string text);
int sentences_num(string text);

int main(void)
{
// Take Text From The User
    string name = get_string("text:");
// The Grad of The Text
    float index = get_grad(name);
// Controle the Return of The get_grad Function
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }
}

// Return The Gred Value
float get_grad(string text)
{
//  Applied Coleman-Liau index Low
    int  letters_Number =  chars_num(text);
    int  words_number = words_num(text);
    int sentences_number =  sentences_num(text);
    float L =  100.00 / words_number * letters_Number ;
    float S =  100.00 / words_number * sentences_number ;
    float index = 0.0588 * L - 0.296 * S - 15.8 ;
    return index;
}

// Return number of char
int chars_num(string text)
{
    int letter_number = 0 ;
    // Iiterate Text to Get Number Of Char
    for (int i = 0,  n = strlen(text) ; i < n ; i++)
    {
        // Condition For Incrase Number Of The Letter Number
        if (!isspace(text[i]) && isalnum(text[i]))
        {
            letter_number += 1;
        }

    }
    return  letter_number;
}

// Return number of Words
int words_num(string text)
{
    int words_number = 0 ;
    // Iiterate Text to Get Number Of Words
    for (int i = 0,  n = strlen(text) ; i < n ; i++)
    {
        // Condition For Incrase Number Of The Words Number
        if (isspace(text[i]))
        {
            words_number += 1;
        }
    }
    return  words_number;
}

// Return number of Sentences
int sentences_num(string text)
{
    int sentences_number = 0 ;
    // Iiterate Text to Get Number Of Sentences
    for (int i =  0,  n = strlen(text) ; i < n ; i++)
    {
        // Condition For Incrase Number Of The Sentences Number
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences_number += 1;
        }
    }
    return  sentences_number;
}