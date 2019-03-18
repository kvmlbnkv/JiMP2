#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string PolybiusCrypt(string message){
    char Polybius[5][5]={{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    string crypted = "", numbers = "1234567890";
    for(int i=0; i < message.length(); i++){
        if(message[i] == 'j'){
            message[i] = 'i';
        }
        for(int j=0; j < 5; j++){
            for(int l=0; l < 5; l++){
                if(message[i] == Polybius[j][l]) {
                    crypted+=numbers[j];
                    crypted+=numbers[l];
                    crypted+=" ";
                }
            }
        }
    }
    return crypted;
}

string PolybiusDecrypt(string crypted){
    char Polybius[5][5]={{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    string decrypted = "", numbers = "1234567890";
    for(int i = 0; i < crypted.length(); i+=3){
        for(int j = 0; j < numbers.length(); j++){
            if(crypted[i] == numbers[j]){
                for(int l = 0; l < numbers.length(); l++){
                    if(crypted[i+1] == numbers[l]){
                        decrypted+=Polybius[j][l];
                    }
                }
            }
        }
    }
    return decrypted;
}

int main(int argc,char *argv[]) {
    if(argc == 4){
        string option=argv[3];
        ifstream input(argv[1]);
        ofstream output(argv[2], ios_base::in | ios_base::app);
        char line[256];
        string message = "";
        while(!input.eof()){
            input.getline(line,256);
            message += line;
        }
        if(option == "1"){
            message = PolybiusCrypt(message);
        }

        else if(option == "0"){
            message = PolybiusDecrypt(message);
            output << "(W tej wiadomosci i moze oznaczac j)" << endl << endl;
        }
        else{
            cout << "Nie ma takiej opcji";
        }
        output << message;
        input.close();
        output.close();
    }
    return 0;
}
