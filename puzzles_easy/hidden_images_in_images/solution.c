#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int w;
    int h;
    scanf("%d%d", &w, &h);

    char solution[w*h+1];
    int solutionCnt = 0;

    int byte = 0;
    int cnt = 7;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int pixel;
            scanf("%d", &pixel);

            // Check wether ending with 1 or 0 
            if (pixel % 2 != 0) {
                byte = byte | (1 << cnt); // Set the bit in the current character byte
            }

            // Decrease actual byte count
            cnt--;

            // If we have read 8 bits, we add the character
            if (cnt == -1) {
                solution[solutionCnt++] = (char)byte;

                // Reset byte and byte counter
                cnt = 7;
                byte = 0;
            }
        }
    }

    // Correctly terminate the string.
    // Else I had problems with the 4th testcase
    solution[solutionCnt] = '\0';

    // Print the solution
    printf("%s\n", solution);

    return 0;
}
