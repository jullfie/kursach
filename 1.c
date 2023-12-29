#include <stdio.h>
#include <math.h>

// Функция для расчета скорости спутника на круговой орбите
double calculateVelocity(double Hc) {
    const double mu = 398600; // гравитационный параметр Земли в км^3/с^2
    const double R = 6371; // радиус Земли в км
    return sqrt(mu / (R + Hc));
}

int main() {
    // Открытие файла для записи данных
    FILE *file_for_Vc;
    file_for_Vc = fopen("file_for_Vc.txt", "wt");

    // Расчет и запись скорости для каждой высоты в диапазоне от 0 до 60000 км
    for (int i = 0; i <= 60000; i += 1000) {
        double Vc = calculateVelocity(i);
        fprintf(file_for_Vc, "%.12f\n", Vc);
    }

    // Закрытие файла
    fclose(file_for_Vc);

    return 0;
}
