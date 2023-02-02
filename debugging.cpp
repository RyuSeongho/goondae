#include <iostream>

using namespace std;

int plain[30][10] = {0};
int rslt = -1;
int n, m, h;
int ptr1, ptr2;

void ptrinit(){
    ptr1 = 0;
    ptr2 = 0;
}

bool ptrplus(){
    if(ptr2++ >= n-1){
        ptr2 = 0;
        ptr1++;
    }
    if(ptr1 >= m) return false;
    return true;
}

void process(int left){
    if(left == 0 && check()) rslt = 0;
    
    if(plain[ptr1][ptr2] != 0) {
        if(!ptrplus()) return;
        process(left);
    } else if(plain[ptr1][ptr2+1] == 0){
        if(!ptrplus()) return;
        if(!ptrplus()) return;
        process(left - 1);
    }

}

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        plain[t1][t2] = 1;
        plain[t1][t2+1] = -1;
    }
    ptrinit();
    process(0);
    ptrinit();
    process(1);
    ptrinit();
    process(2);
    ptrinit();
    process(3);
    return 0;
}
