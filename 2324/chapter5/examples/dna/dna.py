# DNA by Drew Babel

import csv
import sys

def main():
    #check usage
    if len(sys.argv) != 3:
        sys.exist("usage: python dna.py database.csv sequence.txt")

    #read database and DNA sequence
    database, dna_sequence = read_files(sys.argv[1], sys.argv[2]) #FUNCTION

    #find largest consecutive repeats for each STR in DNA sequence
    str_counts = {
        str_key: longest_run(dna_sequence, str_key) #FUNCTION
        for str_key in database[0].keys()
        if str_key != "name"
    }

    #compare database STR counts to DNA sequence STR counts
    for person in databse:
        if match_person(person, str_counts): #FUNCTION
            print(person['name'])
            return

    print("no match")


def read_files(database_path, sequence_path):



def longest_run(sequence, str_key):



def match_person(person, str_counts):



if __name__ == "__main__":
main()
