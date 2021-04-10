
#ifndef H_weightedGraph
#define H_weightedGraph

#include <cfloat>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "animationLibrary.h"
#include "graphType.h"

using namespace std;

class weightedGraphType : public graphType {
   public:
    void createWeightedGraph();
    // Function to create the graph and the weight matrix.
    // Postcondition: The graph using adjacency lists and
    //               its weight matrix is created.
    void shortestPath(int vertex);
    // Function to determine the weight of a shortest path
    // from vertex, that is, source, to every other vertex
    // in the graph.
    // Postcondition: The weight of the shortest path from
    //               vertex to every other vertex in the
    //               graph is determined.
    void printShortestDistance(int vertex);
    // Function to print the shortest weight from vertex
    // to the other vertex in the graph.
    // Postcondition: The weight of the shortest path from
    //               vertex to every other vertex in the
    //               graph is printed.

    weightedGraphType(int size = 0);
    // Constructor
    // Postcondition: gSize = 0; maxSize = size;
    //               graph is an array of pointers to linked
    //               lists.
    //               weights is a two-dimensional array to
    //               store the weights of the edges.
    //               smallestWeight is an array to store the
    //               smallest weight from source to vertices.

    ~weightedGraphType();
    // Destructor
    // The storage occupied by the vertices and the arrays
    // weights and smallestWeight is deallocated.

   protected:
    double **weights;        // pointer to create weight matrix
    double *smallestWeight;  // pointer to create the array to
                             // store the smallest weight from
                             // source to vertices
};

void weightedGraphType::createWeightedGraph() {
    ifstream infile;
    char fileName[50];
    // string fileName = "graphData.txt";

    int vertex;
    int adjacentVertex;

    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    infile.open(fileName);

    if (!infile) {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize;

    for (int index = 0; index < gSize; index++) {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999) {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        }
    }

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++) 
            weights[i][j] = DBL_MAX;

    double weight;

    infile >> vertex;
    while (infile) {
        infile >> adjacentVertex;
        while (adjacentVertex != -999) {
            infile >> weight;
            weights[vertex][adjacentVertex] = weight;
            infile >> adjacentVertex;
        }
        infile >> vertex;
    }
    infile.close();
}

void weightedGraphType::shortestPath(int vertex) {
    for (int j = 0; j < gSize; j++) smallestWeight[j] = weights[vertex][j];

    bool *weightFound;
    weightFound = new bool[gSize];

    for (int j = 0; j < gSize; j++) weightFound[j] = false;

    weightFound[vertex] = true;
    smallestWeight[vertex] = 0;

    for (int i = 0; i < gSize - 1; i++) {
        double minWeight = DBL_MAX;
        int v;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (smallestWeight[j] < minWeight) {
                    v = j;
                    minWeight = smallestWeight[v];
                }

        weightFound[v] = true;

        for (int j = 0; j < gSize; j++)
            if (!weightFound[j])
                if (minWeight + weights[v][j] < smallestWeight[j])
                    smallestWeight[j] = minWeight + weights[v][j];
    }  // end for
}  // end shortestPath

void weightedGraphType::printShortestDistance(int vertex) {
    cout << endl;
    typewriter("[Narrator] The Roomba wakes up in existential dread, just like any other Tuesday.\n"); delay(0.5);
    typewriter("[Narrator] It readies itself in the first room, ground zero.\n"); delay(0.5);
    typewriter("[Narrator] The sad little vaccuum begins scanning rooms to calculate todays path"); loadingDots(2); cout << endl; delay(0.5);
    typewriter("[Narrator] It comes back with the infamous NULLPTR EXCEPTION. Heartbroken, the Roomba tries again"); loadingDots(2); cout << endl; delay(0.5);
    typewriter("[Narrator] This time, the scan reports "); cout << gSize; typewriter(" rooms.\n\n");
    typewriter("-------------------------\n",0.025); delay(0.5);
    cout << "Rooms  Shortest Distance" << endl; delay(0.5);

    for (int j = 0; j < gSize; j++)
    {
        cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
        delay(0.25);
    }
    
    int shortestNum = 0;
    int temp = smallestWeight[1];
    for (int j = 1; j < gSize; j++)
    {
        if(smallestWeight[j] < temp)
        {
            shortestNum = j;
            temp = smallestWeight[j];
        }
    }
    typewriter("-------------------------\n",0.025); delay(0.5);
    cout << endl;
    typewriter("[Roomba]   \"Good enough... I guess\"\n\n"); delay(0.5);
    typewriter("[Narrator] Even though the poor guy has no potential, it does its work without complaint.\n"); delay(0.5);
    typewriter("[Narrator] Hmm... Amazon could really use more vaccuums like this one.\n"); delay(0.5);
    typewriter("[Narrator] No workers' rights necessary. Not that they had any to begin with"); loadingDots(1); cout << endl << endl; delay(0.5);
    typewriter("[Roomba]   \"Navigating to the closest room"); loadingDots(1); typewriter(" thats umm"); loadingDots(1); cout << " room " << shortestNum; typewriter(" I think?\"\n" ); delay(0.5);
    typewriter("[Narrator] Wondering why Cyber Jesus brought him into this world, the Roomba sulked to room "); cout << shortestNum << "." << endl; delay(0.5);
    typewriter("[Narrator] As the suffering vaccuum slaved away cleaning the Harrison Family Estate,"); delay(0.5); typewriter("\nthe Roomba managed to knock some framed pictures off of a table.\n"); delay(0.5);
    typewriter("[Roomba]   \"I'd say I suck at my job, "); delay(0.5); typewriter("but even that isn't true. "); delay(0.5); typewriter("I SUCK "); delay(0.5); typewriter("at SUCKING.\"\n"); delay(0.5); 
    typewriter("[Roomba]   \"Its my only job! "); delay(0.5); typewriter("Why did God curse me with this "); delay(0.5);
    typewriter("AWFUL "); delay(0.5); typewriter("EXISTENCE!\"\n"); delay(1);
    
}

// Constructor
weightedGraphType::weightedGraphType(int size) : graphType(size) {
    weights = new double *[size];

    for (int i = 0; i < size; i++) {
        weights[i] = new double[size];
    }
    smallestWeight = new double[size];
}

// Destructor
weightedGraphType::~weightedGraphType() {
    for (int i = 0; i < gSize; i++) delete[] weights[i];

    delete[] weights;
    delete smallestWeight;
}

#endif