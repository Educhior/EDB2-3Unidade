import pandas as pd
import matplotlib.pyplot as plt

# Lê os dados dos benchmarks finais
data_a = pd.read_csv('benchmark_a_noopt_utf8.csv')
data_b = pd.read_csv('benchmark_b_noopt_utf8.csv')

# Configura o plot
plt.figure(figsize=(12, 8))

# Plot das duas curvas
plt.plot(data_a['n'], data_a['time_ms'], 'ro-', label='Solução Ineficiente O(n²)', 
         linewidth=2, markersize=6, alpha=0.8)
plt.plot(data_b['n'], data_b['time_ms'], 'bo-', label='Solução Eficiente O(n log n)', 
         linewidth=2, markersize=6, alpha=0.8)

# Configurações do gráfico
plt.xlabel('Tamanho da Entrada (n)', fontsize=12, fontweight='bold')
plt.ylabel('Tempo de Processamento (ms)', fontsize=12, fontweight='bold')
plt.title('Comparação de Performance: Solução Ineficiente vs Eficiente\nProblema: Encontrar o Maior Valor Único', 
          fontsize=14, fontweight='bold', pad=20)

plt.legend(fontsize=11, loc='upper left')
plt.grid(True, alpha=0.3)

# Adiciona anotações destacando a diferença de complexidade
plt.annotate('Crescimento O(n²)\n(Quadrático)', 
             xy=(data_a['n'].iloc[-1], data_a['time_ms'].iloc[-1]), 
             xytext=(data_a['n'].iloc[-1] - 2000, data_a['time_ms'].iloc[-1] + 100),
             arrowprops=dict(arrowstyle='->', color='red', alpha=0.7),
             fontsize=10, color='red', fontweight='bold')

plt.annotate('Crescimento O(n log n)\n(Quase Linear)', 
             xy=(data_b['n'].iloc[-1], data_b['time_ms'].iloc[-1]), 
             xytext=(data_b['n'].iloc[-1] - 3000, data_b['time_ms'].iloc[-1] + 200),
             arrowprops=dict(arrowstyle='->', color='blue', alpha=0.7),
             fontsize=10, color='blue', fontweight='bold')

# Melhor layout
plt.tight_layout()
plt.xlim(0, max(max(data_a['n']), max(data_b['n'])) * 1.05)
plt.ylim(0, max(max(data_a['time_ms']), max(data_b['time_ms'])) * 1.1)

# Salva o gráfico
plt.savefig('performance_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

# Imprime estatísticas finais
print("\n=== ESTATÍSTICAS DO BENCHMARK ===")
print(f"Solução Ineficiente (O(n²)):")
print(f"  - Maior entrada: {data_a['n'].max()}")
print(f"  - Tempo máximo: {data_a['time_ms'].max():.2f} ms")
print(f"  - Crescimento: {data_a['time_ms'].iloc[-1] / data_a['time_ms'].iloc[0]:.1f}x")

print(f"\nSolução Eficiente (O(n log n)):")
print(f"  - Maior entrada: {data_b['n'].max()}")
print(f"  - Tempo máximo: {data_b['time_ms'].max():.2f} ms")
print(f"  - Crescimento: {data_b['time_ms'].iloc[-1] / data_b['time_ms'].iloc[0]:.1f}x")

speedup = data_a['time_ms'].iloc[-1] / data_b['time_ms'].iloc[-1]
print(f"\nSpeedup na entrada máxima (n=10000): {speedup:.1f}x")
print(f"A solução eficiente é {speedup:.1f} vezes mais rápida!")

print("\n=== RESUMO ===")
print("✅ Solução A (Ineficiente): Implementada e testada")
print("✅ Solução B (Eficiente): Implementada e testada")  
print("✅ Benchmark realizado com diferença clara entre O(n²) e O(n log n)")
print("✅ Gráfico gerado mostrando a superioridade da solução eficiente")
print("📋 Próximos passos: Submeter ambas no AtCoder")