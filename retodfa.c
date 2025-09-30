#include <stdio.h>
#include <string.h>

// DFA states
#define Q0 0
#define Q1 1
#define Q2 2

// DFA transition function
int transition(int state, char symbol) {
    switch (state) {
        case Q0:
            if (symbol == '0') return Q1;
            else if (symbol == '1') return Q0;
            break;
        case Q1:
            if (symbol == '0') return Q1;
            else if (symbol == '1') return Q2;
            break;
        case Q2:
            if (symbol == '0') return Q1;
            else if (symbol == '1') return Q0;
            break;
    }
    return -1; // Invalid
}

// Simulate DFA
int simulateDFA(char *input) {
    int state = Q0; // start state
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("Invalid character '%c' in input.\n", input[i]);
            return 0;
        }
        state = transition(state, input[i]);
    }
    return (state == Q2); // accept if final state is q2
}

int main() {
    char *testStrings[] = {"1101", "111", "0001"};
    int n = 3;

    printf("RE: (0|1)*01\n");
    printf("Accepting condition: String ends with 01\n\n");

    for (int i = 0; i < n; i++) {
        printf("String: %s -> ", testStrings[i]);
        if (simulateDFA(testStrings[i]))
            printf("Accepted ✅\n");
        else
            printf("Rejected ❌\n");
    }

    return 0;
}
