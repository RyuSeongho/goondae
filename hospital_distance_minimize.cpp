#include <iostream>
#include <vector>
using namespace std;

int n, m;
int plain[50][50] = {0};

class Point{
    public:
        int x;
        int y;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void inc(){
        y++;
        if(y >= n){
            x++;
            y=0;
        }
    }

    bool checkOutBoundOnlyXAbove(){
        if(x >= m) return true;
        return false;
    }
};

vector<Point> patients;
vector<Point> hospitals;

Point gptr(0,0);
int currsum = 0;
int gmax = 0;

void distanceCalculation(){}

void hospitalDistributionDfs(){
    if(gptr.checkOutBoundOnlyXAbove()) return;
    gptr.inc();
    if(plain[gptr.x][gptr.y] != 2) return;
    

}

int main() {

    cin >> n >> m;

    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++) cin >> plain[i][j];
    }

    
    return 0;
}
