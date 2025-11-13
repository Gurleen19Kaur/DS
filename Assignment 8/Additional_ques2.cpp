#include <iostream>
using namespace std;

class Solution {
public:
    int solve(int n) {
    
        if (n <= 1)
            return 1;

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int left = solve(i - 1);     // nodes in left subtree
            int right = solve(n - i);    // nodes in right subtree
            ans += left * right;         // total trees for this root
        }
        return ans;
    }

    int numTrees(int n) {
        return solve(n);
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of unique BSTs with " << n << " nodes: " << s.numTrees(n) << endl;
    return 0;
}


