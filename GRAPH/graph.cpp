// CODE FOR REPRESENTING A ADJACENCY LIST IN A GRAPH 

#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph {
  public:

  unordered_map<int, list<int> > adj ;

  void addEdge(int u, int v, bool direction){
        // direction ->0 // undirected edge
        // direction ->1 // directed edge

        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
  }

  void printAdjList(){
    
        for(auto i: adj){
            cout<< i.first <<" -> ";
            for(auto j: i.second){
                cout<< j <<",";
            }
            cout<<endl;
        }
  }

};

int main(){
    
    int n ;
    cout<<"enter the no. of edges :  " ;
    cin>>n;

    int m;
    cout<<"enter the no. of edges:  "  ;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u , v;
        cin>>u>>v;
        // creating an edge
        g.addEdge(u,v,0);
    }
  
      // printing graph
      g.printAdjList();

    return 0;
}