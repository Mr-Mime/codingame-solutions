#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // Number of elements which make up the association table.
    int N;
    scanf("%d", &N);

    // Number Q of file names to be analyzed.
    int Q;
    scanf("%d", &Q);

    // Get the extensions and MIME types
    char ext[N][11];
    char mt[N][51];
    
    for (int i = 0; i < N; i++) {
        scanf("%s%s", ext[i], mt[i]); fgetc(stdin);
        //fprintf(stderr, "%s:%s\n", ext[i], mt[i]);
    }

    // Get the file names
    for (int i = 0; i < Q; i++) {
        // One file name per line.
        char FNAME[257];
        scanf("%[^\n]", FNAME); fgetc(stdin);
        //fprintf(stderr, "%s\n", FNAME);

        // Search for a dot in the file name
        int dot_idx = -1;
        for (int c = strlen(FNAME)-1; c >= 0; c--) {
            if (FNAME[c] == '.') {
                dot_idx = c;
                break;
            }

            if (c == strlen(FNAME)-11) break;
        }

        if (dot_idx == -1) {
            printf("UNKNOWN\n");
            continue;
        }

        char end[11];
        sprintf(end, "%s",&FNAME[dot_idx+1]);

        // Search extension in given list
        bool found = false;
        for (int e = 0; e < N; e++) {
            if (strcasecmp(ext[e], end) == 0) {
                printf("%s\n", mt[e]);
                found = true;
                break;
            }
        }

        // Extension not found in given list
        if (!found) printf("UNKNOWN\n");
    }

    return 0;
}
