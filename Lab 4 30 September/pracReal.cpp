#include <iostream>
#include <string>

using namespace std;

class Prod {
public:
    struct Rule {
        string r;
        Rule* next;
        Rule* prev;

        Rule(const string& ruleString) : r(ruleString), next(nullptr), prev(nullptr) {}
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
                cout << temp->r << " ";
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
            cout << "Enter the rule for production '" << producing->name << "' or 'q' to stop adding rules: ";
            getline(cin, ruleString);
            if (ruleString == "q") {
                break;
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
