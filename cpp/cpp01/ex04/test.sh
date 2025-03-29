#!/bin/bash

# Compile the C++ program
g++ -o sed main.cpp

# Create testfile.txt by fetching content from a URL if it doesn't exist and the first argument is 1
url="https://www.gutenberg.org/files/2600/2600-0.txt" # Replace with your desired URL

# Check if testfile.txt already exists and if the first argument is 1
if [ "$1" == "1" ] && [ ! -f testfile.txt ]; then
    echo "Fetching content from $url..."
    curl -o testfile.txt "$url"

    # Check if the file was created successfully
    if [ ! -f testfile.txt ]; then
        echo "Failed to create testfile.txt. Please check the URL."
        exit 1
    fi
else
    echo "testfile.txt already exists or no fetch requested. Skipping download."
fi

# Define general variables for filenames and strings to replace
filename="testfile.txt"
filename1="Makefile"
s1_chapter="CHAPTER"
s2_section="Section"
s1_nonexistent="nonexistent"
s2_replacement="replacement"

# Define test cases
declare -a test_cases=(
    "1: Replace '$s1_chapter' with '$s2_section'"
    "2: Remove new line returns: Use '\n' to remove"
    "3: Replace '$s1_nonexistent' with '$s2_replacement'"
    "4: Remove files '$filename' and '$filename.replace'"
    "5: Remove file '$filename1.replace'"
    "6: Clean up and exit"
)

# Function to run a specific test case
run_case() {
    case $1 in
        1) ./sed "$filename" "$s1_chapter" "$s2_section" ;;
        2) ./sed "$filename1" $'\n' '' ;;
        3) ./sed "$filename" "$s1_nonexistent" "$s2_replacement" ;;
        4) 
            echo "Removing '$filename' and '$filename.replace'..."
            rm -f "$filename" "$filename.replace"
            echo "Files removed."
            return ;;
        5) 
            echo "Removing '$filename1.replace'..."
            rm -f "$filename1.replace"
            echo "File removed."
            return ;;
        6) 
			echo "Cleaning up..."
			make fclean
			rm -f "$filename"
			rm -f "$filename.replace"
			rm -f "$filename1.replace"
			exit 0 ;;
        *) echo "Invalid case";;
    esac
    echo "--------------------------"
}

# Prompt for user input
echo "Select a test case to run:"
for case in "${test_cases[@]}"; do
    echo "$case"
done

# Read user selection
read -p "Enter the number of the test case (1-6): " choice

# Execute the chosen case
case $choice in
    1|2|3|4|5) run_case $choice ;;
    6) 
        echo "Cleaning up..."
		make fclean
        rm -f "$filename"
		rm -f "$filename.replace"
		rm -f "$filename1.replace"
        exit 0 ;;
    *) echo "Invalid selection";;
esac

# Clean up after running
rm -f sed
