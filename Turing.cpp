#include <bits/stdc++.h>

using namespace std;

class TuringMachine {
private:
    set<string> states;
    string initial_state;
    set<char> tape_symbols;
    map<tuple<string, char>, tuple<string, char, char>> transitions;

    bool check_valid_state(string state) {
        return states.find(state) != states.end();
    }

    bool check_valid_symbol(char symbol) {
        return tape_symbols.find(symbol) != tape_symbols.end();
    }

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

        while (true) {
            cout << "Enter initial state: ";
            cin >> initial_state;
            if (check_valid_state(initial_state))
                break;
            cout << "Error: Invalid state" << endl;
        }

        int n_transitions;
        cout << "Enter number of transitions: ";
        cin >> n_transitions;
        for (int i = 0; i < n_transitions; i++) {
            string state, next_state;
            char read_symbol, write_symbol, action;
            cout << "Enter transition (state, read_symbol, next_state, write_symbol, action): ";
            cin >> state >> read_symbol >> next_state >> write_symbol >> action;
            if (!check_valid_state(state) || !check_valid_state(next_state) || !check_valid_symbol(read_symbol) || !check_valid_symbol(write_symbol)) {
                cout << "Error: Invalid state or symbol" << endl;
                i--;
                continue;
            }
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

        cout << "Transitions:\n";
        for (const auto &transition : transitions) {
            string state = get<0>(transition.first);
            char read_symbol = get<1>(transition.first);
            string next_state = get<0>(transition.second);
            char write_symbol = get<1>(transition.second);
            char action = get<2>(transition.second);
            cout << "(" << state << ", " << read_symbol << ") -> (" << next_state << ", " << write_symbol << ", " << action << ")\n";
        }
    }

    void run_TM(string tape, int head_pos) {
        string state = this->initial_state;
        while (true) {
            char tape_symbol = tape[head_pos];
            if (this->transitions.find(make_tuple(state, tape_symbol)) == this->transitions.end()) {
                cout << "Error: No transition found for state " + state + " and symbol " + tape_symbol << endl;
                break;
            }

            tuple<string, char, char> transition = this->transitions[make_tuple(state, tape_symbol)];
            string next_state = get<0>(transition);
            char write_symbol = get<1>(transition);
            char action = get<2>(transition);

            tape[head_pos] = write_symbol;
            if (action == 'L') {
                head_pos--;
            } else if (action == 'R') {
                head_pos++;
            } else if (action == 'Y') {
                cout << "Accepted." << endl;
                break;
            } else if (action == 'N') {
                cout << "Rejected." << endl;
                break;
            }

            state = next_state;

            cout << "Tape: " << tape << " (head at position " << head_pos << ")" << endl;
        }
    }
};

int main() {
    TuringMachine TM;
    TM.get_TM_specs_from_user();
    TM.print_TM_specs();

    string tape = "101";
    int head_pos = 0;
    TM.run_TM(tape, head_pos);

    return 0;
}
