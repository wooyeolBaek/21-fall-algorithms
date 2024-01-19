#include <iostream>
#define INF 99999

int p[6][6];
int d[6][6];
//Figure 3.2
int w1[6][6] = {
  {0,0,0,0,0,0},
  {0,0,1,INF,1,5},
  {0,9,0,3,2,INF},
  {0,INF,INF,0,4,INF},
  {0,INF,INF,2,0,3},
  {0,3,INF,INF,INF,0}
};
//자작 데이터
int w2[6][6] = {
  {0,0,0,0,0,0},
  {0,0,9,INF,8,INF},
  {0,1,0,2,5,INF},
  {0,INF,1,0,INF,INF},
  {0,INF,2,3,0,1},
  {0,2,INF,INF,INF,0}
};

//fig3.4, floyd2
//n: the number of nodes in the digraph
//w[][]: weighted graph
//d[][]: digraph
void floyd2(int n, int w[][6], int d[][6],int p[][6]){
  int i, j, k;
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      p[i][j] = 0;//p 초기화
      d[i][j] = w[i][j];//d 초기화
    }
  }
  for(k=1;k<=n;k++){//k: 거쳐갈 노드
    for(i=1;i<=n;i++){//i: row
      for(j=1;j<=n;j++){//j: col
        if(d[i][k]+d[k][j]<d[i][j]){//기존 경로보다 k를 거쳐가는 경우가 거리가 더 작은 경우
          p[i][j] = k;//경로에 k추가
          d[i][j] = d[i][k] + d[k][j];//최단 거리 업데이트
        }
      }
    }
  }
}

//fig 3.5
void path(int q, int r){
  if(p[q][r]!=0){//다른 노드를 거쳐가는 경우
    path(q,p[q][r]);//시작노드와 중간노드로 재귀호출: 두 노드 사이의 노드 출력
    std::cout << 'v' << p[q][r] << " ";//중간노드 출력
    path(p[q][r],r); //중간노드와 도착노드로 재귀호출: 두 노드 사이의 노드 출력
  }
}





int main() {
  //floyd2 for w1
  floyd2(5, w1, d, p);

  //d 출력
  std::cout << "w1 d[][]" << "\n";
  for(int i=1;i<=5;i++){
    std::cout << '{';
    for(int j=1;j<=5;j++){
      std::cout << d[i][j] << ',';
    }
    std::cout<<'}'<<"\n";
  }
  std::cout << "\n";

  //path for w1
  //p 출력
  std::cout << "w1 p[][]" << "\n";
  for(int i=1;i<=5;i++){
    std::cout << '{';
    for(int j=1;j<=5;j++){
      std::cout << p[i][j] << ',';
    }
    std::cout<<'}'<<"\n";
  }
  std::cout << "\n";
  
  //path for w1
  path(5,3);
  std::cout << "\n";
  std::cout << "\n";

  
  //floyd2 for w2
  floyd2(5, w2, d, p);
  
  //d 출력
  std::cout << "w2 d[][]" << "\n";
  for(int i=1;i<=5;i++){
    std::cout << '{';
    for(int j=1;j<=5;j++){
      std::cout << d[i][j] << ',';
    }
    std::cout<<'}'<<"\n";
  }
  std::cout << "\n";

  //path for w2
  //p 출력
  std::cout << "w2 p[][]" << "\n";
  for(int i=1;i<=5;i++){
    std::cout << '{';
    for(int j=1;j<=5;j++){
      std::cout << p[i][j] << ',';
    }
    std::cout<<'}'<<"\n";
  }
  std::cout << "\n";
  
  
  //path for w2
  path(5,3);
  std::cout << "\n";
 
  return 0;
}