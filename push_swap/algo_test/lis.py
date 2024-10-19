def longest_increasing_subsequence(a):
    n = len(a)
    if n == 0:
        return []

    dp = [1] * n  # dp[i] will be the length of the LIS ending at index i
    prev = [-1] * n  # To reconstruct the LIS

    for i in range(1, n):
        for j in range(i):
            if a[i] > a[j]:
                if dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    prev[i] = j  # Track the previous index

    max_length = max(dp)
    index = dp.index(max_length)

    b = []
    while index != -1:
        b.append(a[index])
        index = prev[index]

    b.reverse()  # Reverse to get the correct order
    return b

def get_remaining_elements(a, b):
    remaining = []
    b_set = set(b)  # Use a set for O(1) lookups
    for element in a:
        if element not in b_set:
            remaining.append(element)
    return remaining

def recursive_lis_sequences(a):
    if not a:  # Base case: If a is empty, return an empty list
        return []

    b = longest_increasing_subsequence(a)  # Find the LIS b
    remaining_elements = get_remaining_elements(a, b)  # Get remaining elements
    return [b] + recursive_lis_sequences(remaining_elements)  # Collect sequences recursively

# Step 5: Read the array from a file
def read_array_from_file(filename):
    with open(filename, 'r') as file:
        return [int(line.strip()) for line in file.readlines()]

# Example usage
filename = 'numbers.txt'
a = read_array_from_file(filename)
sequences = recursive_lis_sequences(a)

# print("Input Array:", a)
# print("Sequences of Longest Increasing Subsequences:", sequences)

# Write to a text file
# with open('output.txt', 'w') as file:
#     for item in sequences:
#         file.write(item + '\n')

with open('lis.txt', 'w') as file:
    file.write(str(len(sequences)) + '\n')
    for item in sequences:
        file.write(str(len(item)) + '\n')
        file.write(' '.join(map(str, item)) + '\n') 
# Alternatively, using join()
# with open('lis.txt', 'w') as file:
#     file.write(str(len(sequences)) + '\n')
#     file.write('\n'.join(sequences) + '\n') 