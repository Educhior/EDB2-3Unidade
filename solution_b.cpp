#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, vector<int>> valueToIndices;
    
    for (int i = 0; i < n; i++) {
        valueToIndices[a[i]].push_back(i + 1);
    }
    
    int result = -1;
    
    for (auto it = valueToIndices.rbegin(); it != valueToIndices.rend(); ++it) {
        if (it->second.size() == 1) {
            result = it->second[0];
            break;
        }
    }
    
    cout << result << endl;
    
    return 0;
}