#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

class Graph {
private:
	int edgesList;
	int edgesMat;
	int nodes;
	std::vector<int> *adjList;
	int *adjMatrix;
public:
	Graph(int);
	void addEdgeAdjList(int, int);
	void depthSearchFirst(int, int);
	void depthHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&);
	void breadthSearchFirst(int, int);
	void breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&);
	void print_visited(list<int>);
	void print_path(vector<vector<int>>&,int ,int);
	bool contains(list<int>, int);
};

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++){
		adjMatrix[i] = 0;
	}
	edgesList = edgesMat = 0;
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

void Graph::depthSearchFirst(int start, int goal){
	stack <int> st;
	list <int> visited;
	vector <vector<int>> paths(nodes, vector<int>(1, -1));
	st.push(start);
	depthHelper(start, goal, st, visited, paths);
	print_path(paths, start, goal);
}

void Graph::depthHelper(int current,int goal,stack<int> &st,list<int> &visited,vector<vector<int>> &paths){
	if(current == goal){
		print_visited(visited);
	} else if(st.empty()){
		cout << " node not found";
	}	else {
		current = st.top();
		st.pop();
		visited.push_back(current);
		for(int  i = 0; i < adjList[current].size(); i++)
			if(!contains(visited, adjList[current][i])){
				st.push(adjList[current][i]);
				paths[adjList[current][i]][0] = current;
			}
		depthHelper(current, goal, st, visited, paths);
	}
}

void Graph::breadthSearchFirst(int start, int goal){
	queue <int> qu;
	list <int> visited;
    vector <vector<int>> paths(nodes, vector<int>(0));
	qu.push(start);
	breadthHelper(start, goal, qu, visited, paths);
	print_path(paths, start, goal);
}

void Graph::breadthHelper(int current,int goal,queue<int> &qu,list<int> &visited,vector<vector<int>> &paths){
	if(current == goal){
		print_visited(visited);
	}else if(qu.empty()){
		cout << " node not found";
	}else {
		current = qu.front();
		qu.pop();
		visited.push_back(current);
		for(int  i = 0; i < adjList[current].size(); i++)
			if(!contains(visited, adjList[current][i])){
				qu.push(adjList[current][i]);
				paths[adjList[current][i]].push_back(current);
			}
		breadthHelper(current, goal, qu, visited, paths);
	}
}


bool Graph::contains(list<int> ls, int node){
	list<int>::iterator it;
	it = find(ls.begin(), ls.end(), node);
	if(it != ls.end()){
		return true;
	}
	else{
		return false;
	}
}

void Graph::print_visited(list<int> q){
	cout << "Visitado: ";
	while (!q.empty()){
    cout << q.front() << " ";
    q.pop_front();
  }
  cout << endl;
}

void Graph::print_path(vector<vector <int>> &path, int start, int goal){
	int node =  path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	cout << "Mejor ruta: ";
	while (node != start) {
		reverse.push(node);
    node = path[node][0];
    }
	reverse.push(start);
	while (!reverse.empty()) {
		cout << reverse.top() << " ";
		reverse.pop();
    }
    cout << endl;
}

#endif