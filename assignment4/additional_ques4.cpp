#include <iostream>
#include <queue>
using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    queue<int> q;

   
    for (int i = 0; i < n; i++)
        q.push(students[i]);

    int i = 0;             
    int unableToEat = 0;  

    while (!q.empty() && unableToEat < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            unableToEat = 0;  
        } else {
            int front = q.front();
            q.pop();
            q.push(front);  
            unableToEat++;  
        }
    }

    return q.size();  // remaining students unable to eat
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int students[n], sandwiches[n];

    cout << "Enter student preferences (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++)
        cin >> students[i];

    cout << "Enter sandwiches stack (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];

    cout << "Number of students unable to eat: "
         << countStudents(students, sandwiches, n) << endl;

    return 0;
}
