/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B - drutojan
    Enero 22 de 2025
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Person {
    int timeSpent;
    vector<string> namesList;
    Person(vector<string> &list) {
        timeSpent = 0;
        namesList = list;
    }
};
int main() {
    int cases, mins, arrivalTime, size, i, currCase = 1;
    string sitting, name;
    vector<string> names = {"Ja", "Sam", "Sha", "Sid", "Tan"};
    Person *p;
    while(cin >> cases) {
        cin >> mins >> arrivalTime >> sitting;
        map<string, Person*> data;
        vector<string> tmp;
        for(i = 0; i < names.size(); i++) {
            cin >> size;
            for(int j = 0; j < size; j++) {
                cin >> name;
                tmp.push_back(name);
            }
            p = new Person(tmp);
            data[names[i]] = p;
            tmp.clear();
        }
        i = 0;
        while(i < arrivalTime) {
            p = data[sitting];
            i += mins;
            if(i < arrivalTime) {
                p->timeSpent += mins;
            }
            else {
                p->timeSpent += mins-(i-arrivalTime);
            }
            sitting = p->namesList[0];
            p->namesList.erase(p->namesList.begin());
            p->namesList.push_back(sitting);
            i += 2;
        }
        cout << "Case " << currCase << ':' << endl;
        for(map<string, Person*>::iterator it = data.begin(); it != data.end(); it++) {
            cout << it->first << ' ' << it->second->timeSpent << endl;
        }
        currCase++;
        data.clear();
    }
    return 0;
}