#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Prod {
public:
    struct Rule {
        vector<char> ruleVector; 
        Rule* next;
        Rule* prev;

       
        Rule(const string& ruleString) : next(nullptr), prev(nullptr) {
           
            ruleVector.assign(ruleString.begin(), ruleString.end());
        }
    };

    Prod* next;
    Prod* prev;
    Rule* rule;
    string name;

    Prod(const string& Nodename) : name(Nodename), next(nullptr), prev(nullptr), rule(nullptr) {}


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

 
    void printRules() {
        if (rule) {
            Rule* temp = rule;
            while (temp) {
               
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

 void addingProductionFunction(  ){
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
            cout << "Enter the rule for production '" << producing->name << "'  or 'q' to stop adding rules: ";
            getline(cin, ruleString);
            if (ruleString == "q") {
                break;
            }

           

            currentProd->AddRule(ruleString);
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


};

int main() {
    // Prod* headProd = nullptr;
    // Prod* currentProd = nullptr;
    // string stringName;
    // string ruleString;

    addingProductionFunction();

    

    return 0;
}
