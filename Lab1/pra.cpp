#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

int arr[] = {10,20,50};   //1000 1001 1002

int* arrptr = arr;

for (int i = 0; i < 3; i++)
{
    cout<<*arrptr<<endl;
    arrptr++;
}


   return 0;
}