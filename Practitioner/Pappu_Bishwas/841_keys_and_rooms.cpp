#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> mp(n, false);
        stack<vector<int>> st;
        mp[0] = true;
        st.push(rooms[0]);

        while (!st.empty()) {
            vector<int> temp = st.top();
            st.pop();
            for (int j = 0; j < temp.size(); j++) {
                if (!mp[temp[j]]) {
                    st.push(rooms[temp[j]]);
                    mp[temp[j]] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!mp[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    bool canVisit = solution.canVisitAllRooms(rooms);

    if (canVisit) {
        cout << "You can visit all rooms!" << endl;
    } else {
        cout << "You cannot visit all rooms!" << endl;
    }

    return 0;
}
