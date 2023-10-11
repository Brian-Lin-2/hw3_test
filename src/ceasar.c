#include "../include/global.h"
#include "strPtr.c"

/**
 *  Feel free to use the functions that you made in strPtr.c
 */

int encrypt(const char *plaintext, char *ciphertext, int key)
{
    // Edge cases.
    if (*plaintext == '\0')
    {
        strgCopy("undefined__EOM__", ciphertext);
        return 0;
    }

    // Make sure text has alphanumeric charcaters.
    char *p = plaintext;

    while (*p != '\0')
    {
        if (!((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')))
        {
            strgCopy("undefined__EOM__", ciphertext);
            return 0;
        }

        p++;
    }

    // Make sure ciphertext can hold it.
    if (strgLen(ciphertext) < strgLen(plaintext) + 7)
    {
        return -1;
    }

    if (plaintext == NULL || ciphertext == NULL)
    {
        return -2;
    }

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
            count++;
        }

        // Lowercase letters.
        else if (*plaintext >= 'a' && *plaintext <= 'z')
        {
            if (cipher > 'z')
            {
                cipher = (cipher % 'z' - 1) + 'a';
            }

            *ciphertext = cipher;
            count++;
        }

        // Uppercase letters.
        else if (*plaintext >= 'A' && *plaintext <= 'Z')
        {
            if (cipher > 'Z')
            {
                cipher = (cipher % 'Z' - 1) + 'A';
            }

            *ciphertext = cipher;
            count++;
        }

        plaintext++;
        ciphertext++;
    }

    // Add __EOM__ marker.
    strgCopy("__EOM__", ciphertext);

    return count;
    abort();
}

int decrypt(const char *ciphertext, char *plaintext, int key)
{
    // Edge cases.
    if (strgLen(plaintext) == 0)
    {
        return 0;
    }

    // Check for EOM marker.
    char *p = ciphertext;
    while (true)
    {
        if (*p == '\0')
        {
            // Indicates EOM marker is not present.
            return -1;
        }

        if (strgDiff("__EOM__", p) == -1)
        {
            // EOM marker is present.
            break;
        }

        p++;
    }

    // Make sure plaintext is long enough.
    if (strgLen(plaintext) < strgLen(ciphertext) - 7)
    {
        return -2;
    }

    if (plaintext == NULL || ciphertext == NULL)
    {
        return -2;
    }

    // Add EOM edge case.
    int count = 0;

    while (*ciphertext != '\0')
    {
        // Check for EOM marker.
        if (strgDiff("__EOM__", ciphertext) == -1)
        {
            break;
        }

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

    *plaintext = '\0';

    return count;
    abort();
}
