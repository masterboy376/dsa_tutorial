
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Snake and ladder

const int inf = 1e9;

int main() {
  int ladders, snakes;
  cin>>ladders;
  map<int,int> lad;
  for(int i = 0; i<ladders; i++){
    int u,v;cin>>u>>v;
    lad[u]=v;
  }
  cin>>snakes;
  map<int,int> snake;
  for(int i = 0; i<snakes; i++){
    int u,v;cin>>u>>v;
    snake[u] = v;
  }
  int moves = 0;
  queue<int> q;
  q.push(1);
  bool found = false;
  vector<int> vis(101,0);
  vis[1]=true;
  while(!q.empty() and !found){
    int sz = q.size();
    while(sz--){  
    int t = q.front();
    q.pop();
    for(int die = 1; die<=6;die++){
      if(t+die==100){
        found=true;
      }
      if(t+die<=100 and lad[t+die] and !vis[lad[t+die]]){
        vis[lad[t+die]] = true;
        if(lad[t+die]==100){
          found=true;
        }
        q.push(lad[t+die]);
      }
      else if(t+die<=100 and snake[t+die] and !vis[snake[t+die]]){
        vis[snake[t+die]] = true;
        if(snake[t+die]==100){
          found=true;
        }
        q.push(snake[t+die]);
      }
      else if(t+die<=100 and !vis[t+die] and !snake[t+die] and !lad[t+die]){
        vis[t+die]=true;
        q.push(t+die);
      }
    }
    }
    moves++;
  }
  if(found){
    cout<<moves<<endl;
  }
  else{
    cout<<-1<<endl;
  }

  return 0;
}
