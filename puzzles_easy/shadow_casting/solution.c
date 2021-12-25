#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void trimTrailing(char * str)
{
    int index, i;

    /* Set default index */
    index = -1;

    /* Find last index of non-white space character */
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            index= i;
        }

        i++;
    }

    /* Mark next character to last non-white space character as NULL */
    str[index + 1] = '\0';
}

int main()
{
    // Get number of lines
    int N;
    scanf("%d", &N); fgetc(stdin);

    // Get lines
    char lines[N][257];
    char lines_cpy[N+2][257];
    for (int i = 0; i < N; i++) {
        scanf("%[^\n]", lines[i]); fgetc(stdin);
        
        memset(lines_cpy[i], ' ', sizeof(lines_cpy[i]));
        sprintf(lines_cpy[i], "%s", lines[i]);
        lines_cpy[i][strlen(lines_cpy[i])] = ' ';
        lines_cpy[i][256] = '\0';
    }


    memset(lines_cpy[N], ' ', sizeof(lines_cpy[N]));
    memset(lines_cpy[N+1], ' ', sizeof(lines_cpy[N+1]));

    lines_cpy[N][256] = '\0';
    lines_cpy[N+1][256] = '\0';

    for (int i = 0; i < N; i++) {
        int len = strlen(lines[i]);

        for (int j = 0; j < len; j++) {
            // Check if the actual field contains an character
            if (lines[i][j] != ' ') {
                if (lines_cpy[i+1][j+1] == ' ' || (lines_cpy[i+1][j+1] == '`' && lines[i+1][j+1] != '`')) {
                    lines_cpy[i+1][j+1] = '-';
                }

                if (lines_cpy[i+2][j+2] == ' ') {
                    lines_cpy[i+2][j+2] = '`';
                } 
            }
        }
        trimTrailing(lines_cpy[i]);

        printf("%s\n", lines_cpy[i]);
    }


    trimTrailing(lines_cpy[N]);
    trimTrailing(lines_cpy[N+1]);
    
    printf("%s\n", lines_cpy[N]);
    printf("%s\n", lines_cpy[N+1]);
     

    return 0;
}
