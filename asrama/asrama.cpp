#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[300005];
int sp[20][300005];
int lg[300005];
int m1[300005], idx1[300005], m2[300005];
int kompDari[300005];
int kompAwal[300005], kompAkhir[300005];
long long nilaiKomp[300005];
vector<int> potong[300005];

int minR(int l, int r) {
    int k = lg[r - l + 1];
    return min(sp[k][l], sp[k][r - (1 << k) + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);

    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) sp[0][i] = a[i].second;
    for (int k = 1; (1 << k) - 1 <= n; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            sp[k][i] = min(sp[k - 1][i], sp[k - 1][i + (1 << (k -1))]);
        }
    }

    int jumlahKomp = 0;
    int maxR = -1;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].first > maxR) {
            jumlahKomp++;
            kompAwal[jumlahKomp] = i;
        }
        kompDari[i] = jumlahKomp;
        kompAkhir[jumlahKomp] = i;
        maxR = max(maxR, a[i].second);
    }
    for (int c = 1; c <= jumlahKomp; c++) {
        int s = kompAwal[c], e = kompAkhir[c];
        long long v = (long long)minR(s, e) - a[e].first + 1;
        if (v < 0) v = 0;
        nilaiKomp[c] = v;
    }

    int b1 = -1, b2 = -1, bi = 0;
    for (int i = 1; i <= n; i++) {
        int r = a[i].second;
        if (r > b1) {
            b2 = b1;
            b1 = r;
            bi = i;
        } else if (r > b2) {
            b2 = r;
        }
        m1[i] = b1;
        idx1[i] = bi;
        m2[i] = b2;
    }

    for (int q = 1; q < n; q++) {
        int L = a[q + 1].first;
        if (m1[q] >= L && m2[q] < L) {
            potong[idx1[q]].push_back(q);
        }
    }

    long long best1 = 0, best2 = 0;
    int best1komp = 0;
    for (int c = 1; c <= jumlahKomp; c++) {
        if (nilaiKomp[c] > best1) {
            best2 = best1;
            best1 = nilaiKomp[c];
            best1komp = nilaiKomp[c];
        }
    }

    long long jawab = 0;
    for (int x = 1; x <= n; x++) {
        int c = kompDari[x];
        int s = kompAwal[c], e = kompAkhir[c];
        long long cand;
        if (best1komp != c) cand = best1;
        else cand = best2;

        int e1;
        if (potong[x].empty()) e1 = e;
        else e1 = potong[x][0];

        int mn = INT_MAX;
        if (x - 1 >= s) mn = min(mn, minR(s, x - 1));
        if (x + 1 <= e1) mn = min(mn, minR(x + 1 , e1));
        if (mn != INT_MAX) {
            int mx;
            if (e1 == x) mx = a[x - 1].first;
            else mx = a[e1].first;
            cand = max(cand, (long long)mn - mx + 1);
        }

        for (int t = 0; t < (int)potong[x].size(); t++) {
            int kiri = potong[x][t] + 1;
            int kanan;
            if (t + 1 < (int)potong[x].size()) kanan = potong[x][t+1];
            else kanan = e;
            cand = max(cand, (long long)minR(kiri, kanan) - a[kanan].first + 1);
        }

        jawab = max(jawab, cand);
    }

    if (jawab <= 0) cout << -1 << endl;
    else cout << jawab << endl;

    return 0;
}
