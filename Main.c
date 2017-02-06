#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // rejecting more or less than 2 command-line inputs
    if (argc > 2 || argc < 2)
    {
        printf("usage: ./caesar1 k\n");
        return 1;
    }
    
    
    // Getting plaintext
        printf("plaintext: ");
        string plaintext = get_string();
        
        // Converting key from string to integer
        int key = atoi(argv[1]);
        
        // Variable declaration
        int crypt;
        int n = strlen(plaintext);
        
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
        
        for (int i=0; i<n; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    int z_1 = plaintext[i];
                    int x_1 = alphu[z_1];
                    crypt = (x_1 + key) % 26;
                    int y_1 = alphu[65+crypt] + 65;
                    printf("%c", y_1);
                }
                if (islower(plaintext[i]))
                {
                    int z_2 = plaintext[i];
                    int x_2 = alphl[z_2];
                    crypt = (x_2 + key) % 26;
                    int y_2 = alphl[97+crypt] + 97;
                    printf("%c", y_2);
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    
}
