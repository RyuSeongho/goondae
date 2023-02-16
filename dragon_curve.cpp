#include <iostream>
using namespace std;

int n;
int x[20];
int y[20];
int d[20];
int g[20];

int plain[100][100] = {0};


void rotatePoint(int& x, int& y, int crix, int criy){
    int dx = x - crix; //2
    int dy = y - criy; //1

    x = crix + dy;
    y = criy - dx;

    cout << x << " " << y;

}

int main() {
    int p, m, ga, na;
    cin >> p >> m >> ga >> na;
    rotatePoint(p, m, ga, na);
    return 0;
    cin >> n;
    for(int i=0; i < n; i++) cin >> x[i] >> y[i] >> d[i] >> g[i];


    return 0;
}
