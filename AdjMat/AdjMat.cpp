#include<iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std ;

class Graph 
{
	vector< vector<int> > G ; 
	int V , E ;

public :
	Graph ( string filename ) 
	{
		prepare_graph(filename) ;
	}

	void prepare_graph( string filename ) 
	{
		 ifstream myfile;
		 myfile.open(filename) ;

		 myfile >> V >> E ;
		 G.resize( V +1 ) ;

		 for( int i = 0 ; i <=V  ; i ++ )
			 G[i].resize( V+1 ) ;

		 for( int i = 0 ; i <=V  ;i ++ ) 
			 for( int j =0 ; j <=V ; j ++ ) 
				 G[i][j] = 0 ;

 		 int count = E ;
		 int src , dest ; 
		 while( count-- ) 
		 {
			 myfile >> src >> dest ;
			 G[src][dest] = 1 ;

		 }
	}

	void print_graph()
	{
		cout << "printing Adj Matrix " << endl ;
		for( int i=1 ; i <=V  ; i++ ) 
		{
			cout << "  ";
			for(int j= 1 ; j <= V ; j++ )
			{
				cout << G[i][j] << "  ";
			}
			cout << endl ;
		}
 	}
	
	


};



int main()
{
	Graph g = Graph( "input.txt" ) ;
	//g.prepare_graph( );
	g.print_graph();
}