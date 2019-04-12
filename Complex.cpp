#include <iostream>
using namespace std;

class Complex{
public:
	double Re;
	double Im;
	
	Complex(double Re, double Im){
		this -> Re = Re;
		this -> Im = Im;
	}
	
	Complex(){}
	
	~Complex(){}
	
	Complex operator +(Complex other){
		return Complex(this -> Re + other.Re, this -> Im + other.Im);
	}
	
	Complex operator -(Complex other){
		return Complex(this -> Re - other.Re, this -> Im - other.Im);
	}
	
	Complex operator *(Complex other){
		return Complex((this -> Re*other.Re)-(this -> Im*other.Im),(this -> Re*other.Im)+(this -> Im*other.Re) );
	}
	
	Complex operator /(Complex other){
		double m=(other.Re*other.Re)+(other.Im*other.Im);
	
		return Complex(((this -> Re*(other.Re))-(this -> Im*(-other.Im)))/m,((this -> Re*(-other.Im))+(this -> Im*(other.Re)))/m );
	}
	
	friend istream& operator >>(istream & input, Complex& c){
		input >> c.Re;
		input.ignore();
		input >> c.Im;
	}
	
	friend ostream& operator <<(ostream &output, Complex& c){
		output << c.Re;
		if(c.Im>=0){
			output << "+";
		}
		output << c.Im;
		output << "i";
		return output;
	}
	
	void Print(){
		if(Im>=0){
			cout << Re << "+" << Im << "i" << endl;
		}
		else{
			cout << Re << Im << "i" << endl;
		}
	}
};

int main(void){
	Complex a(9,5);
	Complex b(0,2);
	
	Complex c = a+b;
	c.Print();
	c= a-b;
	cout << c << endl;
	c= a*b;
	cout << c << endl;
	c= a/b;
	cout << c << endl;
	
	
	Complex d;
	cin >> d;
	cout << d << endl;
}
