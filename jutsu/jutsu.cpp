#include <bits/stdc++.h>
using namespace std;

int n, m;
string grid[1005];
int kuat[1005][1005];

void proses(vector<pair<int, int> > &garis) {
    int len = garis.size();
    string s = "";
    for (int i = 0; i < len; i++) {
        s += grid[garis[i].first][garis[i].second];
    }

    vector<int> d(len);
    int l = 0, r = -1;
    for (int i = 0; i < len; i++) {
        int k;
        if (i > r) k = 1;
        else k = min(d[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < len && s[i - k] == s[i +k]) k++;
        d[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    for (int i = 0; i < len; i++) {
        int panjang = 2 * d[i] - 1;
        int x = garis[i].first, y = garis[i].second;
        kuat[x][y] = min(kuat[x][y], panjang);
    }
}

void jalan(int si, int sj, int di, int dj) {
    vector<pair<int, int> > garis;
    int i = si, j = sj;
    while (i >= 0 && i < n && j >= 0 && j < m) {
        garis.push_back(make_pair(i, j));
        i += di;
        j += dj;
    }
    proses(garis);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            kuat[i][j] = 1000000000;
    
    for (int i = 0; i < n; i++) jalan(i, 0, 0, 1);
    for (int j = 0; j < m; j++) jalan(0, j, 1, 0);
    for (int j = 0; j < m; j++) jalan(0, j, 1, 1);
    for (int i = 1; i < n; i++) jalan(i, 0, 1, 1);
    for (int j = 0; j < m; j++) jalan(0, j, 1, -1);
    for (int i = 1; i < n; i++) jalan(i, m - 1, 1, -1);

    int terbesar = 0, banyak = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kuat[i][j] > terbesar) {
                terbesar = kuat[i][j];
                banyak = 1;
            } else if (kuat[i][j] == terbesar) {
                banyak++;
            }
        }
    }
    cout << banyak << " " << terbesar << endl;
    return 0;
}
