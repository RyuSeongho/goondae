#include <iostream>
#include <vector>
using namespace std;

int n, m;

int x1 = 50, x2 = 0, y1 = 50, y2 = 0; // singular circle
int plain[50][50] = {0};
int hospitalx[13];
int hospitaly[13];
int hospitals[13];
int patientx[13];
int patienty[13];
int hospitali = 0, patienti = 0;

void makeSingularRect(int x, int y){
    patientx = x; patienty = y;
    patienti++;
    if(x < x1) x1 = x;
    else if(x > x2) x2 = x;
    if(y < y1) y1 = y;
    else if(y > y2) y2 = y;
}

void makeHospitalScore(){
    
}

int main() {

    cin >> n >> m;
    int flag = true;
    int input;

    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++) {
            cin >> input;
            if(input == 1) makeSingularRect(i, j);
            else if(input == 2) {hospitalx = i; hospitaly = j; hospitali++;}
        }
    }
    return 0;
}
