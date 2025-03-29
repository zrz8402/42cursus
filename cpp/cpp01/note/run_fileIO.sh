#!/bin/bash

# Generate example.txt with some initial content
echo "Line 1" > example.txt
echo "Line 2" >> example.txt
echo "Line 3" >> example.txt

# Generate numbers.txt with a sample integer
echo "42" > numbers.txt

# Generate input.txt with multiple lines
echo "This is line one." > input.txt
echo "This is line two." >> input.txt
echo "This is line three." >> input.txt

# Compile the C++ program
g++ -o fileIO fileIO.cpp

# Prompt the user for options
echo "Select an option:"
echo "1. Run all tests"
echo "2. Run specific tests (enter numbers separated by commas)"
echo "3. Cleanup generated files"
read -r userInput

# Determine action based on user input
if [ "$userInput" == "1" ]; then
    # Run all tests
    ./fileIO "1,2,3,4,5,6,7,8"  # Modify this to include all functions
elif [ "$userInput" == "2" ]; then
    # Provide hints for specific functions
    echo "Available functions to test:"
    echo "1 - Basic File Reading"
    echo "2 - File Writing with Mode Flags"
    echo "3 - Reading Different Data Types"
    echo "4 - Error Handling"
    echo "5 - Formatted I/O"
    echo "6 - Reading Lines with getline()"
    echo "7 - Combining ifstream and ofstream"
    echo "8 - Object Serialization"
    echo "Enter the numbers of the functions you want to test (e.g., 1,2,3):"
    read -r specificTests
    ./fileIO "$specificTests"
elif [ "$userInput" == "3" ]; then
    # Remove generated files
    rm example.txt numbers.txt input.txt data.txt formatted_output.txt fileIO output.txt 2>/dev/null
    echo "Cleanup complete. All generated files have been removed."
    exit 0
else
    echo "Invalid option. Exiting."
    exit 1
fi
