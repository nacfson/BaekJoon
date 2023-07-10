#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    vector<int> nArr;
    int m;

    int left = 0;
    int right;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nArr.push_back(input);
    }
    sort(nArr.begin(), nArr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        bool result = false;

        left = 0; 
        right = n - 1;
        while (left <= right) {
            int midValue = (int)((left + right) / 2);

            if (nArr[midValue] == input) {
                result = true;
                break;
            }
            else if (nArr[midValue] < input) {
                left = midValue + 1;
                continue;
            }
            else {
                right = midValue - 1;
                continue;
            }
        }
        cout << (result ? 1 : 0) << "\n";
    }


    return 0;
}