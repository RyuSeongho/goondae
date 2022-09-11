#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int* matrix;
        int degree;
};

void _print(int* matrix, int n){
    for(int i=0; i <n*n; i++){
        if(i%n==0) cout << endl;
        cout << *(matrix+i) << " ";
        
    }
    cout << endl;
}


void _copy(int* orgmatrix, int* matrix, int n){
    for(int i=0; i <n*n; i++){
        *(matrix+i) = *(orgmatrix+i);
    }
}

bool _isValid(int* matrix, int n, int limit, int db_size){
    int sum = 0;
    int valid_limit = limit;
    for(int i=0; i < 5 - db_size; i++) {
        if(valid_limit <= 2) break;
        valid_limit /= 2;
    }
    for(int i=0; i <n*n; i++){
        if(matrix[i] >= valid_limit) sum += matrix[i];
    }
    if(sum >= limit) return true;
    else return false;
}

int _maxof(int* matrix, int n){
    int result = 0;
    for(int i=0; i <n*n; i++){
        if(matrix[i] > result) result = matrix[i];
    }
    return result;
}

void _doProgress(int* matrix, int n){
    
    vector<int> _stack;
    vector<int> _finalstack;
    for(int i=0; i < n; i++){
        bool has_absorbed = false;
        for(int j=0; j < n; j++){
            if(*(matrix+(n*i)+j) == 0) continue;
            _stack.push_back(*(matrix+(n*i)+j));
        }
        while(!_stack.empty()){
            if(!_finalstack.empty() && _finalstack.back() == _stack.at(0) && !has_absorbed){
                _finalstack.back() *= 2;
                has_absorbed = true;
            }
            else {
                _finalstack.push_back(_stack.at(0));
                has_absorbed = false;
            }
            _stack.erase(_stack.begin());
        }
        for(int j = 0; j < n; j++){
            if(_finalstack.empty()) {
                *(matrix+(n*i)+j) = 0;
                continue;
            }
            *(matrix+(n*i)+j) = _finalstack.at(0);
            _finalstack.erase(_finalstack.begin());
        }
    }
}

void _turnProgress(int* matrix, int n)
{
    int result_matrix[n*n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
        *(result_matrix+(n*i)+j) = *(matrix+(n*(n-1-j))+i);
    }
    _copy(result_matrix, matrix, n); // 배열복사
}

int main(){
    int n = 0;
    int db_size = 0;
    cin >> n;
    int* curr_matrix = new int[n*n];

    
    for(int i=0; i < n*n; i++) {
        cin >> *(curr_matrix+i);
    }
    node* db = new node[6];
    for(int i=0; i < 6; i++){
        db[i].matrix = new int[n*n];
        db[i].degree = 0;
    }

    _copy(curr_matrix, db[0].matrix, n);
    int limit = _maxof(curr_matrix, n) * 2; //극복해야 할 숫자
    

    

    bool flag = true;
    int a = 0;

    while(flag){
        
        if(_isValid(curr_matrix, n, limit, db_size)){
            if(db_size > 4){ //이번에 만지고 있는게 index 5짜리 그러니까 마지막 거
                if(_maxof(curr_matrix, n) >= limit) {
                    
                    limit = _maxof(curr_matrix, n) * 2;
                    
                }
                
                
            }
            else{
                
                _doProgress(curr_matrix, n); // 기능 실행
                _copy(curr_matrix ,db[++db_size].matrix, n); // 기능 한 단계 실행 후 저장
                db[db_size].degree = 0;
                //cout << "[" << db_size << "]";
            }
        }
        else{
            
            db_size--;
            
            
            while(db_size > 0 && db[db_size].degree >= 3) {
                db_size--; //계속 전게 끝까지 돌아가있으면 뒤로 계속 돌아가기
                
            }
            if(db[0].degree >= 3 || db_size < 0) break;
            db[db_size].degree++;
            _turnProgress(db[db_size].matrix, n); //전거 먼저 돌려놓기
            _copy(db[db_size].matrix, curr_matrix, n); // 전거 불러오기
            
            
        }
        
        
    }

  cout << limit / 2;

  return 0;

}
