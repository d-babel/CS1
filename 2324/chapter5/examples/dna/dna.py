import csv
import time

def read_database(database_path):
    with open(database_path, newline='') as file:
        reader = csv.DictReader(file)
        return next(reader)  # Returns the first row assuming it contains the STR names

def read_sequence(sequence_path):
    with open(sequence_path, 'r') as file:
        return file.read().strip()

def original_longest_run(sequence, str_key):
    max_count = 0
    n = len(str_key)
    for i in range(len(sequence)):
        count = 0
        while sequence[i + n * count: i + n * (count + 1)] == str_key:
            count += 1
        max_count = max(max_count, count)
    return max_count

def sliding_window_longest_run(sequence, str_key):
    max_run = 0
    current_run = 0
    i = 0
    length_of_sequence = len(sequence)
    length_of_str = len(str_key)
    while i <= length_of_sequence - length_of_str:
        if sequence[i: i + length_of_str] == str_key:
            current_run = 1
            j = i + length_of_str
            while j <= length_of_sequence - length_of_str and sequence[j: j + length_of_str] == str_key:
                current_run += 1
                j += length_of_str
            max_run = max(max_run, current_run)
            i = j
        else:
            i += 1
    return max_run

def harvard_longest_run(sequence, subsequence):
    longest_run = 0
    sub_len = len(subsequence)
    seq_len = len(sequence)
    for i in range(seq_len):
        count = 0
        while True:
            start = i + count * sub_len
            end = start + sub_len
            if end <= seq_len and sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run

def main():
    # Read STRs from the database
    database_path = "databases/large.csv"
    str_data = read_database(database_path)
    str_keys = [key for key in str_data.keys() if key != 'name']  # Exclude the 'name' field

    print("File,STR,Original Method Time (s),Sliding Window Method Time (s),Harvard Solution Time (s)")

    sequence_base_path = "sequences/"
    for i in range(1, 21):
        sequence_file = f"{sequence_base_path}{i}.txt"
        dna_sequence = read_sequence(sequence_file)

        for str_key in str_keys:
            start_time = time.perf_counter()
            original_longest_run(dna_sequence, str_key)
            original_time = time.perf_counter() - start_time

            start_time = time.perf_counter()
            sliding_window_longest_run(dna_sequence, str_key)
            sliding_time = time.perf_counter() - start_time

            start_time = time.perf_counter()
            harvard_longest_run(dna_sequence, str_key)
            harvard_time = time.perf_counter() - start_time

            print(f"{i}.txt,{str_key},{original_time},{sliding_time},{harvard_time}")

if __name__ == "__main__":
    main()
