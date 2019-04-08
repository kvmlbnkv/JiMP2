#include <iostream>
#include <vector>
using namespace std;

class Marsjanin{
public:
	static unsigned int liczbaMarsjan;
	
	Marsjanin(){
		liczbaMarsjan++;
	}
	
	~Marsjanin(){
		liczbaMarsjan--;
	}
	
	void DoSomething(){
		if(liczbaMarsjan < 5){
			Hide();
		}
		else{
			Attack();
		}
	}
	
	void Hide(){
		cout << "ciiiiiichutko" << endl;
	}
	
	void Attack(){
		cout << "woblo woblo" << endl;
	}
};

unsigned Marsjanin::liczbaMarsjan=0;

int main(){

	vector<Marsjanin*> m;
	int choice;
	
    while(true) {
        cout<<"1.nowy marsjanin" << endl << "2.usun marsjanina" << endl << "0.wyjdz " << endl << endl;
        cout << Marsjanin::liczbaMarsjan;
        cout << "Wybor: ";
		cin >> choice;
		if(choice == 1){
			m.emplace_back(new Marsjanin());
		}
		else if(choice == 2){
			if(Marsjanin::liczbaMarsjan > 0){
				delete *m.back();
				m.pop_back();
			}
			else{
				cout << endl << "i tak juz nie ma";
			}
		}
		else if(choice == 0){
			m.clear();
			break;
		}
		
		cout << endl;
		
		if(Marsjanin::liczbaMarsjan > 0){
			for(auto a: m){
				a -> DoSomething();
			}
		}
		cout << endl;
	}
	return 0;
}
