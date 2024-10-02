#include<iostream>
#include<stdio.h>
using namespace std;


struct Rule{
    string r;
    Rule* next;
    Rule* prev;
    Rule(const string& ruleString): r(ruleString), next(nullptr), prev(nullptr){}
};

struct Prod{
    Prod* next;
    Prod* prev;
    Rule* rule;
    string name;
    Prod(const string& Nodename): name(Nodename),next(nullptr),prev(nullptr),rule(nullptr){}
};

void AddRule(Prod* prod,string& ruleString){
         Rule* ruleStrings = new Rule(ruleString);
         if(!prod->rule){
            prod->rule = ruleStrings;
         }
         Rule* temp = prod->rule;
         while(temp->next){
           temp = temp->next;
         }
         temp->next = ruleStrings;
         ruleStrings->prev = temp;

}
void printRule(Prod* prod){
    Prod* prodPrint = prod;
    if(prodPrint->rule){
        Rule* temp = prod->rule;
        while(temp->next){
         cout<< temp->r;

         temp = temp->next;
        }
    }
}

int main(){
    Prod* headProd;
    Prod* currentProd;
    string stringName;
    string ruleString;
while(true){
    cout<<"enter the name"<<endl;
    getline(cin,stringName);
    Prod* producing = new Prod(stringName);
    if(!headProd){
     headProd = producing;
    }
    else{
      currentProd->next = producing;
      producing->prev = currentProd;
    }
    currentProd = producing;
     while (true) {

            cout << "Enter the rule for production '" << producing << "' or 'q' to stop adding rules ";
            
            getline(cin, ruleString);



            if (ruleString == "q") {


                break;


            }

            AddRule(currentProd, ruleString);
        }
    }
 cout << "\nAll Productions:\n";
    Prod* tempProd = headProd;
    while (tempProd) {
        printRule(tempProd);


        tempProd = tempProd->next;
    }

    return 0;


}
