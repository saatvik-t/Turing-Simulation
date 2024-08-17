#include <bits/stdc++.h>

using namespace std;

class TuringMachine {
private:
    set<string> states;
    string initial_state;
    set<char> tape_symbols;

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
    }
};

int main() {
    TuringMachine TM;
    TM.get_TM_specs_from_user();
    TM.print_TM_specs();

    return 0;
}