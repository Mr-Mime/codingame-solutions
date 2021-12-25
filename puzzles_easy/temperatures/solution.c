#include <stdlib.h>
#include <stdio.h>

int main()
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);

    // Get the numbers
    int lowest = (n != 0) ? 5526 : 0;  // Set to 0 if no temperatures are provided
    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);
        
        if (abs(t) == abs(lowest)) lowest = (t<0 && lowest<0) ? t : abs(t);
        if (abs(t) < abs(lowest)) lowest = t;
    }

    printf("%d\n", lowest);

    return 0;
}
