#include <iostream>
#include <string>

using namespace std;

int maxprofit = 0;//현재까지 등장한 최대 profit
//int profit = 0;//현재 node까지 추가한 item들의 profit 합
//int weight = 0;//현재 node까지 추가한 item들의 weight 합

//int W = 16;
int W = 9;
const int n = 4;

//eg5.6
//int p[n+1] = {0,40,30,50,10};
//int w[n+1] = {0,2,5,10,5};

//my data
int p[n+1] = {0,40,30,25,8};
int w[n+1] = {0,2,3,5,2};

void knapsack(int i, int profit, int weight);
bool promising(int i);

int numbest = 0;
string include[n+1] = {"NA","NA","NA","NA","NA"};
string bestset[n+1] = {"NA","NA","NA","NA","NA"};


int main(){
    knapsack(0,0,0);
    cout<<"maxprofit: "<<maxprofit<<"\n";
    cout<<"bestset: ";
    for(int j=1;j<=numbest;j++){//numbest까지만 출력해야 답이 나옴(numbest+1부터는 탐색중 저장한 다른 값 나옴)
        cout<<bestset[j]<<",";
    }
    cout<<"\n";
    //cout<<"profit: "<<profit<<"\n";
    //cout<<"weight: "<<weight<<"\n";


    return 0;
}









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
        cout<<"==> level "<<i+1<<" bound: "<<bound<<"\n";
        return bound>maxprofit;
    }
}




void knapsack(int i, int profit, int weight){
    cout<<"\n[knapsack: level "<<i<<", "<<"profit: "<<profit<<", "<<"weight: "<<weight<<" 호출]\n";
    if(weight<=W && profit>maxprofit){
        cout<<"[최신화] maxprofit:"<<maxprofit<<"->";
        maxprofit = profit;
        numbest = i;
        cout<<maxprofit<<", i: "<<i<<"\n";
        cout<<"bestset: ";
        for(int j=0;j<=i;j++){
            bestset[j] = include[j];//bestset 최신화
            cout<<bestset[j]<<"->";
        }
        cout<<"\n";
    }

    if(promising(i,profit,weight)){

        include[i+1] = "yes";
        knapsack(i+1,profit+p[i+1],weight+w[i+1]);
        //cout<<"level "<<i<<"의 branch끝 \n";
        include[i+1] = "no";
        knapsack(i+1,profit,weight);
    }
}