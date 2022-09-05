#include <iostream>
using namespace std;

int main(){

    int n = 0; //식당의 수
    int* people_per = NULL; //식당 사람 포인터
    int master = 0;
    int slave = 0;
    long long result = 0;

    cin >> n;
    people_per = new int[n];
    for(int i = 0; i < n; i++) cin >> *people_per;
    cin >> master >> slave;

    for(int i = 0; i < n; i++){
        int thisp = people_per[i];
        int leftover = (thisp - master) % slave;
        int divis = (thisp - master) / slave;
        if(leftover != 0) divis++;
        result += (long long)divis;
    }


    cout << result;
    return 0;
}
