#include <iostream>
#include <math.h>
using namespace std;

class Point{
public:
    int x;
    int y;

    Point(char n){
        cout << "Punkt " << n << ":" << endl;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
    }
};

double Distance(Point A, Point B){
    return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}

class Square{
private:
    Point A{'A'};
    Point B{'B'};
    Point C{'C'};
    Point D{'D'};
public:
    int t;

    Square(){
        double a = Distance(A,B);
        if( Distance(B,C) != a or Distance(C,D) != a or Distance(D,A) != a ){
            t=0;
        }
        else{
            double e = Distance(A, C);
            double f = Distance(B, D);
            if (e != f) {
                t=0;
            }
            else{
                t=1;
            }
        }
    }
    void Circumfance(){
        double x = Distance(A,B);
        cout << "Obwod: " << 4*x << endl;
    }
    void Area(){
        double x = Distance(A,B);
        cout << "Pole: " << x*x << endl;
    }
};

int main() {
    cout << "Podaj wspolrzedne wierczholkow kwadratu:" << endl;
    Square kw{};
    if(kw.t == 1) {
        kw.Circumfance();
        kw.Area();
    }
    else{
        cout << "Podane punkty nie tworza kwadratu" << endl;
    }
    return 0;
}
