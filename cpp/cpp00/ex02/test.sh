#!/bin/bash

# Define colors
GREEN='\033[0;32m'   # Green
RED='\033[0;31m'     # Red
NC='\033[0m'         # No Color

# Define output and log files
OUTPUT_FILE="out.txt"
LOG_FILE="19920104_091532.log"

# Step 1: Compile the code
echo "Compiling the code..."
make

# Step 2: Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    
    # Step 3: Run the program and save output to the specified output file
    ./account > "$OUTPUT_FILE"
    
    # Step 4: Compare the output with the log file, ignoring lines with timestamps
    echo "Comparing output with log file..."
    if diff -I '^\[.*\]' "$OUTPUT_FILE" "$LOG_FILE"; then
        # No differences found
        echo -e "${GREEN}No differences found.${NC}"
    else
        # Differences found
        echo -e "${RED}Differences found.${NC}"
    fi
    
    # Step 5: Remove the output file
    echo "Cleaning up..."
    rm -f "$OUTPUT_FILE"
    
    # Step 6: Run make fclean
    echo "Cleaning up the build files..."
    make fclean
else
    echo -e "${RED}Compilation failed.${NC}"
fi
