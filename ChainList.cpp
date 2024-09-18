#include <iostream>

class DoubleChainedNode{
    public:
        DoubleChainedNode* prev;
        int val;
        DoubleChainedNode* next;

        DoubleChainedNode(DoubleChainedNode* pre){
            prev = pre;
            val = 0;
            if (pre) pre->next = this;
            next = nullptr;
        }

        DoubleChainedNode(DoubleChainedNode* pre, int v){
            prev = pre;
            val = v;
            if (pre) pre->next = this;
            next = nullptr;
        }

        DoubleChainedNode(DoubleChainedNode* pre, int v, DoubleChainedNode* nex){
            prev = pre;
            val = v;
            if (pre) pre->next = this;
            next = nex;
            if (nex) nex->prev = this;
        }

        DoubleChainedNode(int v, DoubleChainedNode* nex){
            prev = nullptr;
            val = v;
            next = nex;
            if (nex) nex->prev = this;
        }

        DoubleChainedNode(){
            prev = nullptr;
            next = nullptr;
            val = 0;
        }

};

class ChainList{
    public:
        DoubleChainedNode* root;
        DoubleChainedNode* last;
        int len;

        ChainList(int x){
            root = new DoubleChainedNode();
            DoubleChainedNode* act = root;
            for(int i = 1; i < x; i++){
                act = new DoubleChainedNode(act);
            }
            last = act;
            len = x;
        }

        int insert(int val, int index){
            if(index > len)throw std::out_of_range("Index out of range");

            if (index == len)
            {
                DoubleChainedNode* newNode = new DoubleChainedNode(last, val);
                last = newNode;
            }
            else if(index == 0)
            {
                DoubleChainedNode* newNode = new DoubleChainedNode(val, root);
                root = newNode;
            }
            else{
                DoubleChainedNode* act = parcours(index);
                DoubleChainedNode* newNode = new DoubleChainedNode(act->prev, val, act);
            }

            len++;
        }

        int remove(int index){
            if(index > len)throw std::out_of_range("Index out of range");

            DoubleChainedNode* act = new DoubleChainedNode();

            if (index == len)
            {
                act = last;
                last = last->prev;
                if (last) last->next = nullptr;
                act->prev = nullptr;
            }
            else if(index == 0)
            {
                act = root;
                root = root->next;
                if (root) root->prev = nullptr;
                act->next = nullptr;
            }
            else{
                act = parcours(index);
                if(act->prev)act->prev->next = act->next;
                if(act->next)act->next->prev = act->prev;
                delete act;
            }

            len--;
        }

        DoubleChainedNode* parcours(int index){
            if (index < 0 || index >= len) {
                throw std::out_of_range("Index out of range");
            }

            DoubleChainedNode* act;

            if(index>=len/2){
                act = last;
                for(int i = len - 1; i > index; i--){
                    act = act->prev;
                }
            }
            else{
                act = root;
                for(int i = 0; i < index; i++){
                    act = act->next;
                }
            }
            return act;
        }

        int changeVal(int val, int index){
            parcours(index)->val = val;
        }

        int print(){
            DoubleChainedNode* act = root;
            while(act != nullptr){
                std::cout << act->val << std::endl;
                act = act->next;
            }
        }

};