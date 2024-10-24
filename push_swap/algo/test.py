import itertools
import subprocess

def main():
    # Generate all unique sequences of numbers from 1 to 5
    sequences = itertools.permutations(range(1, 6), 5)

    # Open a file to write the results
    with open('results.txt', 'w') as result_file:
        for seq in sequences:
            # Convert the tuple to a list of strings
            args = list(map(str, seq))
            
            # Call the C program with the sequence as arguments and capture output
            result = subprocess.run(['./push_swap'] + args, capture_output=True, text=True)
            
            # Get the output and count the number of lines
            output = result.stdout
            line_count = output.count('\n')  # Count newlines in the output

            # Write the sequence, line count, and output to the file
            result_file.write(f"Sequence: {seq} -> Line Count: {line_count}\n")
            # result_file.write("Output:\n")
            # result_file.write(output)
            result_file.write("\n")  # Add a new line for separation

if __name__ == "__main__":
    main()
