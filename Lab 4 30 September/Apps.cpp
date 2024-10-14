#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Prod {
public:
    struct Rule {
        vector<string> terms;
        Rule* next;
        Rule* prev;

        Rule(const vector<string>& ruleTerms) : terms(ruleTerms), next(nullptr), prev(nullptr) {}
    };

    Prod* next;
    Prod* prev;
    Rule* first_rule;
    Rule* last_rule;
    string name;

    Prod(const string& Nodename) : name(Nodename), next(nullptr), prev(nullptr), first_rule(nullptr), last_rule(nullptr) {}

    void AddRule(const vector<string>& ruleTerms) {
        Rule* newRule = new Rule(ruleTerms);
        if (!first_rule) {
            first_rule = last_rule = newRule;
        } else {
            last_rule->next = newRule;
            newRule->prev = last_rule;
            last_rule = newRule;
        }
    }

    void printRules() {
        if (first_rule) {
            Rule* temp = first_rule;
            while (temp) {
                for (size_t i = 0; i < temp->terms.size(); ++i) {
                    cout << temp->terms[i] << (i < temp->terms.size() - 1 ? " " : "");
                }
                cout << " | ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "No rules for " << name << endl;
        }
    }
};

void addingProductionFunction() {
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

            vector<string> ruleTerms;
            size_t pos = 0;
            while ((pos = ruleString.find(' ')) != string::npos) {
                ruleTerms.push_back(ruleString.substr(0, pos));
                ruleString.erase(0, pos + 1);
            }
            if (!ruleString.empty()) {
                ruleTerms.push_back(ruleString);
            }

            currentProd->AddRule(ruleTerms);
        }
    }

    cout << "\nAll Productions and Rules:\n";
    Prod* tempProd = headProd;
    while (tempProd) {
        cout << "Production: " << tempProd->name << endl;
        cout << "Rules: ";
        tempProd->printRules();
        tempProd = tempProd->next;
    }
}

int main() {
    addingProductionFunction();
    return 0;
}
