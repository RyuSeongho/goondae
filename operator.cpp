#include <iostream>
using namespace std;

int n;
int number[100];
int opr[99];
int add, sub, mul;

long long _max = -1000000000;
long long _min = 1000000000;


void calculate(long long curr, int next, int _add, int _sub, int _mul){
    if(next == n){
        //cout << endl;
        if(curr > _max) _max = curr;
        if(curr < _min) _min = curr;
        return;
    }
    if(_add > 0) {
        //cout << "+" << number[next];
        calculate(curr + number[next], next + 1, _add - 1, _sub, _mul);
    }
    if(_sub > 0){
        //cout << "-" << number[next];
        calculate(curr - number[next], next + 1, _add, _sub - 1, _mul);
    } 
    if(_mul > 0){
        //cout << "*" << number[next];
        calculate(curr * number[next], next + 1, _add, _sub, _mul - 1);
    }
    
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> number[i];
    cin >> add >> sub >> mul;

    calculate((long long)number[0], 1, add, sub, mul);

    cout << _min << " " << _max;
}
