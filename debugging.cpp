#include <iostream>

using namespace std;

int plain[30][10] = {0};
//int rslt = -1;
int n, m, h;
int ptr1, ptr2;

void printplain(){
    for(int i=0; i < h; i++){
        for(int j=0; j <n; j++) cout << plain[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool check(){
    for(int i=0; i < n; i++){
        int curr = i;
        for(int j=0; j < h; j++){
           curr += plain[j][curr];
        }
        if(curr != i) return false;
    }
    return true;
}

void ptrinit(){
    ptr1 = 0;
    ptr2 = 0;
}

bool ptrplus(){
    if(ptr2++ >= n){
        ptr2 = 0;
        ptr1++;
    }
    if(ptr1 >= m) return false;
    return true;
}

bool process(int left){
    if(left == 0 && check()) {
        return true;
    }
    
    if(plain[ptr1][ptr2] != 0) {
        if(!ptrplus()) return false;
        process(left);
    } else if(plain[ptr1][ptr2+1] == 0){
        plain[ptr1][ptr2] = 1;
        plain[ptr1][ptr2+1] = -1;
        if(!ptrplus()) return false;
        if(!ptrplus()) return false;
        printplain();
        process(left - 1);
    } else{
        if(!ptrplus()) return false;
    }

}

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        plain[t1-1][t2-1] = 1;
        plain[t1-1][t2-1+1] = -1;
    }
    printplain();
    for(int i = 0; i < 4; i++){
        ptrinit();
        if(process(i)) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
