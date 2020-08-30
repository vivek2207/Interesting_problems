#include<iostream>
#include<queue>

using namespace std;



struct queueboard{
	int v;
	int dice;
};


int dicemin(int move[], int n){
	
	bool *visited=new bool[n];
	
	for (int i=0; i<n; i++){
		visited[i]=false;
	}
	
	queue<queueboard> q;
	
	visited[0]=true;
	queueboard s={0,0};
	q.push(s);
	
	queueboard qe;
	
	while (!q.empty()){
		qe = q.front(); 
		int v=qe.v;
		if (v==n-1){
			break;
		}
		q.pop();
		
		for(int j=v+1; j<v+7 && j<n; j++){
			if (!visited[j]){
				queueboard a;
				a.dice=qe.dice+1;
				visited[j]=true;
				if (move[j]!=-1){
					a.v=move[j];
				}
				else{
					a.v=j;
				}
				q.push(a);
			}
		}
	}
	return qe.dice;
}



int main(){
	int n=30;
	int board[n];
	
	for (int i=0; i<n; i++){
		board[i]=-1;
	}
	// Ladders
	board[2]=21;
	board[4]=7;
	board[10]=25;
	board[19]=28;
	//Snakes
	board[26]=0;
	board[20]=8;
	board[16]=3;
	board[18]=6;
	
	cout<<"Min dice required to reach: " <<dicemin(board, n);
	return 0;
}
