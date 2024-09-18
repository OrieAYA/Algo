#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int forfunc(int& test){
    for(int i = 0; i < 4; i++){
        test+=i;
        cout << test << endl;
    }
}

int whilefunc(int& test){
    while(test>0){
        cout << test << endl;
        test--;
    }
}

int main() {

    int test(2); //var
    int& val(test); //reference (call)

    whilefunc(test);

    forfunc(test);

    vector<int> vect(5, 2); //dynamic table
    vect.push_back(8); //add val 8
    vect.pop_back();

    int *pointeur(0);

    pointeur = &test;

    cout << pointeur << endl;

    pointeur = new int;

    *pointeur = 2;

    cout << *pointeur << endl;

    return 0;
}