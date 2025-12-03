#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int solve_inefficient(vector<int>& a) {
    int n = a.size();
    int maxVal = -1;
    int result = -1;
    
    // O(n²) - verifica para cada elemento se ele é único
    // Versão que sempre faz O(n²) comparações (sem break para otimização)
    for (int i = 0; i < n; i++) {
        int duplicateCount = 0;
        
        // Para cada elemento, conta quantas vezes aparece
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                duplicateCount++;
            }
        }
        
        // Se aparece exatamente 1 vez (único) e é maior que o máximo atual
        if (duplicateCount == 1 && a[i] > maxVal) {
            maxVal = a[i];
            result = i + 1; // retorna 1-indexado
        }
    }
    
    return result;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    
    cout << "n,time_ms" << endl;
    
    // Testamos de 1000 até 10000 com incrementos maiores para ver diferença
    for (int n = 1000; n <= 10000; n += 500) {
        vector<int> a(n);
        
        // Gera dados com ~50% únicos, ~50% com duplicatas
        // Usando range maior para ter mais valores únicos
        uniform_int_distribution<> dis(1, n * 2);
        for (int i = 0; i < n; i++) {
            a[i] = dis(gen);
        }
        
        // Fazemos múltiplas medições e tiramos a média
        const int NUM_RUNS = 10; // Mais execuções para melhor precisão
        double total_time = 0;
        
        for (int run = 0; run < NUM_RUNS; run++) {
            auto start = high_resolution_clock::now();
            solve_inefficient(a);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<nanoseconds>(end - start); // Usar nanosegundos
            total_time += duration.count() / 1000000.0; // Converter para ms
        }
        
        double avg_time = total_time / NUM_RUNS;
        cout << n << "," << avg_time << endl;
    }
    
    return 0;
}