#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Polka{
    VODKA,
    BEER,
    JUPIK,
    SANDWICH,
    KEBAB,
    BURGERZMIASTECZKA,
    SPRITE,
    BANAN,
    WINE,
    SKITELSY
};

class Proviant{
private:
    double bac;
    string name;
public:
    Proviant(double bac, string name){
        this -> bac = bac;
        this -> name = name;
    }

    string GetName(){
        return name;
    }
};

class Beer: public Proviant{
public:
    Beer():Proviant(0.3, "Beer"){}
};

class Sandwich: public Proviant{
public:
    Sandwich():Proviant(0, "Sandwich"){}
};

class Vodka: public Proviant{
public:
    Vodka():Proviant(3, "Vodka"){}
};

class Jupik: public Proviant{
public:
    Jupik():Proviant(0, "Jupik"){}
};

class Wine: public Proviant{
public:
    Wine():Proviant(0.7, "Wine"){}
};

class Kebab: public Proviant{
public:
    Kebab():Proviant(0, "Kebab"){}
};

class Backpack{
private:
    vector<reference_wrapper<Proviant>*> b;
    int products;
public:
    Backpack(){
        this -> products = 0;
    }

    void add(reference_wrapper<Proviant> *p){
        if(!isFull()) {
            b.push_back(p);
            products++;
        }
        else{
            cout << "Plecak pelny!";
        }
    }

    bool isFull(){
        if(b.size()<7){
            return false;
        }
        else{
            return true;
        }
    }

    void print(){
        int i=0;
        for(auto &a:b){
            cout << *a->GetName();
            i++;
            if(i < b.size()){
                cout << ", ";
            }
        }
    }
};


int main(){
    Backpack B;
    int p;
    while(true){
        if(!B.isFull()) {
            p = rand() % 6 + 1;
            switch (p) {
                case 1:
                    B.add(new Beer());
                    break;
                case 2:
                    B.add(new Sandwich());
                    break;
                case 3:
                    B.add(new Vodka());
                    break;
                case 4:
                    B.add(new Jupik());
                    break;
                case 5:
                    B.add(new Wine());
                    break;
                case 6:
                    B.add(new Kebab());
                    break;
            }
            B.print();
        }
    }
}
