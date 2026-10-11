#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long kiri = 1, kanan = 1000000000; 
        long long hasil = 1;

        while (kiri <= kanan) {
            long long tengah = (kiri + kanan) / 2;
            if (tengah * tengah <= n) {
                hasil = tengah;
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }

        cout << hasil << "\n";
    }

    return 0;
}
