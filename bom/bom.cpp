#include <bits/stdc++.h>
using namespace std;

long long A[1005][1005];
long long E[1005][1005];
long long hasil[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            A[i][j] = A[i][j] % k;
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<long long> kiri(m + 2), kanan(m + 2);
        kiri[0] = 1 % k;
        kanan[m + 1] = 1 % k;
        for (int j = 1; j <= m; j++) kiri[j] = kiri[j - 1] * A[i][j] % k;
        for (int j = m; j >= 1; j--) kanan[j] = kanan[j + 1] * A[i][j] % k;
        for (int j = 1; j <= m; j++) E[i][j] = kiri[j - 1] * kanan[j + 1] % k;
    }

    for (int j = 1; j <= m; j++) {
        vector<long long> atas(n + 2), bawah(n + 2);
        atas[0] = 1 % k;
        bawah[n + 1] = 1 % k;
        for (int i = 1; i <= n; i++) atas[i] = atas[i - 1] * E[i][j] % k;
        for (int i = n; i >= 1; i--) bawah[i] = bawah[i + 1] * E[i][j] % k;
        for (int i = 1; i <= n; i++) hasil[i][j] = atas[i - 1] * bawah[i + 1] % k;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << hasil[i][j];
            if (j < m) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
