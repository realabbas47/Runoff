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
void print_winner(void);
void sortcandidates(void);

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

    // Sort based on votes
    sortcandidates();

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int vts = candidates[0].votes;
    for (int i = 1; i < candidate_count; ++i)
    {
        if (candidates[i].votes > vts)
        {
            vts = candidates[i].votes;
        }
    }

    // Printing winners
    for (int i = 0; i < candidate_count; ++i)
    {
        if (candidates[i].votes == vts)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

// Sorting candidates based on votes using bubble sort.
void sortcandidates(void)
{
    string tn = "";
    int tv = 0;
    int flag = 0;
    do
    {
        flag = 0;
        for (int i = 0; i < candidate_count - 1; i++)
        {
            if (candidates[i].votes < candidates[i + 1].votes)
            {
                tn = candidates[i].name;
                tv = candidates[i].votes;

                candidates[i].name = candidates[i + 1].name;
                candidates[i].votes = candidates[i + 1].votes;

                candidates[i + 1].name = tn;
                candidates[i + 1].votes = tv;
                flag = 1;
            }
        }
    } while (flag == 1);
    return;
}