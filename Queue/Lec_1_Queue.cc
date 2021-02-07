// Priority Queue on Class.
#include <bits/stdc++.h>
using namespace std;

class Person {
    private:
        int age;
        string name;
    public:
        // Default Constructor. 
        Person() {}
        // Parametrised Constructor.
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        int getAge() {
            return this->age;
        }
        string getName() {
            return this->name;
        }
};

class PersonCompare {
    public:
        bool operator() (Person A, Person B) {
            return A.getAge() > B.getAge();
        }
};

int main() {
    priority_queue<Person, vector<Person>, PersonCompare> pq;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        string name; int age;
        cin >> name >> age;
        Person P(name, age);
        pq.push(P);
    }
    while(!pq.empty()) {
        Person P = pq.top();
        cout << P.getName() << " : " << P.getAge() << endl;
        pq.pop();
    }
    return 0;
}

// Sample Input 

// 5
// Ajay 26
// Vijay 24
// Deepak 21
// Kanika 17
// Vishal 25

// Sample Output :

// Ajay : 26
// Vishal : 25
// Vijay : 24
// Deepak : 21
// Kanika : 17