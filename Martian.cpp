#include <iostream>
#include <vector>
using namespace std;

class Martian{
public:
	static unsigned int Martian_number;

    Martian(){
        ++Martian_number;
	}

	~Martian(){
        --Martian_number;
	}

	void DoSomething(){
		if(Martian_number < 5){
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

unsigned Martian::Martian_number=0;

int main(){

	vector<Martian*> m;
	int choice;

    cout<<"1.nowy marsjanin" << endl << "2.usun marsjanina" << endl << "0.wyjdz " << endl << endl;

    while(true) {
        cout << "Wybor: ";
		cin >> choice;
		if(choice == 1){
			m.emplace_back(new Martian());
		}
		else if(choice == 2){
			if(Martian::Martian_number > 0){
				delete *m.end();
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

		for(auto a: m){
		    a -> DoSomething();
		}

		cout << endl;

	}
	return 0;
}