#include <iostream>
#include <vector>

class List{
    public:
        std::string name;
        std::vector<int> vect;

        List(std::string name, int len){
            name = name;
            vect = std::vector<int>(len);
        }

        void add(int x, int index){
            if(index >= vect.size())vect.resize(index+1);
            vect[index] = x;
        }

        void print(){
            for(int i = 0; i < vect.size(); i++){
                std::cout << vect[i] << std::endl;
            };
        }
};