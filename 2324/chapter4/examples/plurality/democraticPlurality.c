// Plurality by Drew Babel

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void quick_sort(int low, int high);
int partition(int low, int high);
void print_candidates_sorted(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // display candidates sorted by votes
    print_candidates_sorted();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// quick sort function to sort candidates by vote in descending order
// https://stackoverflow.com/questions/20835441/my-quicksort-function-and-partition
void quick_sort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);

        quick_sort(low, pi - 1);
        quick_sort(pi + 1, high);
    }
}

// partition function used by quick sort w changed vars
// https://stackoverflow.com/questions/20835441/my-quicksort-function-and-partition
int partition(int low, int high)
{
    int pivot = candidates[high].votes;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (candidates[j].votes > pivot)
        {
            i++;
            candidate temp = candidates[i];
            candidates[i] = candidates[j];
            candidates[j] = temp;
        }
    }
    candidate temp = candidates[i + 1];
    candidates[i + 1] = candidates[high];
    candidates[high] = temp;
    return (i + 1);
}

void print_candidates_sorted(void)
{
    // call quick sort on array of candidates
    quick_sort(0, candidate_count - 1);

    // print  sorted array of candidates
    printf("\n\n");

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s: %i\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}
