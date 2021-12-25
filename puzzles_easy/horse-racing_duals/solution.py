import sys
import math

# Get number of horses
n = int(input())

# Get strength of horses
pi = []
for i in range(n):
    pi.append(int(input()))

# Sort list and set the max strength as start for the lowest distance.
pi = sorted(pi)
min_dist = max(pi)

# Compare each horse to the next stronger one
for idx in range(len(pi)-1):
    if (pi[idx+1]-pi[idx] < min_dist):
        min_dist = pi[idx+1] - pi[idx]

# Print solution
print(min_dist)
