#include <iostream>
#include <string>

using namespace std;

struct Prod;

struct Rule {
    string r;
    Rule* next;
    Rule* prev;

    Rule(const string& ruleString)
        : r(ruleString), next(nullptr), prev(nullptr) {}
};

struct Prod {
    string name;
    Prod* prev;
    Prod* next;
    Rule* ruleNode;

    Prod(const string& nonTerminalName)
        : name(nonTerminalName), prev(nullptr), next(nullptr), ruleNode(nullptr) {}
};

void addRule(Prod* prod, const string& ruleString) {
    Rule* newRule = new Rule(ruleString);

    if (!prod->ruleNode) {
        prod->ruleNode = newRule;
    } else {
        Rule* temp = prod->ruleNode;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newRule;
        newRule->prev = temp;
    }
}

void printRules(Prod* prod) {
    Rule* temp = prod->ruleNode;
    cout << "Production " << prod->name << ": ";
    while (temp) {
        cout << temp->r << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Prod* firstProd = new Prod("S");
    Prod* secondProd = new Prod("A");

    addRule(firstProd, "A");
    addRule(firstProd, "B");

    addRule(secondProd, "a");
    addRule(secondProd, "A");

    firstProd->next = secondProd;
    secondProd->prev = firstProd;

    printRules(firstProd);
    printRules(secondProd);

    Prod* headProd = nullptr;
    Prod* currentProd = nullptr;

    string prodName;
    string ruleString;

    while (true) {
        cout << "Enter production name or 'q' to quit: ";
        getline(cin, prodName);

        if (prodName == "q") {
            break;
        }

        Prod* newProd = new Prod(prodName);

        if (!headProd) {
            headProd = newProd;
        } else {
            currentProd->next = newProd;
            newProd->prev = currentProd;
        }

        currentProd = newProd;

       
        while (true) {
            cout << "Enter rule for production '" << prodName << "' (or 'q' to stop adding rules): ";
            getline(cin, ruleString);

            if (ruleString == "q") {
                break;
            }

            addRule(currentProd, ruleString);
        }
    }

    cout << "\nAll Productions:\n";
    Prod* tempProd = headProd;
    while (tempProd) {
        printRules(tempProd);
        tempProd = tempProd->next;
    }

    return 0;
}
