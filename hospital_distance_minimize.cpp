#include <iostream>
#include <vector>
using namespace std;

int n, m;
int plain[50][50] = {0};



vector<pair<int,int>> patients;
vector<pair<int,int>> hospitals;
vector<int> selected_hospital_index;

Point gptr(0,0);
int currsum = 0;
int gmax = 0;

void distanceCalculation(){}

void hospitalDistributionDfs(int idx){
    if(idx >= hospitals.size()) return;
    if(selected_hospital_index.size() > m) {
        distanceCalculation();
        
    }

    hospitalDistributionDfs(idx + 1);\
    selected_hospital_index.push_back(idx);


}

int main() {

    cin >> n >> m;

    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            int input;
            switch(input){
                case 1:
                    patients.push_back(input);
                    break;
                case 2:
                    hospitals.push_back(input);
                    break;
                default:
                    break;

            }
        }
    }

    
    return 0;
}
