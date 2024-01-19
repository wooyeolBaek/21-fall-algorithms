#include "knapsack.hpp"

int main(){

    //example 5.6 출력
    knapsack(0,0,0);
    cout<<"maxprofit: "<<maxprofit<<"\n";
    cout<<"bestset: ";
    for(int j=1;j<=numbest;j++){
        cout<<bestset[j]<<",";
    }
    cout<<"\n";
    
    return 0;
}