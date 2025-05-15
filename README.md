# Viajes- Xochimilco
Fundamentos - Algoritmos - C++ 20 - Programación Dinámica

### Resumen del problema
* Hay n embarcaderos numerados del `0` al `n-1`.
* Solo se puede viajar de `i` a `j` si `i < j` (río abajo).
* Una matriz `tarifas[i][j]` (con `i < j`) indica el costo directo de ir de `i` a `j`.
* A veces es más barato hacer escalas: `i → k → j` en lugar de ir directo `i → j`.
* El objetivo es calcular el costo mínimo de cada `i` a cada `j (i < j)`.

### Usamos programación dinámica porque:
* Tenemos subproblemas solapados: el costo óptimo de i → j puede depender de i → k y k → j.
* Podemos almacenar resultados intermedios y construir soluciones más grandes.

### Descripción Algoritmo
* Creamos una matriz `min_cost[i][j]` donde guardamos el costo mínimo para ir de `i` a `j`.
* Inicializamos `min_cost[i][j] = tarifas[i][j]` si `i < j`, y `INF` si no hay conexión.
* Luego actualizamos:
```cpp
for (int k = i + 1; k < j; ++k)
    min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
```

### Complejidad temporal
Tres bucles anidados: `O(n^3)` en el peor caso.
