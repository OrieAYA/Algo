#include <iostream>

class StackNode{

    public:

        StackNode* prev;
        int val;

        StackNode(StackNode* pre, int v){
            prev = pre;
            val = v;
        }

        StackNode(){
            prev = nullptr;
            val = 0;
        }

};

class Stack{

    public:

        StackNode* last;

        Stack(){
            last = nullptr;
        }

        int pop(){
            if (!last) {
            throw std::out_of_range("Stack is empty, cannot pop");
        }
            StackNode* act = last;
            int value = act->val;
            last = last->prev;
            delete act;
            return value;
        }

        int add(int v){
            last = new StackNode(last, v);
        }

};