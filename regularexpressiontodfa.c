#include <stdio.h>
#include <string.h>

// Define DFA
#define STATES 4
#define ALPHABET 2  // a=0, b=1

// Transition table: transitions[state][input]
int transitions[STATES][ALPHABET] = {
    {1, 0}, // q0: on 'a' -> q1, on 'b' -> q0
    {1, 2}, // q1: on 'a' -> q1, on 'b' -> q2
    {1, 3}, // q2: on 'a' -> q1, on 'b' -> q3
    {1, 0}  // q3: on 'a' -> q1, on 'b' -> q0
};

int start_state = 0;
int accept_state = 3;

// Function to simulate DFA on input string
int simulateDFA(char *input) {
    int state = start_state;
    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        int col;

        if (symbol == 'a')
            col = 0;
        else if (symbol == 'b')
            col = 1;
        else {
            printf("Invalid character '%c' in input.\n", symbol);
            return 0;
        }

        state = transitions[state][col];
    }
    return state == accept_state;
}

int main() {
    // Print DFA transition table
    printf("DFA Transition Table for (a|b)*abb\n");
    printf("States: q0 q1 q2 q3\n");
    printf("Start State: q0\n");
    printf("Accept State: q3\n\n");

    printf("-----------------------------------\n");
    printf("State\t|   a   |   b   \n");
    printf("-----------------------------------\n");
    for (int i = 0; i < STATES; i++) {
        printf("q%d\t|  q%d   |  q%d\n", i, transitions[i][0], transitions[i][1]);
    }
    printf("-----------------------------------\n\n");

    // Test DFA with user input
    char input[100];
    printf("Enter a string of a's and b's: ");
    scanf("%s", input);

    if (simulateDFA(input))
        printf("✅ Accepted: The string matches (a|b)*abb\n");
    else
        printf("❌ Rejected: The string does not match (a|b)*abb\n");

    return 0;
}
