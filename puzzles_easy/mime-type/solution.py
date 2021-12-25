import sys
import math

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.

ext = [] # ext: file extension
mt  = [] # mt: MIME type.

for i in range(n):
    e, m = input().split()
    ext.append(e.lower())
    mt.append(m)

# Get file names and check the extension
for i in range(q):
    fname = input()  # One file name per line.

    sp = fname.split(".")
    
    # if sp has more than one element we found a dot
    if len(sp) > 1:
        end = sp[-1].lower()

        if ext.__contains__(end):
            print(mt[ext.index(end)])
        else:
            print("UNKNOWN")
    else: # no dot found => no MIME type for us
        print("UNKNOWN")
