#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){

enum COL {L=0,D,U,NLDU};
enum state {f=0,t};
enum lu {n=0,id,op,pun,key};
char cha;
char buffer[4096];
COL coltype;


lu lexunit;
state currentstate = f;

 ifstream inputFile("code.txt");

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

 auto characterClassifier = [](char ch)->COL{
   if(islower(ch)|| isupper(ch)) return L;
   if(isdigit(ch)) return D;
   if(ch == '_') return U;
   else return NLDU;

 }  ; 

    while(inputFile.get(cha)){
     coltype =  characterClassifier(cha);
     switch(currentstate){
        case f:
           switch(coltype){
            case L:
            // cout<< "this is a literal"<<"\n";
            lexunit = id;
           cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
           currentstate = t;
            break;

            case D:
            lexunit = op;
           cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
            currentstate = t;
            break;

            case U:
            lexunit = pun;
            cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
             currentstate = t;
            break;

            case NLDU:
            cout<< "this is a nothing"<<"\n";
             currentstate = t;
            break;
           }
        
        case t:
         switch(coltype){
            case L:
            // cout<< "this is a literal"<<"\n";
            lexunit = id;
            cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
            break;

            case D:
            lexunit = op;
            cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
            break;
            
            case U:
            lexunit = pun;
            cout<<"found alphabet "<<cha<<" COL: "<<coltype<<" , LU : "<<lexunit<<"\n";
            break;

            case NLDU:
            cout<< "this is a nothing"<<"\n";
            break;
           }

        
     }
    }

    return 1;
}