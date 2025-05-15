#include <iostream>

using namespace std;
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Mover disco 1 de " << from_rod << " a " << to_rod << endl;
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Mover disco " << n << " de " << from_rod << " a " << to_rod << endl;
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main() {
    int num_disks = 3; // Cambia este valor para probar con mas discos
    hanoi(num_disks, 'A', 'C', 'B'); // 'A', 'B' y 'C' son los nombres de las varillas
    return 0;
}