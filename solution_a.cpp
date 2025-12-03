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
    
    int maxVal = -1;
    int result = -1;
    
    // Solução O(n²) - ineficiente
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        
        // Para cada elemento, verifica todos os outros
        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) {
                isUnique = false;
                break;
            }
        }
        
        // Se é único e é maior que o máximo atual
        if (isUnique && a[i] > maxVal) {
            maxVal = a[i];
            result = i + 1; // retorna 1-indexado
        }
    }
    
    cout << result << endl;
    
    return 0;
}