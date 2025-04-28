import subprocess
import time
import re

def run_command():
    # Command template (use your actual path to PmergeMe if needed)
    command = './PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`'
    
    # Run the command and capture the output
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    
    # Print the output for debugging purposes
    output = result.stdout
    # print("Command Output:", output)  # Debugging line
    
    # Use regex to extract the time in microseconds
    match = re.search(r'Time to process.*?(\d+) us', output)
    
    if match:
        time_taken = int(match.group(1))  # Extract the microseconds
    else:
        time_taken = 0  # Default to 0 if no time found
    
    return time_taken

def main():
    num_runs = 100
    times = []
    
    for _ in range(num_runs):
        time_taken = run_command()
        times.append(time_taken)
    
    # Calculate the average time
    average_time = sum(times) / len(times) if times else 0

    # Calculate the lowest and highest times
    lowest_time = min(times) if times else 0
    highest_time = max(times) if times else 0 

    # Print the results
    print(f"Times: {times}")
    print(f"Average time: {average_time} µs")
    print(f"Lowest time: {lowest_time} µs")
    print(f"Highest time: {highest_time} µs")

if __name__ == '__main__':
    main()
