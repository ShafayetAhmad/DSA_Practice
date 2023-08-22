#include <iostream>
#include <vector>

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;
        if (k == 1)
            return n;

        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i + 1;
        }
        
        int start = 0; // Change to 0 for 0-based indexing
        while (ans.size() != 1) {
            int temp = k - 1;
            while (temp > 0) {
                if (start >= ans.size())
                    start = 0;
                start++;
                temp--;
            }
            if (start >= ans.size())
                start = 0;
            ans.erase(ans.begin() + start);
        }
        return ans[0];
    }
};

int main() {
    int n, k;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    Solution solution;
    int winner = solution.findTheWinner(n, k);
    std::cout << "The winner is: " << winner << std::endl;

    return 0;
}
