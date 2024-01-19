#include <iostream>
#include <string>

using namespace std;

int maxprofit = 0;
int profit_g = 0;//현재 node까지 추가한 item들의 profit 합
int weight_g = 0;//현재 node까지 추가한 item들의 weight 합

int W = 16;
const int n = 4;

int p[n+1] = {0,40,30,50,10};
int w[n+1] = {0,2,5,10,5};

void knapsack(int i, int profit, int weight);
bool promising(int i);

int numbest = 0;
string include[n+1] = {"NE","NE","NE","NE","NE"};
string bestset[n+1] = {"NE","NE","NE","NE","NE"};


int main(){
    knapsack(0,profit_g,weight_g);
    cout<<"maxprofit: "<<maxprofit<<"\n";
    cout<<"bestset: ";
    for(int j=1;j<=numbest;j++){
        cout<<bestset[j]<<",";
    }
    cout<<"\n";
    cout<<"profit_g: "<<profit_g<<"\n";
    cout<<"weight_g: "<<weight_g<<"\n";


    return 0;
}




bool promising(int i){//level i인 현재 노드의 자식 노드가 유망한지
    int j,k;
    int totweight;//최대로 가능한 무게
    float bound;//최대로 가능한 가치

    if(weight_g>=W){//유망하지 않은 경우: item을 추가하면 W를 초과하는 경우
        return false;
    }

    else{//bound 계산
        j=i+1;//다음 level
        bound = profit_g;
        totweight = weight_g;
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
    cout<<"[knapsack "<<i<<", "<<profit_g<<", "<<weight_g<<" 호출]\n";
    if(weight_g<=W && profit_g>maxprofit){
        maxprofit = profit_g;
        numbest = i;
        for(int j=0;j<i;j++){
            bestset[j] = include[j];
        }
    }

    if(promising(i)){
        include[i+1] = "yes";
        knapsack(i+1,profit_g+p[i+1],weight_g+w[i+1]);
        profit_g = profit_g + p[i+1];
        weight_g = weight_g + w[i+1];
        cout<<"yes끝 \n";
        include[i+1] = "no";
        knapsack(i+1,profit_g,weight_g);
    }
}