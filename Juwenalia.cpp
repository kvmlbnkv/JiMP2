#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <random>
#include <chrono>

using namespace std;

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

    double GetBac(){
        return bac;
    }
};

class Beer: public Proviant{
public:
    Beer():Proviant(0.3, "Beer"){}
};

class Sandwich: public Proviant{
public:
    Sandwich():Proviant(-0.2, "Sandwich"){}
};

class Vodka: public Proviant{
public:
    Vodka():Proviant(1.5, "Vodka"){}
};

class Jupik: public Proviant{
public:
    Jupik():Proviant(-0.1, "Jupik"){}
};

class Wine: public Proviant{
public:
    Wine():Proviant(0.7, "Wine"){}
};

class Kebab: public Proviant{
public:
    Kebab():Proviant(-1, "Kebab"){}
};

class Backpack{
private:
    vector<reference_wrapper<Proviant>> b;
    int products;
public:
    Backpack(){
        this -> products = 0;
    }

    void add(reference_wrapper<Proviant> &p){
        if(!isFull()) {
            b.emplace_back(p);
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
        cout << "Plecak:" << endl;
        for(auto &a:b){
            cout << a.get().GetName();
            i++;
            if(i < b.size()){
                cout << ", " << endl;
            }
        }
    }

    Proviant Last(){
        return b.back();
    }
};


int main(){
    Backpack B;
    int p;
    double bac=0;
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    while(true){
        if(!B.isFull()) {
            p = e()%6+1;
            switch (p) {
                case 1: {
                    auto b = ref<Proviant>(*new Beer);
                    B.add(b);
                }
                    break;
                case 2: {
                    auto b = ref<Proviant>(*new Sandwich);
                    B.add(b);
                }
                    break;
                case 3: {
                    auto b = ref<Proviant>(*new Jupik);
                    B.add(b);
                }
                    break;
                case 4: {
                    auto b = ref<Proviant>(*new Vodka);
                    B.add(b);
                }
                    break;
                case 5: {
                    auto b = ref<Proviant>(*new Wine);
                    B.add(b);
                }
                    break;
                case 6: {
                    auto b = ref<Proviant>(*new Kebab);
                    B.add(b);
                }
                    break;
            }
            bac = bac + B.Last().GetBac();
            if(bac < -0.3){
                bac = -0.3;
            }
            if(bac > 0){
                bac = bac - 0.1;
            }
            if(bac < 0){
                bac = bac + 0.1;
            }
        }
        else{
            B.print();
            cout << endl;
            cout << "No jak bedziesz spozywac produkty w takiej kolejnosci jaka jest w plecaku to ";
            if(bac > 0 && bac <= 0.2){
                cout << "bedzie gituwa";
            }
            else if(bac <= 0){
                cout << "sredniawa zabawa bedzie...";
            }
            else if(bac > 0.2 && bac <= 0.3){
                cout << "zabawa bedzie przednia!";
            }
            else if(bac > 0.3){
                cout << "przeczuwam ze niestety sie zle skonczy :/";
            }
            break;
        }
    }
}
