#include <iostream>
#include <vector>
using namespace std;

int n;

class Point{
    public:
        int x;
        int y;


    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

vector<Point> v;
vector<Point> sp;


int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int plain[100][100] = {0};

int idx = 0; //start with 1

int rslt = 0;


void printPlain(){
    for(int i=0; i < 20; i++){
        for(int j=0; j < 20; j++){
            cout << plain[i][j];
        }
        cout << endl;
    }
}


void rotatePoint(int& x, int& y, int crix, int criy){
    int dx = x - crix; //2
    int dy = y - criy; //1

    x = crix + dy;
    y = criy - dx;

}

void makePointProcess(int crix, int criy, int g){
    if(g <= 0) {
        v.clear();
        return;
    }

    int size = v.size();
    int rx, ry;
    int indexOfStartPoint = plain[crix][criy];
    for(int i=0; i < size; i++){
        rx = v[i].x;
        ry = v[i].y;

        if(crix == rx && criy == ry) continue;

        rotatePoint(rx, ry, crix, criy);
        v.push_back(Point(rx, ry));

        plain[rx][ry] = indexOfStartPoint;
    }

    Point startPointOfThis = sp[indexOfStartPoint];

    rx = startPointOfThis.x;
    ry = startPointOfThis.y;

    rotatePoint(rx, ry, crix, criy);

    crix = rx;
    criy = ry;

    makePointProcess(crix, criy, g - 1);
    
}


void makeFirstPoint(int x, int y, int d, int g){
    sp.push_back(Point(x,y));
    
    int _x = x+dx[d];
    int _y = y+dy[d];
    plain[x][y] = idx;
    plain[_x][_y] = idx;

    v.push_back(Point(x,y));
    v.push_back(Point(_x,_y));

    makePointProcess(_x, _y, g);
}

bool checkIsSquare(int x, int y){
    if(plain[x+1][y] == 0) return false;
    if(plain[x+1][y+1] == 0) return false;
    if(plain[x][y+1] == 0) return false;
    return true;
}

bool checkOutOfBound(int x, int y){
    if(x < 0 || y < 0) return true;
    if(x >= 100 || y >= 100) return true;
    return false;
}

void dfs(int x, int y){
    
    if(checkOutOfBound(x, y)) return;
    if(plain[x][y] <= 0) return;
    
    //cout << x << " " << y << endl;

    plain[x][y] = -1;

    for(int i=0; i<4; i++){
        dfs(x+dx[i], y+dy[i]);
    }
    
    if(checkIsSquare(x, y)) rslt++;

}

int main() {
    int d = 0;
    sp.push_back(Point(0,0)); //dummy
    cin >> n;
    for(int i=0; i < n; i++) {
        idx++;
        int x, y, d, g;
        
        cin >> x >> y >> d >> g;
        makeFirstPoint(x, y, d, g);
    }

    //printPlain();

    for(int i=1; i <= idx; i++){
        dfs(sp[i].x, sp[i].y);
    }
    
    cout << rslt;
    return 0;
}
