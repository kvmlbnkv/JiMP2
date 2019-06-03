#include<iostream>
#include<vector>
using namespace std;

class IterableIterator {
public:
    virtual IterableIterator &Next()= 0;
    virtual pair<int, string> Dereference()= 0;
    virtual bool NotEquals(IterableIterator &other)= 0;
    virtual ~IterableIterator() = default;
};

class ZipperIterator :public IterableIterator {
private:
    vector<int>::const_iterator first_current;
    vector<int>::const_iterator first_begin;
    vector<int>::const_iterator first_end;
    vector<string>::const_iterator second_current;
    vector<string>::const_iterator second_begin;
    vector<string>::const_iterator second_end;
public:
    explicit ZipperIterator(vector<int>::const_iterator first_begin, vector<int>::const_iterator first_end, vector<string>::const_iterator second_begin, vector<std::string>::const_iterator second_end){
        this -> first_current = first_begin;
        this -> first_begin = first_begin;
        this -> first_end = first_end;
        this -> second_current = second_begin;
        this -> second_begin = second_begin;
        this -> second_end = second_end;
    }

    ZipperIterator &Next() override{
        if(first_current != first_end)
            first_current++;
        if(second_current != second_end)
            second_current++;
        return *this;
    }

    pair<int, string> Dereference() override{
        return {*first_current, *second_current};
    }

    bool NotEquals(IterableIterator &other) override{
        return (this -> Dereference().first != other.Dereference().first && this -> Dereference().second != other.Dereference().second);
    }

    void Iterate(){
        bool t[2] = {true, true};
        while(t[0] || t[1]) {
            if(t[0]) {
                cout << "Pierwszy: " << Dereference().first;
            }
            if(t[1] == 1){
                cout << ", Drugi: " << Dereference().second;
            }
            cout << endl;
            Next();
            if(first_current == first_end){
                t[0] = false;
            }
            if(second_current == second_end){
                t[1] = false;
            }
        }
    }

};

int main() {
    vector<int> i = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> s = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"};
    ZipperIterator z(i.begin(), i.end(), s.begin(), s.end());
    z.Iterate();

    vector<int> m = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    ZipperIterator z1(m.begin(), m.end(), s.begin(), s.end());
    cout << z.NotEquals(z1);
}