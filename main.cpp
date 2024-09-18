#include <stdio.h>
#include <iostream>
#include <vector>
#include "List.cpp"
#include "ChainList.cpp"
#include "Stack.cpp"
#include "File.cpp"

using namespace std;

int main() {

    File f;

    f.queue(5);
    f.queue(2);

    cout << f.dequeue() << endl;
    cout << f.dequeue() << endl;

    return 0;
}