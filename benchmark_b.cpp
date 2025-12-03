#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int solve_efficient(vector<int>& a) {
    int n = a.size();
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
    
    return result;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << "n,time_ms" << endl;
    
    // Testamos a mesma faixa para comparação justa
    for (int n = 1000; n <= 10000; n += 500) {
        vector<int> a(n);
        
        // Gera dados com ~50% únicos, ~50% com duplicatas
        // Usando range maior para ter mais valores únicos
        uniform_int_distribution<> dis(1, n * 2);
        for (int i = 0; i < n; i++) {
            a[i] = dis(gen);
        }
        
        // Fazemos múltiplas medições e tiramos a média
        const int NUM_RUNS = 10;
        double total_time = 0;
        
        for (int run = 0; run < NUM_RUNS; run++) {
            auto start = high_resolution_clock::now();
            solve_efficient(a);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<nanoseconds>(end - start); // Usar nanosegundos
            total_time += duration.count() / 1000000.0; // Converter para ms
        }
        
        double avg_time = total_time / NUM_RUNS;
        cout << n << "," << avg_time << endl;
    }
    
    return 0;
}