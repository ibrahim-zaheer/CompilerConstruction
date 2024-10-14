#include <iostream>
#include <vector>

using namespace std;

// Define states
enum State {
    STATE_0,
    STATE_1,
    STATE_2,
    NUM_STATES // Keeps track of the number of states
};

// Define the transition table
State transitionTable[NUM_STATES][2] = {
    {STATE_0, STATE_1}, // Transitions for STATE_0
    {STATE_2, STATE_0}, // Transitions for STATE_1
    {STATE_1, STATE_2}  // Transitions for STATE_2
};

int main() {
    State currentState = STATE_0; // Initial state
    vector<int> inputs = {1, 0, 1, 1, 0}; // Example input sequence

    // Process each input
    for (int input : inputs) {
        currentState = transitionTable[currentState][input]; // Get the next state
        cout << "Current State: " << currentState << endl; // Print current state
    }

    return 0;
}
