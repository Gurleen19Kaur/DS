#include <iostream>
using namespace std;

void sortString(char str[]) {
    int i, j;
    char temp;
    
    for (i = 0; str[i] != '\0'; i++) {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) {
                 
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool areAnagrams(char str1[], char str2[]) {
     
    int len1 = 0, len2 = 0;
    for (len1 = 0; str1[len1] != '\0'; len1++);
    for (len2 = 0; str2[len2] != '\0'; len2++);
    if (len1 != len2)
        return false;

     
    sortString(str1);
    sortString(str2);

     
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}
