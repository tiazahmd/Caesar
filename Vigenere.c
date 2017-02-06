#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // rejecting more or less than 2 command line inputs
    if (argc > 2 || argc < 2)
    {
        printf("usage: ./vigenere k\n");
        return 1;
    }
    
    // rejecting non-alpha
    int m = strlen(argv[1]);
    for (int i=0; i<m; i++)
    {
        if(isdigit(argv[1][i]))
        {
            printf("usage: ./vigenere k\n");
            return 1;
        }
    }
    
    // getting plaintext
    printf("plaintext: ");
    string plaintext = get_string();
    int n = strlen(plaintext);
    
    // converting key from string to integer
    int key[m];
    for (int i=0; i<m; i++)
    {
        if (isupper(argv[1][i]))
        {
            key[i] = argv[1][i] - 65;    
        }
        if (islower(argv[1][i]))
        {
            key[i] = argv[1][i] - 97;
        }
    }
    
    // Ascii to alphabetical index - upper case
    int alphu[91];
    
    for (int i=65, p=0; i<91; i++, p++)
    {
        alphu[i] = p;
    }
    
    // Ascii to alphabetical index - lower case
    int alphl[123];
    
    for (int i=97, p=0; i<123; i++, p++)
    {
        alphl[i] = p;
    }
    
    printf("ciphertext: ");
    
    // variable declaration
    int crypt;
    
    //ciphering the text
    for (int i=0, j=0; i<n; i++, j++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int z_1 = plaintext[i];
                int x_1 = alphu[z_1];
                crypt = (x_1 + key[j%m]) % 26;
                int y_1 = alphu[65 + crypt] + 65;
                printf("%c", y_1);
            }
            if (islower(plaintext[i]))
            {
                int z_2 = plaintext[i];
                int x_2 = alphl[z_2];
                crypt = (x_2 + key[j%m]) % 26;
                int y_2 = alphl[97 + crypt] + 97;
                printf("%c", y_2);
                }
        }
        
        else
        {
            printf("%c", plaintext[i]);
            j = j-1;
        }
    
    }
    printf("\n");
}
