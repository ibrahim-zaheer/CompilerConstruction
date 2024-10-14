#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    enum COL { L = 0, D, U, NLDU, A, R, T };
    enum state { f = 0, t };
    enum lu { n = 0, id, op, pun, key };
    
    char len[100];  
    int li = 0;     
    state currentState = f;
    char cha;

    COL colType;
    lu lexUnit;

    ifstream inputFile("code.txt");

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

   
    auto classifyCharacter = [](char c) -> COL {
        if (islower(c)) return L;
        if (isupper(c)) return U;
        if (isdigit(c)) return D;
        if (isspace(c)) return NLDU;
        return A;  
    };

    // Process each character
    while (inputFile.get(cha)) {
        colType = classifyCharacter(cha);

        switch (currentState) {
            case f:
                switch (colType) {
                    case L:
                    case U:
                        lexUnit = id;
                        cout << "Found alphabet: " << cha << " (COL: "
                             << (colType == L ? "L" : "U") << ", LU: id)" << endl;
                        currentState = t;
                        break;

                    case D:
                        lexUnit = op;
                        cout << "Found digit: " << cha << " (COL: D, LU: op)" << endl;
                        currentState = t;
                        break;

                    case NLDU:
                        lexUnit = pun;
                        cout << "Found space or newline" << endl;
                        break;

                    case A:
                        lexUnit = pun;
                        cout << "Found special character: " << cha << " (COL: A, LU: pun)" << endl;
                        break;
                    
                    default:
                        cout << "Unknown character" << endl;
                        break;
                }
                break;

            case t:
                switch (colType) {
                    case L:
                    case U:
                        lexUnit = id;
                        cout << "Found alphabet: " << cha << " (COL: "
                             << (colType == L ? "L" : "U") << ", LU: id)" << endl;
                        break;

                    case D:
                        lexUnit = op;
                        cout << "Found digit: " << cha << " (COL: D, LU: op)" << endl;
                        currentState = f;
                        break;

                    case NLDU:
                        lexUnit = pun;
                        cout << "Found space or newline" << endl;
                        currentState = f;
                        break;

                    case A:
                        lexUnit = pun;
                        cout << "Found special character: " << cha << " (COL: A, LU: pun)" << endl;
                        currentState = f;
                        break;

                    default:
                        cout << "Unknown character" << endl;
                        break;
                }
                break;
        }
    }

    inputFile.close();
    return 0;
}