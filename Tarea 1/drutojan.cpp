/*
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B - drutojan
    Enero 25 de 2025
*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Person {
    int timeSpent;
    queue<string> namesList;
    Person(queue<string> &list) {
        timeSpent = 0;
        namesList = list;
    }
};
int main() {
    int cases, mins, arrivalTime, size, i, currCase = 1;
    string sitting, name;
    vector<string> names = {"Ja", "Sam", "Sha", "Sid", "Tan"};
    map<string, Person*> data;
    Person* p;
    cin >> cases;
    while(cases--) {
        cin >> mins >> arrivalTime >> sitting;
        for(i = 0; i < names.size(); i++) {
            queue<string> tmp;
            cin >> size;
            for(int j = 0; j < size; j++) {
                cin >> name;
                tmp.push(name);
            }
            p = new Person(tmp);
            data[names[i]] = p;
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
            sitting = p->namesList.front();
            p->namesList.pop();
            p->namesList.push(sitting);
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