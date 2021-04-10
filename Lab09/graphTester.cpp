  
#include <iostream>
#include <fstream>

#include "weightedGraph.h"
#include "animationLibrary.h"
 
using namespace std;

int main() 
{
	weightedGraphType shortestPathGraph(50);
	shortestPathGraph.createWeightedGraph();
	cout << "\n" << endl;
	typewriter("The Tale of the Emotionally Distressed Roomba");
	cout << "\n----------------------------------------------" << endl; delay(2);
	shortestPathGraph.shortestPath(0);
	shortestPathGraph.printShortestDistance(0);

	cout << endl;

	return 0;
}