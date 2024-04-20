import csv
import time

def read_database(database_path):
    with open(database_path, newline='') as file:
        reader = csv.DictReader(file)
        return next(reader)  # Assuming first row contains the STR names

def read_sequence(sequence_path):
    with open(sequence_path, 'r') as file:
        return file.read().strip()

def find_repeated_strings(source, substring):
    max_count = 0
    index = source.find(substring)
    if index < 0:
        return -1  # Return -1 if the substring is not found at all

    while index != -1:  # Change the condition to check 'index' instead of finding substring again
        count = 0
        while True:
            source = source[index + len(substring):]  # Move the start beyond the current match
            count += 1
            index = source.find(substring)  # Update index based on the new source position
            if index != 0:  # Check if the new substring is not at the start
                break
        if count > max_count:
            max_count = count
        index = source.find(substring)  # Refresh the index for the while loop condition

    return max_count

def main():
    database_path = "databases/large.csv"  # Path to the CSV file containing the STRs
    str_data = read_database(database_path)
    str_keys = [key for key in str_data.keys() if key != 'name']  # Extract STR names

    print("File, STR, New Method Time (s)")

    sequence_base_path = "sequences/"  # Base path to the directory with DNA sequence files
    for i in range(1, 21):  # Loop over each file from 1.txt to 20.txt
        sequence_file = f"{sequence_base_path}{i}.txt"
        dna_sequence = read_sequence(sequence_file)

        for str_key in str_keys:  # Test each STR key in the database
            start_time = time.perf_counter()
            find_repeated_strings(dna_sequence, str_key)
            elapsed_time = time.perf_counter() - start_time

            print(f"{i}.txt, {str_key}, {elapsed_time}")

if __name__ == "__main__":
    main()
