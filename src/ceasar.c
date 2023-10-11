//
//
//
// ADD BACK LATER
// #include "global.h"
//
//
//

// REMOVE LATER.
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Feel free to use the functions that you made in strPtr.c
 */

int encrypt(const char *plaintext, char *ciphertext, int key)
{
    if (plaintext == NULL || ciphertext == NULL)
    {
        return -2;
    }

    // Add EOM edge case.
    int count = 0;

    while (*plaintext != '\0')
    {
        char cipher = *plaintext + key;

        // Digits.
        if (*plaintext >= '0' && *plaintext <= '9')
        {
            if (cipher > '9')
            {
                cipher = (cipher % '9' - 1) + '0';
            }

            *ciphertext = cipher;
        }

        // Lowercase letters.
        else if (*plaintext >= 'a' && *plaintext <= 'z')
        {
            if (cipher > 'z')
            {
                cipher = (cipher % 'z' - 1) + 'a';
            }

            *ciphertext = cipher;
        }

        // Uppercase letters.
        else if (*plaintext >= 'A' && *plaintext <= 'Z')
        {
            if (cipher > 'Z')
            {
                cipher = (cipher % 'Z' - 1) + 'A';
            }

            *ciphertext = cipher;
        }

        count++;
        plaintext++;
        ciphertext++;
    }

    return count;
    abort();
}

int decrypt(const char *ciphertext, char *plaintext, int key)
{
    if (plaintext == NULL || ciphertext == NULL)
    {
        return -2;
    }

    // Add EOM edge case.
    int count = 0;

    while (*ciphertext != '\0')
    {
        char cipher = *ciphertext - key;

        // Digits.
        if (*ciphertext >= '0' && *ciphertext <= '9')
        {
            if (cipher < '0')
            {
                cipher = '9' + (cipher - '0' + 1);
            }

            *plaintext = cipher;
        }

        // Lowercase letters.
        else if (*ciphertext >= 'a' && *ciphertext <= 'z')
        {
            if (cipher < 'a')
            {
                cipher = 'z' + (cipher - 'a' + 1);
            }

            *plaintext = cipher;
        }

        // Uppercase letters.
        else if (*ciphertext >= 'A' && *ciphertext <= 'Z')
        {
            if (cipher < 'A')
            {
                cipher = 'Z' + (cipher - 'A' + 1);
            }

            *plaintext = cipher;
        }

        count++;
        ciphertext++;
        plaintext++;
    }

    return count;
    abort();
}

// int main()
// {
//     char s[] = "Dtf331";
//     char d[] = "000000";

//     int count = decrypt(s, d, 1);
//     printf("%d\n", count);
//     printf("%s\n", d);

//     return 0;
// }
