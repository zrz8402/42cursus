#!/bin/bash

make

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."

    expect <<EOF
spawn ./test

# Enter the ADD command
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }

# Enter contact details
# Contact 1: John Doe
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "John\r" }
expect "Enter last name:" { send "Doe\r" }
expect "Enter nickname:" { send "Johnny\r" }
expect "Enter phone number:" { send "1234567890\r" }
expect "Enter darkest secret:" { send "Loves pizza\r" }

# Contact 2: Alice Johnson
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Alice\r" }
expect "Enter last name:" { send "Johnson\r" }
expect "Enter nickname:" { send "Ally\r" }
expect "Enter phone number:" { send "555-1234\r" }
expect "Enter darkest secret:" { send "Hates chocolate\r" }

# Contact 3: Bob Smith
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Bob\r" }
expect "Enter last name:" { send "Smith\r" }
expect "Enter nickname:" { send "Bobby\r" }
expect "Enter phone number:" { send "555-2345\r" }
expect "Enter darkest secret:" { send "Lost his job last year\r" }

# Contact 4: Charlie Brown
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Charlie\r" }
expect "Enter last name:" { send "Brown\r" }
expect "Enter nickname:" { send "Chuck\r" }
expect "Enter phone number:" { send "555-3456\r" }
expect "Enter darkest secret:" { send "Failed a big exam\r" }

# Contact 5: David White
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "David\r" }
expect "Enter last name:" { send "White\r" }
expect "Enter nickname:" { send "Dave\r" }
expect "Enter phone number:" { send "555-4567\r" }
expect "Enter darkest secret:" { send "Always forgets birthdays\r" }

# Contact 6: Emma Green
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Emma\r" }
expect "Enter last name:" { send "Green\r" }
expect "Enter nickname:" { send "Em\r" }
expect "Enter phone number:" { send "555-5678\r" }
expect "Enter darkest secret:" { send "Stole a pen from work\r" }

# Contact 7: Fiona Black
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Fiona\r" }
expect "Enter last name:" { send "Black\r" }
expect "Enter nickname:" { send "Fi\r" }
expect "Enter phone number:" { send "555-6789\r" }
expect "Enter darkest secret:" { send "Is scared of spiders\r" }

# Contact 8: George Turner
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "George\r" }
expect "Enter last name:" { send "Turner\r" }
expect "Enter nickname:" { send "Geo\r" }
expect "Enter phone number:" { send "555-7890\r" }
expect "Enter darkest secret:" { send "Never learned to ride a bike\r" }

# Contact 9: Hannah Lee
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Hannah\r" }
expect "Enter last name:" { send "Lee\r" }
expect "Enter nickname:" { send "Han\r" }
expect "Enter phone number:" { send "555-8901\r" }
expect "Enter darkest secret:" { send "Secretly loves reality TV\r" }

# Contact 10: Isaac Harris
expect "Enter a command(ADD, SEARCH, EXIT):" { send "ADD\r" }
expect "Enter first name:" { send "Isaac\r" }
expect "Enter last name:" { send "Harris\r" }
expect "Enter nickname:" { send "Ike\r" }
expect "Enter phone number:" { send "555-9012\r" }
expect "Enter darkest secret:" { send "Hates public speaking\r" }
# Enter the SEARCH command
expect "Enter a command(ADD, SEARCH, EXIT):" { send "SEARCH\r" }
expect "Enter the entry index(0 - 7):" { send "0\r" }

# Exit the program
expect "Enter a command(ADD, SEARCH, EXIT):" { send "EXIT\r" }

# End the expect session
expect eof
EOF
make fclean
else
    echo "Compilation failed."
fi