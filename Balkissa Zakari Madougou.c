#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack <hash>");
        return 1;
    }

    const int letters_count = 53;

    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_people[5] = "\0\0\0\0\0";

        for (int numberfour = 0; numberfour < letters_count; numberfour++)
        {
            for (int numberthree = 0; numberthree < letters_count; numberthree++)
            {
                for (int numbertwo = 0; numbertwo < letters_count; numbertwo++)
                {
                    for (int numberone = 1; numberone < letters_count; numberone++)
                    {
                        key_people[0] = letters[numberone]; // 1)
                        key_people[1] = letters[numbertwo]; // 2)
                        key_people[2] = letters[numberthree]; // 3)
                        key_people[3] = letters[numberfour]; // 4)


                        if (strcmp(crypt(key_people, salt), hash) == 0)
                        {
                            printf("%s\n", key_people);
                            return 0;
                        }
                    }
                }
            }
        }
 printf("Password couldn't be cracked!");
return 2;
}