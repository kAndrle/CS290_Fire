#include <iostream>
#include "forest.h"
using namespace std;

/*
forest.cpp is a collection of functions for manipulating, percolating, etc. a 2-dimensional array.
*/

/*
get_density: prompts a user for a density between 1 and 100. Returns the user's input, once it is valid.
*/
int get_density(){
	int density;
	cout<<"Please enter a density between 1 and 100"<<endl;
	cin.clear();
	cin >> density;
while(cin.fail() || !(density>=1 && density<=100)){
		cin.clear();
		cin >> density;
	}
	return density;
}


	/*
	Forest constructor: constructs a Forest object, and initializes the forest array with enum values based on requested tree density.
	*/
	Forest::Forest(int d){
		//rows = 30;
		//cols = 30;
		density = d;
		plant_forest();
		originalNumTrees = count_trees();
		trueOriginalDensity = 100.0*originalNumTrees/(rows*cols);
	}
	
	/*
	plant_forest: initializes a forest with a number of trees based on density.
	*/
	void Forest::plant_forest(){
		for(int i=0;i<rows;++i){
			for(int j=0;j<cols;++j){
				int chance = rand()%100 + 1;
				if(chance<density){
					forest[i][j] = TREE;
				}else{
					forest[i][j] = BARE;
				}
			}
		}
	
	}
	
	/*
	display_forest: prints the forest as a matrix in the console, where spaces represent BARE cells, T represents a TREE, and * represents BURNING.
	*/
	void Forest::display_forest() const {
		for(int j=0;j<cols;++j){
			cout<<"-";
		}
		cout<<"--"<<endl;
		for(int i=0;i<rows;++i){
			cout<<"-";
			for(int j=0;j<cols;++j){
				if(forest[i][j]==TREE){
					cout<<"T";
				}else if(forest[i][j]==BURNING){
					cout<<"*";
				}else if(forest[i][j]==BARE){
					cout<<" ";
				}
			}
			cout<<"-"<<endl;
		}
		for(int j=0;j<cols;++j){
			cout<<"-";
		}
		cout<<"--"<<endl;
	}
	
	/*
	nextState: gives the state of the cell in question after percolation. essentially, if any neighbors of a TREE are BURNING, the TREE will be BURNING after percolation.
	*/
	cell Forest::nextState(int r, int c){
		// if the cell in question is not a TREE, it cannot ignite:
		if(forest[r][c] == BARE){
			return BARE;
		}
		if(forest[r][c] == BURNING){
			return BURNING;
		}
		// first attempt to check the three neighbors to the left:
		if(r>0){
			if(forest[r-1][c]==BURNING){
				return BURNING;
			}
			if(c>0 && forest[r-1][c-1]==BURNING){
				return BURNING;
			}
			if(c<cols-1 && forest[r-1][c+1]==BURNING){
				return BURNING;
			}
		}
		// now the three to the right:
		if(r<rows-1){
			if(forest[r+1][c]==BURNING){
				return BURNING;
			}
			if(c>0 && forest[r+1][c-1]==BURNING){
				return BURNING;
			}
			if(c<cols-1 && forest[r+1][c+1]==BURNING){
				return BURNING;
			}
		}
		// now to check the cells directly above and below:
		if(c>0 && forest[r][c-1]==BURNING){
			return BURNING;
		}
		if(c<cols-1 && forest[r][c+1]==BURNING){
			return BURNING;
		}
		// if all neighbors are not burning, return TREE:
		return TREE;
	}
	
	/*
	percolate_frame: percolates every cell in the forest array, recording the number of ignitions.
	*/
	int Forest::percolate_frame(){
		cell nextFrame[rows][cols];
		int changes = 0;
		for(int i=0;i<rows;++i){
			for(int j=0;j<cols;++j){
				nextFrame[i][j] = nextState(i,j);
				// if a tree is ignited, a change is recorded:
				if(nextFrame[i][j]==BURNING && forest[i][j]==TREE){
					changes++;
				}
			}
		}
		for(int i=0;i<rows;++i){
			for(int j=0;j<cols;++j){
				forest[i][j] = nextFrame[i][j];
			}
		}
		return changes;
	}
	
	/*
	ignite_forest: changes any TREEs in the first row to be BURNING.
	*/
	void Forest::ignite_forest(){
		for(int j=0;j<cols;++j){
			if(forest[0][j]==TREE){
				forest[0][j]=BURNING;
			}
		}
	}
	
	/*
	percolate_forest: repeats percolate_frame until there is a percolation with 0 ignitions.
	*/
	void Forest::percolate_forest(){
		ignite_forest();
		int changes=1;
		while(changes!=0){
			changes = percolate_frame();
		}
	}
	
	/*
	count_trees: returns the number of TREEs in the array.
	*/
	int Forest::count_trees(){
		int count = 0;
		for(int i=0;i<rows;++i){
			for(int j=0;j<cols;++j){
				if(forest[i][j]==TREE){
					count++;
				}
			}
		}
		return count;
	}
		
	/*
	report: prints data about the forest before and after percolation.
	*/
	void Forest::report(){
		cout<<"Requested density: "<<density<<endl;
		cout<<"Trees planted: "<<originalNumTrees<<endl;
		cout<<"Actual pre-fire density: "<<trueOriginalDensity<<endl;
		cout<<"Surviving trees: "<<count_trees()<<endl;
		cout<<"Post-fire density: "<<100.0*count_trees()/(rows*cols)<<endl;
	}
	 
