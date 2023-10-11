#include "../include/global.h"

int strgLen(char *s)
{
    // Edge case.
    if (s == NULL)
    {
        return -1;
    }

    int count = 0;

    while (*s != '\0')
    {
        count++;
        s++;
    }

    return count;
    abort();
}
void strgCopy(char *s, char *d)
{
    // Edge case.
    if (s == NULL || d == NULL)
    {
        return;
    }

    // Make sure you don't overflow.
    if (strgLen(d) < strgLen(s))
    {
        printf("char: %c\n", *d);
        while (*d != '\0')
        {
            *d = *s;
            s++;
            d++;
        }
    }
    else
    {
        while (*s != '\0')
        {
            *d = *s;
            s++;
            d++;
        }
    }

    *d = '\0';
    // abort();
}
void strgChangeCase(char *s)
{
    // Edge case.
    if (s == NULL)
    {
        return;
    }

    while (*s != '\0')
    {
        // Lowercase to uppercase.
        if (*s >= 'a' && *s <= 'z')
        {
            *s -= 32;
        }
        // Uppercase to lowercase.
        else if (*s >= 'A' && *s <= 'Z')
        {
            *s += 32;
        }
        // If non-alphabetic character, don't change.
        s++;
    }

    // abort();
}
int strgDiff(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL || *s1 == '\0' || *s2 == '\0')
    {
        return -2;
    }

    int i = 0;

    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return i;
        }

        i++;
        s1++;
        s2++;
    }

    // Equal strings.
    return -1;
    abort();
}
void strgInterleave(char *s1, char *s2, char *d)
{
    if (s1 == NULL || s2 == NULL || d == NULL)
    {
        return;
    }

    // 1 is s1, 0 is s2.
    int next = 1;

    // Exit out once space has been filled.
    while (*d != '\0')
    {
        // Check if any string is exhausted.
        if (*s1 == '\0')
        {
            while (*s2 != '\0' && *d != '\0')
            {
                *d = *s2;
                d++;
                s2++;
            }
            return;
        }
        else if (*s2 == '\0')
        {
            while (*s1 != '\0' && *d != '\0')
            {
                *d = *s1;
                d++;
                s1++;
            }
            return;
        }

        // Flip the switch after each iteration.
        if (next)
        {
            *d = *s1;
            d++;
            s1++;
            next = 0;
        }
        else
        {
            *d = *s2;
            d++;
            s2++;
            next = 1;
        }
    }

    // abort();
}
