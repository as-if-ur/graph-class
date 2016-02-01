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
		 int count = E ;
		 int src , dest ; 
		 while( count-- ) 
		 {
			 myfile >> src >> dest ;
			 G[src].push_back(dest) ;

		 }
	}

	void print_graph()
	{
		for( int i=1 ; i <= V ; i++ ) 
		{
			cout << i << "  ";
			for(int j= 0 ; j < G[i].size() ; j++ )
			{
				cout << G[i].at(j) << "  ";
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