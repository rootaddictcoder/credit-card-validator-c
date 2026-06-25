/*
    Credit Card Validator
    ---------------------
    Author : Datyatreya Ray

    Validates credit card numbers using the Luhn algorithm
    and identifies the issuing network based on
    prefix and length rules.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Validate that the input contains only digits
int inputValidity(const char *n, int len)
{
    for (int i = 0; n[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)n[i]))
        {
            printf("Invalid Input. Try Again.");
            return 0;
        }
    }

    if (len < 13 || len > 19)
    {
        printf("Invalid Input. Try Again.");
        return 0;
    }

    return 1;
}

// Compute the Luhn checksum
int LuhnCheckStr(const char *cn, int len)
{
    int sum = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        int digit = cn[i] - '0';

        if ((len - i) % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
    }

    return sum % 10 == 0;
}

int getPrefix(const char *cn, int n)
{
    int prefix = 0;

    for (int i = 0; i < n; i++)
    {
        prefix = prefix * 10 + (cn[i] - '0');
    }

    return prefix;
}

// Determine the card issuer from its prefix and length
void detectCardType(const char *cn, int len)
{
    int prefix2 = getPrefix(cn, 2);
    int prefix3 = getPrefix(cn, 3);
    int prefix4 = getPrefix(cn, 4);

    // American Express
    if ((strncmp(cn, "34", 2) == 0 ||
         strncmp(cn, "37", 2) == 0) &&
        len == 15)
    {
        printf("American Express\n");
    }

    // MasterCard
    else if (((prefix2 >= 51 && prefix2 <= 55) ||
              (prefix4 >= 2221 && prefix4 <= 2720)) &&
             len == 16)
    {
        printf("MasterCard\n");
    }

    // Visa
    else if (strncmp(cn, "4", 1) == 0 &&
             (len >= 13 && len <= 19))
    {
        printf("Visa\n");
    }

    // Visa Electron
    else if (strncmp(cn, "4026", 4) == 0 ||
             strncmp(cn, "417500", 6) == 0 ||
             strncmp(cn, "4405", 4) == 0 ||
             strncmp(cn, "4508", 4) == 0 ||
             strncmp(cn, "4844", 4) == 0 ||
             strncmp(cn, "4913", 4) == 0 ||
             strncmp(cn, "4917", 4) == 0)
    {
        printf("Visa Electron\n");
    }

    // Discover
    else if (strncmp(cn, "6011", 4) == 0 ||
             (prefix3 >= 644 && prefix3 <= 649) ||
             strncmp(cn, "65", 2) == 0)
    {
        printf("Discover\n");
    }

    // China UnionPay
    else if (strncmp(cn, "62", 2) == 0 ||
             strncmp(cn, "81", 2) == 0)
    {
        printf("China UnionPay\n");
    }

    // Diners Club International
    else if (strncmp(cn, "36", 2) == 0 ||
             (prefix3 >= 300 && prefix3 <= 305) ||
             strncmp(cn, "3095", 4) == 0 ||
             (prefix2 >= 38 && prefix2 <= 39))
    {
        printf("Diners Club International\n");
    }

    // Diners Club US & Canada
    else if (strncmp(cn, "54", 2) == 0 ||
             strncmp(cn, "55", 2) == 0)
    {
        printf("Diners Club US & Canada\n");
    }

    // JCB
    else if (prefix4 >= 3528 && prefix4 <= 3589)
    {
        printf("JCB\n");
    }

    // Maestro
    else if (strncmp(cn, "5018", 4) == 0 ||
             strncmp(cn, "5020", 4) == 0 ||
             strncmp(cn, "5038", 4) == 0 ||
             strncmp(cn, "5893", 4) == 0 ||
             strncmp(cn, "6304", 4) == 0 ||
             strncmp(cn, "6759", 4) == 0 ||
             (prefix4 >= 6761 && prefix4 <= 6763))
    {
        printf("Maestro\n");
    }

    // RuPay
    else if (strncmp(cn, "60", 2) == 0 ||
             strncmp(cn, "65", 2) == 0 ||
             strncmp(cn, "81", 2) == 0 ||
             strncmp(cn, "82", 2) == 0)
    {
        printf("RuPay\n");
    }

    else
    {
        printf("Unknown Card\n");
    }
}

int main(void)
{
    char *cn = calloc(30, sizeof(char));

    if (cn == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int len;

    do
    {
        printf("Number: ");
        scanf("%29s", cn);

        len = strlen(cn);
        
        int cl;
        while ((cl = getchar()) != '\n' && cl != EOF);

    } while (!inputValidity(cn, len));

    char *temp = realloc(cn, ((len * sizeof(char)) + 1));

    if (temp != NULL)
    {
        cn = temp;
    }

    if (LuhnCheckStr(cn, len))
    {
        detectCardType(cn, len);
        printf("Card is legit. \n");
    }
    else
    {
        printf("Card is fake. \n");
    }

    free(cn);

    while (1)
    {
        char choice;
        printf("Do you want to check another card? (y/n)  ");
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            main();
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 0;
            break;
        }
        else
        {
            printf("Invalid Input. Try again with the given choices. \n");
        }  
    }
    return 0;
}