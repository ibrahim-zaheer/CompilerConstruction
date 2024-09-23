#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    // char data;
    string data;
    Node* next;
};
struct Nodes
{
    // char data;
    string data;
    Nodes* next;
    Nodes* prev;
};


class LinkedList{
    Node* head ;
  

    public:
      LinkedList(): head(NULL){

        }

    void Insert(string data){

Node* newNode = new Node();


newNode->data = data;



newNode->next=NULL;


 if(!head){
       head = newNode;
       return; 
    }  
    Node* temp = head;
    while(temp->next){
temp = temp->next;
    }
    temp->next = newNode;

    }

    void display(){
        
        if(!head){
            return;
        }
        
            Node* temp = head;
            while (temp)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            
        
    }
     
      

};




class DoublyLinkedList{
    Nodes* head ;
  

    public:
      DoublyLinkedList(): head(NULL){

        }

    void Insert(string data){

Nodes* newNode = new Nodes();


newNode->data = data;



newNode->next=NULL;
newNode->prev=NULL;


 if(!head){
       head = newNode;
       return; 
    }  
    Nodes* temp = head;
    while(temp->next){
        temp = temp->prev;
temp = temp->next;
    }
    temp->next = newNode;

    }

    void display(){
        
        if(!head){
            return;
        }
        
            Nodes* temp = head;
            while (temp)
            {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            
        
    }
     
      

};



int main(){
    LinkedList LL;
    string c;
for (int i = 0; i < 10; i++)
{
   cout<<"enter the charcater"<<endl;
    cin>>c;
    LL.Insert(c);
}

    
    
    LL.display();
}


