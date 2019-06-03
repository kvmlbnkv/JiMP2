#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int ToMinutes(string time_HH_MM){
    int colon = time_HH_MM.find(":");
    int inMins;
    string h = time_HH_MM.substr(0, colon);
    colon ++;
    string min = time_HH_MM.substr(colon, 2);
    string::size_type sz;
    int hrs = stoi(h, &sz);
    int mins = stoi(min, &sz);
    inMins = hrs * 60 + mins;
    return inMins;
}

int MinimalTimeDifference(vector<string> times){
        int diff = abs(ToMinutes(times[1]) - ToMinutes(times[0]));
        int minimal = diff;
        if (minimal>720){
            minimal=1440-diff;
        }
        return minimal;
}

int main() {
        string time;
        vector <string> times;
        cout << " Podaj 2 godziny.\nFormat - XX:XX\n";
        for(int i=0; i < 2; i++){
                getline(cin, time);
                times.push_back(time);
        }
        cout << "Najmniejsza roznica miedzy dwoma z podanych czasow to " << MinimalTimeDifference(times) << " minut.";
        return 0;
}