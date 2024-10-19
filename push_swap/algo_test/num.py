import random
from itertools import permutations

def generate_unique_numbers(count):
    # Generate all possible unique numbers from digits 0-9
    digits = list(range(10))
    all_unique_numbers = [''.join(map(str, perm)) for perm in permutations(digits)]
    
    # Shuffle the list to randomize the selection
    random.shuffle(all_unique_numbers)

    # Select the first 'count' numbers
    selected_numbers = all_unique_numbers[:count]
    
    return selected_numbers

def write_to_file(filename, numbers):
    with open(filename, 'w') as file:
        for number in numbers:
            file.write(f"{number}\n")

# Example usage:
count = 500
unique_numbers = generate_unique_numbers(count)

# Write to a file
write_to_file('numbers.txt', unique_numbers)

print(f"{count} unique numbers generated and written to 'numbers.txt'.")