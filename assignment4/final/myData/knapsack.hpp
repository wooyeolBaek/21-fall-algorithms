#include <iostream>
#include <string>

using namespace std;

//자작 데이터
int maxprofit = 0;

int W = 9;
const int n = 4;

int p[n+1] = {0,40,30,25,8};
int w[n+1] = {0,2,3,5,2};


int numbest = 0;
//include, bestset 초기화
string include[n+1] = {"NA","NA","NA","NA","NA"};
string bestset[n+1] = {"NA","NA","NA","NA","NA"};



bool promising(int i,int profit, int weight){//level i인 현재 노드의 자식 노드가 유망한지
    int j,k;
    int totweight;//최대로 가능한 무게
    float bound;//최대로 가능한 가치

    if(weight>=W){//유망하지 않은 경우: item을 추가하면 W를 초과하는 경우
        return false;
    }

    else{//bound 계산
        j=i+1;//다음 level
        bound = profit;
        totweight = weight;
        while((j<=n) && (totweight+w[j] <= W)){//다음 level부터 최대한 더함
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        k=j;
        if(k<=n){
            bound = bound + (W-totweight)*p[k]/w[k];
        }
        return bound>maxprofit;
    }
}




void knapsack(int i, int profit, int weight){
    if(weight<=W && profit>maxprofit){
        
        maxprofit = profit;
        numbest = i;
        
        for(int j=0;j<=i;j++){
            bestset[j] = include[j];//bestset 최신화
        }
    }

    if(promising(i,profit,weight)){
        include[i+1] = "yes";
        knapsack(i+1,profit+p[i+1],weight+w[i+1]);
        include[i+1] = "no";
        knapsack(i+1,profit,weight);
    }
}