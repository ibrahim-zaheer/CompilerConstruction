#include <iostream>
#include <fstream>
#include <cctype>

void genToken(const char *lex, const char *tokenType) {
    std::cout << "Token: " << tokenType << ", Lexeme: " << lex << std::endl;
}

int main() {
    int state{}, li{} , bi{};
    char ch{};
    char lexeme[100]{};
    constexpr size_t buffer_size{50};
    char buffer[buffer_size + 1]{};

    std::ifstream file("code.txt");
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    file.read(buffer, buffer_size);

    while (file.gcount() > 0)
    {
       ch = buffer[bi++];

       switch (state)
       {
           case 0:
               if (ch == '_' || isalpha(ch))
               {
                   lexeme[li++] = ch;
                   state = 1;
               }
           break;

           case 1:
               if (ch == '_' || isalpha(ch) || isdigit(ch))
               {
                   lexeme[li++] = ch;
               }
               else
               {
                   lexeme[li] = '\0';
                   li = 0;
                   state = 2;
               }
           break;

           case 2:
               bi--;
               genToken(lexeme, "ID");
               state = 0;
               li = 0;
           break;
       }

        if(bi == buffer_size) {
            file.read(buffer, buffer_size);
            bi = 0;
        }
   }

    file.close();

    return 0;
}