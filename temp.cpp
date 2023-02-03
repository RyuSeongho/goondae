#include <iostream>
#include <vector>

using namespace std;

class line{
    int h = 0;
    int n = 0;
}

int plain[30][10] = {0};
//int rslt = -1;
int n, m, h;
int ptr1, ptr2;
vector<line> li;



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

bool canputin(){

}

void process(int left){
    li.
}

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        line l;
        cin >> l.h >> l.n;
        li.push_back(l);
        //plain[t1-1][t2-1] = 1;
        //plain[t1-1][t2-1+1] = -1;
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
