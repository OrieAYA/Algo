#include <iostream>

class FileNode{

    public:

        int value;
        FileNode* prev;

        FileNode(int val){
            prev = nullptr;
            value = val;
        }
};

class File{

    public:

        FileNode* Last;
        FileNode* First;

        File(){
            Last = nullptr;
            First = nullptr;
        }

        int queue(int v){
            FileNode* act = new FileNode(v);
            if(!First){
                First = act;
            }
            else{
                Last->prev = act;
            }
            Last = act;
        }

        int dequeue(){
            if(!First)throw std::out_of_range("File is empty, cannot dequeue");
            int value = First->value;
            First = First->prev;
            return value;
        }
};