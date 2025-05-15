#include <iostream>
#include <vector>
#include <limits>

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    int n;
    std::cout << "Número de embarcaderos: ";
    std::cin >> n;

    std::vector<std::vector<int>> tarifas(n, std::vector<int>(n, INF));

    std::cout << "Ingresa la matriz de tarifas (usa -1 para entradas no válidas):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int costo;
            std::cout << "Costo de " << i << " a " << j << ": ";
            std::cin >> costo;
            if (costo >= 0) tarifas[i][j] = costo;
        }
    }

    // Inicializamos min_cost con las tarifas directas
    std::vector<std::vector<int>> min_cost = tarifas;

    // Programación dinámica: actualizar con trayectos intermedios
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i + 1; k < j; ++k) {
                if (min_cost[i][k] != INF && min_cost[k][j] != INF) {
                    min_cost[i][j] = std::min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
                }
            }
        }
    }

    // Mostrar resultados
    std::cout << "\nCostos mínimos entre embarcaderos:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::cout << "De " << i << " a " << j << ": ";
            if (min_cost[i][j] == INF)
                std::cout << "No disponible\n";
            else
                std::cout << min_cost[i][j] << "\n";
        }
    }

    return 0;
}
