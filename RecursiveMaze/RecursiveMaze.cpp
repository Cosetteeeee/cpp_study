#include <fstream>
#include <iostream>
#include <type_traits>
using namespace std;

struct Intersection {
  int left, forwd, right;
};

struct Maze {
  int MazeSize;
  int Exit;
  Intersection *intsec;
  bool *visited;
};

bool GetMaze(const char* filename,Maze &M){
  ifstream fin;
  fin.open(filename);

  if(!fin){
    cout<<"迷宫数据文件"<<filename<<"打不开"<<endl;
    return false;
  }
  fin>>M.MazeSize;
  if (M.MazeSize<=0) {
  cout<<"迷宫路口数量错误"<<endl;
  fin.close();
  return false;
  }
  M.intsec=new Intersection[M.MazeSize+1];
  M.visited=new bool[M.MazeSize+1];
  for (int i=1;i<=M.MazeSize;i++) {
    fin>>M.intsec[i].left>>M.intsec[i].forwd>>M.intsec[i].right;
    M.visited[i]=false;
  }
  M.visited[0]=false;
  fin>>M.Exit;
  fin.close();
  return true;
}


bool Traverse(int Pos,Maze &M){
  if (Pos<=0||Pos>M.MazeSize) {
    return false;
  }
  if (M.visited[Pos]) {
  return false;
  }
  M.visited[Pos]=true;
  if (Pos==M.Exit) {
  cout<<Pos;
  return true;
  }
  if (Traverse(M.intsec[Pos].left,M)) {
    cout<<"<-"<<Pos;
    return true;
  }
  if (Traverse(M.intsec[Pos].forwd,M)) {
    cout<<"<-"<<Pos;
    return true;
  }
  if (Traverse(M.intsec[Pos].right,M)) {
    cout<<"<-"<<Pos;
    return true;
  }
  return false;
}

void DestroyMaze(Maze &M){
  delete [] M.intsec;
  delete [] M.visited;
  M.intsec = nullptr;
  M.visited = nullptr;
  M.MazeSize = 0;
}

int main() {
  Maze M;

  if (!GetMaze("maze.txt", M)) {
    return 0;
  }

  cout << "路径（出口到入口）：";

  if (Traverse(1, M)) {
    cout << endl;
  } else {
    cout << "没有找到路径。" << endl;
  }

  DestroyMaze(M);
  return 0;
}