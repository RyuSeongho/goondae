#include <iostream>
using namespace std;

int n;
int t[15];
int p[15];
int mmax = 0;

void process(int index, int stackedPayment){
    if(index > n) return;
    if(index == n) {
        if(mmax < stackedPayment) mmax = stackedPayment;
        return;
    }
    if(t[index] == 1) process(index + 1, stackedPayment + p[index]);
    else{
        process(index + t[index], stackedPayment + p[index]);
        process(index + 1, stackedPayment);
    }

}

int main() {

    cin >> n;
    for(int i=0; i < n; i++){
        cin >> t[i] >> p[i];
    }

    process(0, 0);

    cout << mmax;

    return 0;
}
