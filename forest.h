#ifndef FOREST_H
#define FOREST_H

int get_density();
enum cell{
	TREE,BARE,BURNING
};
//cell[][] plant_forest();
class Forest{
	
	const int rows = 30;
	const int cols = 30;
	int density;
	int originalNumTrees;
	double trueOriginalDensity;
	cell forest[30][30];
	
	private:
	void plant_forest();
	cell nextState(int r, int c);
	int percolate_frame();
	void ignite_forest();
	int count_trees();
	
	public:
	Forest(int d);
	void display_forest() const;
	void percolate_forest();
	void report();
	
};



#endif