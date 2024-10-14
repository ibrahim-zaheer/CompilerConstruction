#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct Token{
    char lex[100];
    char type[100];
};

void genToken(const char* lex, const char* type) {
    cout << "Token: " << lex << ", Type: " << type<< endl;
}

int main(){
    int state=0;
    char ch;
    char lex[100];
    int li=0;
    char buffer[4096];

    const char* filename = "code.txt";
    ifstream file(filename, ios::binary);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    int bi = 0;
    file.read(buffer, 4096);
    int length = file.gcount();

    while(bi < length){
         ch = buffer[bi];
        switch (state) {
            case 0:
                if (isalpha(ch) || ch == '_') {
                    state = 1;
                    lex[li++] = ch;
                }
                break;

            case 1:
                if (isalpha(ch) || isdigit(ch) || ch == '_') {
                    lex[li++] = ch;
                } else {
                    state = 2;
                    lex[li] = '\0';
                }
                break;

            case 2:
                bi-=2;
                genToken(lex, "ID");
                state = 0;
                li = 0;
                break;
        }
        bi++;
    }  
    if (state == 1) {
        lex[li] = '\0';
        genToken(lex, "ID");
    }

}