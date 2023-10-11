#include "../include/global.h"

/**
 *  Feel free to use the functions that you made in strPtr.c
 */

int encrypt(const char *plaintext, char *ciphertext, int key)
{
    // Edge cases.
    if (strgLen(plaintext) == 0)
    {
        strgCopy("undefined__EOM__", ciphertext);
        return 0;
    }

    // Make sure text has alphanumeric charcaters.
    char *p = plaintext;
    int alpnum = 0;

    while (*p != '\0')
    {
        if ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
        {
            alpnum++;
        }

        p++;
    }

    if (alpnum == 0)
    {
        strgCopy("undefined__EOM__", ciphertext);
        return 0;
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
        // Digits.
        if (*plaintext >= '0' && *plaintext <= '9')
        {
            // Makes sure there's no overflow.
            *ciphertext = '0' + ((*plaintext - '0' + key) % 10);
            count++;
        }

        // Lowercase letters.
        else if (*plaintext >= 'a' && *plaintext <= 'z')
        {
            // Makes sure there's no overflow.
            *ciphertext = 'a' + ((*plaintext - 'a' + key) % 26);
            count++;
        }

        // Uppercase letters.
        else if (*plaintext >= 'A' && *plaintext <= 'Z')
        {
            // Makes sure there's no overflow.
            *ciphertext = 'A' + ((*plaintext - 'A' + key) % 26);
            count++;
        }

        // Ignore. Don't increment count.
        else
        {
            *ciphertext = *plaintext;
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

    // Check for empty.
    if (strgDiff("__EOM__", ciphertext) == -1)
    {
        strgCopy("undefined", plaintext);
        return 0;
    }

    // Make sure text has alphanumeric charcaters.
    char *p = plaintext;
    int alpnum = 0;

    while (*p != '\0')
    {
        if (strgDiff("__EOM__", p) == -1)
        {
            // EOM marker is present.
            break;
        }

        if ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
        {
            alpnum++;
        }

        p++;
    }

    if (alpnum == 0)
    {
        strgCopy("undefined__EOM__", ciphertext);
        return 0;
    }

    // Check for EOM marker.
    char *p2 = ciphertext;
    while (true)
    {
        if (*p2 == '\0')
        {
            // Indicates EOM marker is not present.
            return -1;
        }

        if (strgDiff("__EOM__", p2) == -1 || strgDiff("__EOM__", p2) > 6)
        {
            // EOM marker is present.
            break;
        }

        p2++;
    }

    if (plaintext == NULL || ciphertext == NULL)
    {
        return -2;
    }

    int count = 0;

    while (*ciphertext != '\0')
    {
        // Make sure plaintext still has room.
        if (*plaintext == '\0')
        {
            break;
        }

        // Check for EOM marker.
        if (strgDiff("__EOM__", ciphertext) == -1 || strgDiff("__EOM__", ciphertext) > 6)
        {
            break;
        }

        // Digits.
        if (*ciphertext >= '0' && *ciphertext <= '9')
        {
            if (key > 10)
            {
                key %= 10;
            }

            *plaintext = '0' + ((*ciphertext - '0' - key + 10) % 10);
            count++;
        }

        // Lowercase letters.
        else if (*ciphertext >= 'a' && *ciphertext <= 'z')
        {
            if (key > 26)
            {
                key %= 26;
            }

            *plaintext = 'a' + ((*ciphertext - 'a' - key + 26) % 26);
            count++;
        }

        // Uppercase letters.
        else if (*ciphertext >= 'A' && *ciphertext <= 'Z')
        {
            if (key > 26)
            {
                key %= 26;
            }

            *plaintext = 'A' + ((*ciphertext - 'A' - key + 26) % 26);
            count++;
        }

        // Ignore. Don't increment count.
        else
        {
            *plaintext = *ciphertext;
        }

        ciphertext++;
        plaintext++;
    }

    *plaintext = '\0';

    return count;
    abort();
}
