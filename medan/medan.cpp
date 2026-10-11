#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> tree[800005];
long long hp[200005];
long long habis[200005];
int jumlahShield = 0;

void pasang(int node, int kiri, int kanan, int a, int b, int id) {
    if (a <= kiri && kanan <= b) {
        tree[node].push_back(id);
        return;
    }
    int tengah = (kiri + kanan) / 2;
    if (a <= tengah) pasang(node * 2, kiri, tengah, a, b, id);
    if (b > tengah) pasang(node * 2 + 1, tengah + 1, kanan, a, b, id);
}

int cari(int a, int waktu) {
    int node = 1, kiri = 1, kanan = n;
    int terbaik = 0;
    while (true) {
        while (!tree[node].empty()) {
            int id = tree[node].back();
            if (hp[id] <= 0 || habis[id] < waktu) {
                tree[node].pop_back();
            } else {
                break;
            }
        }
        if (!tree[node].empty()) {
            terbaik = max(terbaik, tree[node].back());
        }
        if (kiri == kanan) break;
        int tengah = (kiri + kanan) / 2;
        if (a <= tengah) {
            node = node * 2;
            kanan = tengah;
        } else {
            node = node * 2 + 1;
            kiri = tengah + 1;
        }
    }
    return terbaik;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int t = 1; t <= q; t++) {
        int tipe;
        cin >> tipe;
        if (tipe == 1) {
            int a, b;
            long long d, h;
            cin >> a >> b >> d >> h;
            jumlahShield++;
            hp[jumlahShield] = h;
            habis[jumlahShield] = t + d - 1;
            pasang(1, 1, n, a, b, jumlahShield);
        } else {
            int a;
            long long k;
            cin >> a >> k;
            int id = cari(a, t);
            if (id == 0) {
                cout << "EVAKUASI SEKARANG!\n";
            } else {
                hp[id] -= k;
                cout << "Shield Elmax pelindung kota!\n";
            }
        }
    }
    return 0;
}
