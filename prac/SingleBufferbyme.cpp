#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(){

char buffer[]{};
int state = 0;
char ch{};
int bi{};
int li{};
char lexeme[]{};
// int buffersize = 100;
constexpr size_t buffersize{50};

ifstream file("code.txt");
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    file.read(buffer, buffersize);

    while (file.gcount()>0)
    {
        ch = buffer[bi++];
        switch (state)
        {
        case 0:
             if(ch == '_' || isalpha(ch))
             lexeme[li++] = ch;
             state = 1;
            break;
        case 1:
             if(ch == '_'|| isalpha(ch)|| isdigit(ch)){
                lexeme[li++] = ch;
             }
            break;
              
        default:
            break;
        }
    }
    


    return 1;
}