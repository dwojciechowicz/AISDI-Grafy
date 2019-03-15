#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph;
    if(graph.input_file() == false)
        return 1;
    cout << "Graf:" << endl;
    graph.print_graph();
    cout << "Mosty:" << endl;
    graph.find_bridges();
    return 0;
}
