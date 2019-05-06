#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class InvalidNameSurname{
private:
	string error;
public:
	InvalidNameSurname(){
		error = "Podane imie lub nazwisko jest niepoprawne";
	}
	
	string getError(){
		return error;
	}
};

class InvalidAge{
private:
	string error;
public:
	InvalidAge(){
		error = "Podany wiek jest niepoprawny";
	}
	
	string getError(){
		return error;
	}
};

class InvalidProgram{
private:
	string error;
public:
	InvalidProgram(){
		error = "Podany kierunek jest niepoprawny";
	}
	
	string getError(){
		return error;
	}
};

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
	Student(){
		string fn, ln, p;
		int y, i;
		cin >> fn;
		cin >> ln;
		cin >> p;
		cin >> y;
		cin >> i;
		try{
			validateNames(fn, ln);
		}
		catch(InvalidNameSurname &i){
			cout << i.getError() << endl;
		}
		try{
			validateAge(y);
		}
		catch(InvalidAge &i){
			cout << i.getError() << endl;
		}
		try{
			validateProgram(p);
		}
		catch(InvalidProgram &i){
			cout << i.getError() << endl;
		}
		this -> id = i;
	};
	
	Student(string first_name, string last_name){
		try{
			validateNames(first_name, last_name);
		}
		catch(InvalidNameSurname &i){
			cout << i.getError() << endl;
		}
	}
	
	Student(string first_name, string last_name, string program, int year){
		try{
			validateNames(first_name, last_name);
		}
		catch(InvalidNameSurname &i){
			cout << i.getError() << endl;
		}
		try{
			validateAge(year);
		}
		catch(InvalidAge &i){
			cout << i.getError() << endl;
		}
		try{
			validateProgram(program);
		}
		catch(InvalidProgram &i){
			cout << i.getError() << endl;
		}
	}
	
	Student(string first_name, string last_name, string program, int year, int id){
		try{
			validateNames(first_name, last_name);
		}
		catch(InvalidNameSurname &i){
			cout << i.getError() << endl;
		}
		try{
			validateAge(year);
		}
		catch(InvalidAge &i){
			cout << i.getError() << endl;
		}
		try{
			validateProgram(program);
		}
		catch(InvalidProgram &i){
			cout << i.getError() << endl;
		}
		this -> id = id;
	}
	
	~Student(){}
	
	void validateNames(string first_name, string last_name){
		//regex pattern{"\\u\\l+"};first_name==pattern && last_name==pattern
		if(true){
			this -> first_name = first_name;
			this -> last_name = last_name;
		}
		else{
			throw InvalidNameSurname();
		}
	}
	
	void validateAge(int year){
		if(year <= 100 && year >= 10){
			this -> year.ChangeYear(year);
		}
		else{
			throw InvalidAge();
		}
	}
	
	void validateProgram(string program){
		string programs[5]={"informatyka","ekonomia","matematyka","fizyka","filozofia"};
		int t=0;
		for(int i=0; i<5; i++){
			if(program==programs[i]){
				t=1;
				break;
			}
		}
		
		if(t==1){
			this -> program = program;
		}
		else{
			throw InvalidProgram();
		}
	}
	
	void Print(){
		cout << id << endl << first_name << endl << last_name << endl << program << endl << year << endl;
	}
	
	friend istream& operator >>(istream &input, Student& s){
		input >> s.first_name;
		input.ignore();
		input >> s.last_name;
		input.ignore();
		input >> s.program;
		input.ignore();
		input >> s.year;
		input.ignore();
		input >> s.id;
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
	
	string GetFirst(){
		return this->first_name;
	}
	
	string GetLast(){
		return this->last_name;
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
	
	void Delete(){
		delete *r.end();
		r.pop_back();
	}
	
	Student* Last(){
		return r.back(); 
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
	StudentRepository Repository;
	while(true){
		cout << "dej studenta:" << endl;
		Repository.Add(new Student());
		if(Repository.Last()->GetFirst()=="" || Repository.Last()->GetLast()==""){
			Repository.Delete();
		}
		if(Repository.GetRep().size() > 0){
			cout << Repository << endl;
		}
	}
	Student Ziomek;
	cin >> Ziomek;
}
