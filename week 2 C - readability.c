#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//reference: custom built functions
    int words(string spaces);
    int letters(string letters);
    int sentences(string sentence);
    float formula(int nletter, int nword, int nsentence);

int main(void)
    {
    //input
        string text = get_string("Enter sentence:");
    //extract
        float nletters = letters(text);
        float nwords = words(text);
        float nsentences = sentences(text);
        int coleman_liau_index = round(formula(nletters,nwords,nsentences));

        if(coleman_liau_index >= 16)
            {
                printf("Grade 16+\n");
            }
        else if(coleman_liau_index < 1)
            {
                printf("Before Grade 1\n");
            }
        else
            {
                printf("Grade %i\n",coleman_liau_index);
            }
    }

int words(string spaces)
    {
    //variable declaration
        int val = 0, sp = 0;
    //for loop searches for the ASCII code for " " (32) and then writes it into the variable sp
        for(int i = 0, n = strlen(spaces); i < n;i++)
            {
             if((int) spaces[i] == 32)
                {
                    sp++;
                }
            }
    //returns an additional one for the final word before a '.' or '!' or '?' at the end of the string
        return sp + 1;
    }

int letters (string spaces)
    {
    //variable declaration
        int val = 0, sp = 0;
    //for loop searches for the any upper-case or lower-case letters and if true adds 1 to sp
        for(int i = 0, n = strlen(spaces); i < n;i++)
            {
             if((int) (spaces[i] >= 'a' && spaces[i] <= 'z')||(spaces[i] >= 'A' && spaces[i] <= 'Z'))
                {
                    sp++;
                }
            }
        return sp;
    }

int sentences (string spaces)
    {
    //variable declaration
        int val = 0, sp = 0;
    //for loop searches for '.' and adds 1 to sp if found
        for(int i = 0, n = strlen(spaces); i < n;i++)
            {
             if(spaces[i] == '.'||spaces[i] == '!'||spaces[i] == '?')
                {
                    sp++;
                }
            }
    //ensure that even if there is no '.' that is still triggers as one sentence
            if (sp == 0)
                {
                    sp = 1;
                }
        return sp;
    }

float formula (int nletter, int nword, int nsentence)
    {
    //variable declaration
        float pm = 100.00/(float) nword;
        float l = pm * (float) nletter;
        float s = pm * (float) nsentence;
    //transform data
        float index = 0.0588 * l - 0.296 * s - 15.8;
        return index;
    }
