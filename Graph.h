#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;

class Graph
{
private:
    int **A;
    int vertex;
public:
    Graph()
    {
        vertex = 0;
        A = nullptr;
      //  A=NULL;
    }
    Graph(int a)
    {
        vertex = a;
        A = new int * [vertex];
        for(int i = 0; i < vertex; ++i)
            {
                A[i] = new int [vertex];
                for(int j = 0; j < vertex; ++j)
                    A[i][j] = false;
            }
    }
    ~Graph()
    {
        for(int i = 0; i < vertex; ++i)
            delete [] A[i];
        delete [] A;
    }
    Graph& operator=(const Graph& g)
    {
        for(int i = 0; i < vertex; ++i)
        {
            for (int j = 0; j < vertex; ++j)
            {
                A[i][j] = g.A[i][j];
            }
        }
        return *this;
    }
    void find_bridges()
    {
       // Graph *copyGraph=new Graph(vertex);
        for(int i = 0; i < vertex; ++i)
        {
            for(int j=i; j < vertex; ++j)
            {
                if(A[i][j] == true)
                    {
                   //     *copyGraph = *this;
                     //   for(int a = 0; a < vertex; ++a)
                       // {
                        //    copyGraph->A[i][a] = false;
                          //  copyGraph->A[j][a] = false;
                          //  copyGraph->A[a][i] = false;
                          //  copyGraph->A[a][j] = false;
                     //   }
                        if(!(isCoherent(i, j)))
                            cout << i << "  " << j <<endl;
                    }
            }
        }
    }
    void print_graph()
    {
        for(int i=0; i<vertex; ++i)
        {
            for(int j=i; j<vertex; ++j)
            {
                if(A[i][j] == true)
                    cout<<i<<" "<<j<<endl;
            }
        }
    }
    bool isCoherent(int first, int second)
    {
        vector<bool> visited(vertex,false);
        int v, u, nrvis = 0;
        stack<int> stos;
        if (vertex <= 2) return true;
        visited[first] = true;
        visited[second] = true;
        if(first != 0)
        {
            stos.push(0);
            visited[0] = true;
        }
        else if(second != 1)
        {
            stos.push(1);
            visited[1] = true;
        }
        else
        {
            stos.push(2);
            visited[2] = true;
        }
        while (stos.empty() == false)
        {
            v = stos.top();
            stos.pop();
            ++nrvis;
            for (int i = 0; i < vertex; ++i)
            {
                if(A[v][i]==true)
                {
                    u = i;
                    if (visited[u] == false)
                    {
                        visited[u] = true;
                        stos.push(u);
                    }
                }
            }
        }
        if (nrvis == vertex-2) return true;
        else return false;
    }
    bool input_file()
    {
        ifstream file;
        int i, j;
        file.open("Graph.txt");
        if (!file.good())
            return false;
        file >> vertex;
        A = new int * [vertex];
        for(i = 0; i < vertex; i++)
            A[i] = new int [vertex];
        while (file.good())
        {
            file >> i >> j;
            if (file.fail())
                break;
            A[i][j] = true;
            A[j][i] = true;
        }
        file.close();
        return true;
    }
};

#endif
