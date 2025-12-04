#include <iostream>
#include <vector>
using namespace std;

int main() {    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int maxVal = -1;
    int result = -1;
    
    
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        
        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) {
                isUnique = false;
                break;
            }
        }
        
        if (isUnique && a[i] > maxVal) {
            maxVal = a[i];
            result = i + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}