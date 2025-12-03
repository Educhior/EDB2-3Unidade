#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, vector<int>> valueToIndices;
    
    // O(n log n) - agrupa índices por valor
    for (int i = 0; i < n; i++) {
        valueToIndices[a[i]].push_back(i + 1);
    }
    
    int result = -1;
    
    // O(n) - percorre do maior para o menor valor
    for (auto it = valueToIndices.rbegin(); it != valueToIndices.rend(); ++it) {
        if (it->second.size() == 1) { // valor único
            result = it->second[0];
            break; // já encontrou o maior valor único
        }
    }
    
    cout << result << endl;
    
    return 0;
}