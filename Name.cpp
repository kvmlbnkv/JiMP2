#include <iostream>
using namespace std;

class Name{
private:
  string first_name;
  string second_name;

  string third_name;
  string last_name;

public:
    Name(string firstname, string surname){
        first_name=firstname;
        last_name=surname;
    }

    Name(string firstname, string surname, string secondname){
        first_name=firstname;
        last_name=surname;
        second_name=secondname;
    }

    Name(string firstname, string surname, string secondname, string thirdname){
        first_name=firstname;
        last_name=surname;
        second_name=secondname;
        third_name=thirdname;
    }

    string FirstName()const{
        return first_name;
    }
    string SecondName()const{
        return second_name;
    }
    string ThirdName()const{
        return third_name;
    }
    string Surname()const{
        return last_name;
    }
    string ToFullInitials(){
        string initials;
        initials+=first_name[0];
        initials+=". ";
        if(second_name[0] != NULL){
            initials+=second_name[0];
            initials+=". ";
        }
        if(third_name[0] != NULL){
            initials+=third_name[0];
            initials+=". ";
        }
        initials+=last_name[0];
        initials+=".";

        return initials;
    }
    string ToFirstNamesInitials(){
        string initials;
        initials+=first_name[0];
        initials+=". ";
        if(second_name[0] != NULL){
            initials+=second_name[0];
            initials+=". ";
        }
        if(third_name[0] != NULL){
            initials+=third_name[0];
            initials+=". ";
        }
        initials+=last_name;

        return initials;
    }
    string ToSurnameNames(){
        string tosurname;
        tosurname+=last_name;
        tosurname+=" ";
        tosurname+=first_name;
        tosurname+=" ";
        if(second_name != "") {
            tosurname += second_name;
            tosurname+=" ";
        }
        if(third_name != "") {
            tosurname += third_name;
            tosurname += " ";
        }
        return  tosurname;
    }
    string ToNamesSurname(){
        string toname;
        toname+=first_name;
        toname+=" ";
        if(second_name != "") {
            toname += second_name;
            toname += " ";
        }
        if(third_name != "") {
            toname += third_name;
            toname += " ";
        }
        toname+=last_name;
        toname+=" ";

        return  toname;
    }
    bool IsBeforeBySurname(const Name &other){
        int size;
        if (other.last_name.length() > last_name.length()) {
            size = last_name.length();
        }
        else{
            size = other.last_name.length();
        }
        for(int i=0; i < size; i++){
            if(other.last_name[i] > last_name[i]){
                return true;
            }
            else if(last_name[i] > other.last_name[i]){
                return false;
            }
        }
        return false;
    }
    bool IsBeforeByFirstName(const Name &other){
        int size;
        if (other.first_name.length() > first_name.length()) {
            size = first_name.length();
        }
        else{
            size = other.first_name.length();
        }
        for(int i=0; i < size; i++){
            if(other.first_name[i] > first_name[i]){
                return true;
            }
            else if(first_name[i] > other.first_name[i]){
                return false;
            }
        }
        return false;
    }
};

int main() {
    Name karol("Karol", "Wojtyla");
    string i = karol.FirstName();
    string n = karol.Surname();

    cout << i << " " << n << endl;

    Name jan("Jan", "Drugi", "Pawel");
    i = jan.FirstName();
    n = jan.Surname();
    string d=jan.SecondName();

    cout << i << " " << d << " " << n << endl;

    Name pawel("Karol","Wojtyla","Jan","Pawel");
    Name mario("Mario","Bergoglio","Jorge","Francis");

    string inicjaly = pawel.ToFullInitials();
    string inicjaly2 = pawel.ToFirstNamesInitials();
    string odnazwiska = pawel.ToSurnameNames();
    string odimienia = pawel.ToNamesSurname();
    bool nazw = pawel.IsBeforeBySurname(mario);
    bool imie = pawel.IsBeforeByFirstName(mario);

    cout << inicjaly << endl << inicjaly2 << endl << odnazwiska << endl << odimienia << endl << nazw << endl << imie;

    return 0;
}