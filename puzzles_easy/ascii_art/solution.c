#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);

    char word[257];
    scanf("%[^\n]", word); fgetc(stdin);
    
    char letters[H][28*L];
    for (int i = 0; i < H; i++) {
        scanf("%[^\n]", letters[i]); fgetc(stdin);
    }


    // Start of ASCI calculation and output
    int indizes[strlen(word)];
    for (int i = 0; i < strlen(word); i++) {
        if ((int) word[i] >= 65 && (int) word[i] <= 90) {           // Check for upper case letter
            indizes[i] = word[i] % 65;
        } else if ((int) word[i] >= 97 && (int) word[i] <= 122) {   // Check for lower case letter
            indizes[i] = (word[i]-32) % 65;
        } else {                                                    // Unknown letter
            indizes[i] = 26; // the question mark
        }
    }

    // Output line per line
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < strlen(word); j++) {
            for (int k = 0; k < L; k++) {
                printf("%c", letters[i][indizes[j]*L+k]);
            }
        }
        if (i != H-1) printf("\n");
    }

    return 0;
}
