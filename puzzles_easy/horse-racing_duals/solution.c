#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Compare function for the quick sort
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    // Get number of horses
    int N;
    scanf("%d", &N);
    
    // Get strength for each horse
    int pi[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &pi[i]);
    }

    // Sort the array (from low to high)
    qsort((void *) pi, N, sizeof(int), compare);

    // Check smallest distance by comparing each horse to the next stronger one
    int smallest_dist = pi[1] - pi[0];
    for (int i = 1; i < N-1; i++) {
        int dist = pi[i+1] - pi[i];

        smallest_dist = (dist < smallest_dist) ? dist : smallest_dist;
    }

    // Print the smallest distance
    printf("%d", smallest_dist);

    return 0;
}
