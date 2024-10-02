#include <iostream>
#include <string>
#include <vector> // For using vector

using namespace std;

class Prod {
public:
    struct Rule {
        vector<char> ruleVector; // Vector to store characters
        Rule* next;
        Rule* prev;

        // Constructor to initialize the rule vector
        Rule(const string& ruleString) : next(nullptr), prev(nullptr) {
            // Copy the characters from the ruleString to the vector
            ruleVector.assign(ruleString.begin(), ruleString.end());
        }
    };

    Prod* next;
    Prod* prev;
    Rule* rule;
    string name;

    Prod(const string& Nodename) : name(Nodename), next(nullptr), prev(nullptr), rule(nullptr) {}

    // Method to add a rule
    void AddRule(const string& ruleString) {
        Rule* newRule = new Rule(ruleString);
        if (!rule) {
            rule = newRule;
        } else {
            Rule* temp = rule;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newRule;
            newRule->prev = temp;
        }
    }

    // Method to print rules
    void printRules() {
        if (rule) {
            Rule* temp = rule;
            while (temp) {
                // Print each character from the vector
                for (char c : temp->ruleVector) {
                    cout << c;
                }
                cout << " ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "No rules for " << name << endl;
        }
    }
};

int main() {
    Prod* headProd = nullptr;
    Prod* currentProd = nullptr;
    string stringName;
    string ruleString;

    while (true) {
        cout << "Enter the production name (or 'q' to quit): ";
        getline(cin, stringName);
        if (stringName == "q") {
            break;
        }

        Prod* producing = new Prod(stringName);
        if (!headProd) {
            headProd = producing;
        } else {
            currentProd->next = producing;
            producing->prev = currentProd;
        }
        currentProd = producing;

        while (true) {
            cout << "Enter the rule for production '" << producing->name << "' (must be 5 characters) or 'q' to stop adding rules: ";
            getline(cin, ruleString);
            if (ruleString == "q") {
                break;
            }

            if (ruleString.length() != 5) {
                cout << "The rule must be exactly 5 characters long!" << endl;
                continue;
            }

            currentProd->AddRule(ruleString);
        }
    }

    // Print all productions and their rules
    cout << "\nAll Productions and Rules:\n";
    Prod* tempProd = headProd;
    while (tempProd) {
        cout << "Production: " << tempProd->name << endl;
        cout << "Rules: ";
        tempProd->printRules();
        tempProd = tempProd->next;
    }

    return 0;
}
