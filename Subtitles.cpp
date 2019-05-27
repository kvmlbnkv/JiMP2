#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <cmath>
using namespace std;

class SubtitlesException{
protected:
    string error;
public:
    SubtitlesException(){}

    SubtitlesException(string error){
        this -> error = error;
    }

    string Error(){
        return this -> error;
    }
};

class NegativeFrameAfterShift: public SubtitlesException{
public:
    explicit NegativeFrameAfterShift(const string error): SubtitlesException(error) {}
};

class SubtitleEndBeforeStart: public SubtitlesException{
public:
    explicit SubtitleEndBeforeStart(const string error): SubtitlesException(error) {}
};

class InvalidSubtitleLineFormat: public SubtitlesException{
public:
    explicit InvalidSubtitleLineFormat(const string error): SubtitlesException(error) {}
};

class NoFile: public SubtitlesException{
public:
    explicit NoFile(const string error): SubtitlesException(error) {}
};

class MovieSubtitles{
public:
    virtual void ShiftAllSubtitlesBy(const string input, const string output, int delay, int frame_per_second)=0;
};

class MicroDvd: public MovieSubtitles {
public:
    void ShiftAllSubtitlesBy(const string input, const string output, int delay, int fps) override{
        vector<string> lines = readLines(input);

        for (auto &line : lines) {
            line = delayLine(line, delay, fps);
        }

        writeToFile(output, lines);
    }

    vector<string> readLines(const string input) {
        string line;
        vector<string> lines;
        ifstream file(input);

        if (file.fail()) {
            throw NoFile("Brak podanego pliku do odczytu.");
        }

        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();

        return lines;
    }

    string delayLine(const string line, int delay, int fps) {
        validateLineFormat(line);

        stringstream ss(line);
        string subtitle;
        int start;
        int end;

        ss.ignore();
        ss >> start;
        ss.ignore();
        ss.ignore();
        ss >> end;
        ss.ignore();
        getline(ss, subtitle);

        int c = (int) floor(fps * ((double) delay / 1000));

        if(start + c < 0){
            throw NegativeFrameAfterShift("Po przesunieciu, napisy w ujemnych klatkach");
        }

        string text = "{" + to_string(start + c) + "}{" + to_string(end + c) + "}" + subtitle;

        return text;
    }

    void validateLineFormat(const string line) {
        regex pattern("^\\{\\d+\\}\\{\\d+\\}.+$");

        if (!regex_match(line, pattern)) {
            throw InvalidSubtitleLineFormat("Blad w skladni podanego pliku.");
        }

        stringstream ss(line);
        int start;
        int end;

        ss.ignore();
        ss >> start;
        ss.ignore();
        ss.ignore();
        ss >> end;
        ss.ignore();

        if(start < end){
            throw SubtitleEndBeforeStart("Klatka zaczyna sie po tym jak sie konczy.");
        }

    }

    void writeToFile(const string output, vector<string> lines) {
        ofstream file;
        file.open(output, ofstream::out | ofstream::app);

        if (file.fail()) {
            throw NoFile("Brak podanego pliku do zapisu.");
        }

        for (auto &line : lines) {
            file << line << "\n";
        }

        file.close();
    }
};

int main(int argc, char * argv[]) {
    if (argc != 3) {
        cout << "Podaj plik z ktorego beda odczytywane napisy, a nastepnie do ktorego beda zapisywane." << endl;
    }
    else {
        string input = argv[1];
        string output = argv[2];
        int delay;
        int fps;
        cout << "Opoznienie: ";
        cin >> delay;
        cout << "Klatki na sekunde: ";
        cin >> fps;
        MicroDvd md;
        try {
            md.ShiftAllSubtitlesBy(input, output, delay, fps);
        } catch (SubtitlesException e) {
            cout << e.Error() << endl;
            return 0;
        }

        cout << "Napisy przesuniete." << endl;
    }
    return 0;
}