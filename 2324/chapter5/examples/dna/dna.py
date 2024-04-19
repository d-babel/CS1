# DNA by Drew Babel

import csv
import sys


def main():
    # check usage
    if len(sys.argv) != 3:
        sys.exit("usage: python dna.py database.csv sequence.txt")

    # read database and DNA sequence
    database, dna_sequence = read_files(sys.argv[1], sys.argv[2])

    # find largest consecutive repeats for each STR in DNA sequence
    str_counts = {
        str_key: longest_run(dna_sequence, str_key)
        for str_key in database[0].keys()
        if str_key != "name"
    }

    # compare database STR counts to DNA sequence STR counts
    for person in database:
        if match_person(person, str_counts):
            print(person['name'])
            return

    print("no match")


def read_files(database_path, sequence_path):
    # load database from CSV file
    with open(database_path, newline='') as file:
        reader = csv.DictReader(file)
        database = list(reader)

    # load DNA sequence from text file
    with open(sequence_path, 'r') as file:
        dna_sequence = file.read().strip()

    return database, dna_sequence


def longest_run(sequence, str_key):
    # find max num that STR appears consecutively in the sequence
    max_count = 0
    n = len(str_key)
    for i in range(len(sequence)):
        count = 0
        while sequence[i + n*count: i + n*(count + 1)] == str_key:
            count += 1
        if count > max_count:
            max_count = count

    return max_count

#ALTHOUGH THIS (PSEUDOCODE) ALGO. CONSISTS OF LESS STEPS, THE TIME TO EXECUTE IS LONGER
# function findLongestSTRRun(DNA_Sequence, STR)
    # max_run = 0
    # current run = 0
    # i = 0

    # while i <= length of DNA_Sequence - length_of_STR
    # if DNA_sequence[i : i+Length_of_STR] == STR
    # current_run = 1
    # j = i + Length of STR

    # while j <= (length of DNA_sequence - length of STR) and DNA_sequence[j:j+length of STR] == STR:
    # current_run += 1
    # j += length of STR


def match_person(person, str_counts):
    # check if STR couts match in person's STR counts in database
    return all(int(person[str_key]) == str_counts[str_key] for str_key in str_counts)


if __name__ == "__main__":
    main()
