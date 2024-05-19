#include <iostream>

int main() {
    int A = 10;
    int B = 20;
    int C = 30;

    std::cout << "Початкові значення:" << std::endl;
    std::cout << "A = " << A << ", B = " << B << ", C = " << C << std::endl;

    // Тимчасова змінна для збереження значення A
    int temp = A;

    // Переміщення значень
    A = C;
    C = B;
    B = temp;

    std::cout << "Нові значення:" << std::endl;
    std::cout << "A = " << A << ", B = " << B << ", C = " << C << std::endl;

    return 0;
}