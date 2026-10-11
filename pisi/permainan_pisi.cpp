#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string p, s;
        int x;
        cin >> p >> x;
        cin >> s;

        int n = p.size();
        int m = s.size();

        int i = 0;
        int j = 0; 
        bool ok = true;
        while (i < n) {
            char c = p[i];

            int a = i;
            while (a < n && p[a] == c) {
                a++;
            }
            int panjangP = a - i;
            int banyakKelipatan = a / x - i / x;

            if (j >= m || s[j] != c) {
                ok = false;
                break;
            }
            int b = j;
            while (b < m && s[b] == c) {
                b++;
            }
            int panjangS = b - j;

            if (panjangS < panjangP || panjangS > panjangP + 2 * banyakKelipatan) {
                ok = false;
                break;
            }

            i = a;
            j = b;
        }

        if (j != m) {
            ok = false;
        }

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
