#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar cada punto de datos (x = Advertising, y = Sales)
struct DataPoint {
    double x;
    double y;
};

int main() {
    //  DataSet del Caso Benetton
    vector<DataPoint> dataset = {
        {43.60, 1261.08},
        {50.44, 1475.28},
        {59.01, 1657.52},
        {66.30, 2059.05},
        {82.36, 2303.76},
        {92.15, 2512.64},
        {100.51, 2751.46},
        {110.06, 2787.67},
        {111.51, 2939.13}
    };

    int n = dataset.size();
    double sumX = 0.0;
    double sumY = 0.0;
    double sumXY = 0.0;
    double sumX2 = 0.0;

  
    for (int i = 0; i < n; i++) {
        double xi = dataset[i].x;
        double yi = dataset[i].y;

        sumX += xi;
        sumY += yi;
        sumXY += (xi * yi);
        sumX2 += (xi * xi);
    }

    //  Cálculo de parámetros óptimos Beta 1 y Beta 0
    double beta1 = (n * sumXY - sumX * sumY) / (n * sumX2 - (sumX * sumX));
    double beta0 = (sumY - beta1 * sumX) / n;

   
    cout << "  Ecuacion de regresion lineal simple\n";

    cout << "y_hat = " << beta0 << " + " << beta1 << " * x\n";
    
    //Simular ventas
    vector<double> valoresAInyectar = { 45.0, 60.0, 75.0, 90.0, 105.0 };

    
    cout << "        Simulacion de ventas\n";
    

    for (size_t i = 0; i < valoresAInyectar.size(); i++) {
        double x_test = valoresAInyectar[i];
        double y_pred = beta0 + beta1 * x_test;

        cout << "Caso " << (i + 1)
            << " | Gasto (x): " << x_test
            << " | Ventas Predichas (y_hat): " << y_pred << "\n";
    }
   

    return 0;
}