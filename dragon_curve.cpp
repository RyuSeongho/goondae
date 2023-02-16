#include <iostream>
using namespace std;

int n;
int sx[20];
int sy[20];
int sd[20];
int sg[20];


int plain[100][100] = {0};



void rotatePoint(int& x, int& y, int crix, int criy){
    int dx = x - crix; //2
    int dy = y - criy; //1

    x = crix + dy;
    y = criy - dx;

    cout << x << " " << y;

}

void getNewCriterionPoint(int& sx, int& sy, int crix, int criy){
    rotatePoint(sx, sy, crix, criy);
}

int main() {
    int d = 0;
    cin >> n;
    for(int i=0; i < n; i++) {
        
        cin >> sx[i] >> sy[i] >> sd[i] >> sg[i];
        
    }
    



    return 0;
}
