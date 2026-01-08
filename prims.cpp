#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int g[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int selected[100] = {0};
    selected[0] = 1;

    int edges = 0;

    while (edges < n - 1) {
        int x = -1, y = -1, mn = 1e9;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && g[i][j] && g[i][j] < mn) {
                        mn = g[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << mn << endl;
        selected[y] = 1;
        edges++;
    }
    return 0;
}
