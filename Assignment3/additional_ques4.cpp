#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    int answer[n];       
    for (int i = 0; i < n; i++) answer[i] = 0;  

    int stack[n];        
    int top = -1;       

     
    for (int i = n - 1; i >= 0; i--) {
         
        while (top != -1 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }
        
        if (top != -1) {
            answer[i] = stack[top] - i;
        }
         
        top++;
        stack[top] = i;
    }

    cout << "Result: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}
