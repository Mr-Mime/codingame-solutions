# Get number of horses
read -r N

# Get strength of horses
strength=()
for (( i=0; i<$N; i++ )); do
    read -r Pi

    strength+=($Pi)
done

# Sort the strength
sorted=($(echo ${strength[*]} | tr '\040' '\012' | sort -n))

# Search for the shortest distance
len=${#strength[@]}
shortes_dist=${sorted[$len-1]}

for (( i=0; i<$N-1; i++ )); do
    local_dist=$((${sorted[$i+1]} - ${sorted[$i]}))
    if [ $local_dist -lt $shortes_dist ]; then
        shortes_dist=$((${sorted[$i+1]} - ${sorted[$i]}))
    fi
done

# Print the result
echo $shortes_dist
