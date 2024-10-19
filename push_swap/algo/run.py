import subprocess

def run_scripts(num_runs, output_file):
    with open(output_file, 'w') as file:
        for i in range(num_runs):
            print(f"Run {i + 1}:")

            # Run num.py and capture output
            try:
                a_output = subprocess.check_output(['python', 'num.py']).decode('utf-8').strip()
                file.write(f"Run {i + 1} - num.py output: {a_output}\n")
            except subprocess.CalledProcessError as e:
                file.write(f"Run {i + 1} - num.py error: {e}\n")

            # Run lis.py and capture output
            try:
                b_output = subprocess.check_output(['python', 'lis.py']).decode('utf-8').strip()
                file.write(f"Run {i + 1} - lis.py output: {b_output}\n")
            except subprocess.CalledProcessError as e:
                file.write(f"Run {i + 1} - lis.py error: {e}\n")

if __name__ == "__main__":
    run_scripts(100, 'results.txt')
    print("Results have been written to results.txt.")