#include <bits/stdc++.h>

using namespace std;

class TuringMachine {
private:
    set<string> states;
    string initial_state;
    set<char> tape_symbols;
    map<tuple<string, char>, tuple<string, char, char>> transitions;

public:
    void get_TM_specs_from_user() {
        int n_states;
        cout << "Enter number of states: ";
        cin >> n_states;
        for (int i = 0; i < n_states; i++) {
            string state;
            cout << "Enter state " << i + 1 << ": ";
            cin >> state;
            this->states.insert(state);
        }

        int n_tape_symbols;
        cout << "Enter number of tape symbols: ";
        cin >> n_tape_symbols;
        for (int i = 0; i < n_tape_symbols; i++) {
            char symbol;
            cout << "Enter tape symbol " << i + 1 << ": ";
            cin >> symbol;
            this->tape_symbols.insert(symbol);
        }

        cout << "Enter initial state: ";
        cin >> initial_state;

        int n_transitions;
        cout << "Enter number of transitions: ";
        cin >> n_transitions;
        for (int i = 0; i < n_transitions; i++) {
            string state, next_state;
            char read_symbol, write_symbol, action;
            cout << "Enter transition (state, read_symbol, next_state, write_symbol, action): ";
            cin >> state >> read_symbol >> next_state >> write_symbol >> action;
            transitions[make_tuple(state, read_symbol)] = make_tuple(next_state, write_symbol, action);
        }
    }

    void print_TM_specs() {
        cout << "States: {";
        for (const auto &state : states) {
            cout << state << " ";
        }
        cout << "}\n";

        cout << "Tape symbols: {";
        for (const auto &symbol : tape_symbols) {
            cout << symbol << " ";
        }
        cout << "}\n";

        cout << "Initial state: " << initial_state << endl;

        cout << "Transitions: " << endl;
        for (const auto &transition : transitions) {
            string state = get<0>(transition.first);
            char read_symbol = get<1>(transition.first);
            string next_state = get<0>(transition.second);
            char write_symbol = get<1>(transition.second);
            char action = get<2>(transition.second);
            cout << "(" << state << ", " << read_symbol << ") -> (" << next_state << ", " << write_symbol << ", " << action << ")\n";
        }
    }
};

int main() {
    TuringMachine TM;
    TM.get_TM_specs_from_user();
    TM.print_TM_specs();

    return 0;
}
