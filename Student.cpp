#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StudyYear{
private:
	int year;
public:
	StudyYear(){
		year = 0;
	}
	
	friend istream& operator >>(istream &input, StudyYear& y){
		input >> y.year;
	}
	
	friend ostream& operator <<(ostream &output, StudyYear& y){
		output << y.year;
		return output;
	}
	
	StudyYear operator ++(){
		year = year + 1;
	}
	
	StudyYear operator --(){
		year = year - 1;
	}
	
	void ChangeYear(int year){
		this -> year = year;
	}
	
	bool operator ==(StudyYear y){
		return this->year == y.year;
	}
	
	bool operator <(StudyYear y){
		return this->year < y.year;
	}
};

class Student{
private:
	int id;
	string first_name;
	string last_name;
	string program;
	StudyYear year;
public:
	Student(){};
	
	Student(int id, string first_name, string last_name, string program, int year){
		this -> id = id;
		this -> first_name = first_name;
		this -> last_name = last_name;
		this -> program = program;
		this -> year.ChangeYear(year);
	}
	
	void Print(){
		cout << id << endl << first_name << endl << last_name << endl << program << endl << year << endl;
	}
	
	friend istream& operator >>(istream &input, Student& s){
		input >> s.id;
		input.ignore();
		input >> s.first_name;
		input.ignore();
		input >> s.last_name;
		input.ignore();
		input >> s.program;
		input.ignore();
		input >> s.year;
	}
	
	friend ostream& operator <<(ostream &output, Student& s){
		output << "Student {";
		output << "id: ,," << s.id;
		output << "\", first_name: ,," << s.first_name;
		output << "\", last_name: ,," << s.last_name;
		output << "\", program: ,," << s.program;
		output << "\", year: ,," << s.year;
		output << "\"}";
		return output;
	}
	
	bool operator ==(Student& s){
		return (this->id == s.id && this->first_name == s.first_name && this->last_name == s.last_name && this->program == s.program && this->year == s.year);
	}
	
	StudyYear GetYear(){
		return this->year;
	}
};

class StudentRepository{
private:
	vector<Student*> r;
public:
	StudentRepository(){}
	
	~StudentRepository(){}
	
	void Add(Student *s){
		r.push_back(s);
	}
	
	friend ostream& operator <<(ostream &output, StudentRepository& sr){
		output << "[";
		int i=0;
		for(auto &a:sr.r){
			output << *a;
			i++;
			if(i < sr.r.size()){
				output << ", ";
			}
		}
		output << "]";
		return output;
	}
	
	vector<Student*> GetRep(){
		return this->r;
	}
	
	Student& operator [](int i){
		return *this->r[i];
	}
};

int main(void){
	Student Marek(1337, "Marek", "Pobratyniec", "Ceramikoznastwo", 2);
	Student Janek(2115, "Janek", "Frankowski", "Lopatologia", 3);
	Student Franek(71830, "Franek", "Trap", "Rapologia", 1);
	StudentRepository Repository;
	Repository.Add(&Marek);
	Repository.Add(&Janek);
	Repository.Add(&Franek);
	cout << Repository << endl;
	cout << Repository[0] << endl;
	cout << Repository[1] << endl;
	if(Marek.GetYear()<Janek.GetYear()){
		cout << "Janek jest na wyzszym roku od Marka" << endl;
	}
	Student Ziomek;
	cin >> Ziomek;
	int t=0;
	for(auto &a:Repository.GetRep()){
		if(Ziomek==*a){
			cout << "Podany student jest juz w repozytorium" << endl;
			t=1;
			break;
		}
	}
	if(t==0){
		Repository.Add(&Ziomek);
		cout << Repository << endl;
	}
}
