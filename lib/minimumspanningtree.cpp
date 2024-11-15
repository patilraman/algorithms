#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct mstree{
    char id;
    int weight;
};

class edge{
    char u;
    char v;
    int weight;
};

//Merge sort
void sort(vector<vector<mstree> > &graph, vector<edge> & A)
{
   size_t row = sizeof(graph)/sizeof(mstree);
   size_t col = sizeof(graph[0])/sizeof(mstree);
   cout<<"row="<<row<<" col="<<col<<'\n';
   for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    {
        A[i*row+j].weight = graph[i][j];
    }
    size_t sz = sizeof(A);
    for(int i=0;i<sz;i++)
        for(int j=0<sz;j++)
    {
        //mstree tmp;
    }

}
void mst_kruskal(vector<vector<mstree> > & graph )
{
    size_t sz = sizeof(graph)*sizeof(graph[0]);
    vector<edge> A(sz);
    size_t row = sizeof(graph);

    cout<<"size = "<<sz<<"row = "<<row;

    sort(graph, A);
}

int main()
{

    vector<vector<mstree>> graph = {
                                    {{'a',0},{'b',4},{'h',8}},
                                    {{'b',0},{'a',4},{'c',8},{'h',11}},
                                    { {'c',0}, {'b',8}, {'d',7}, {'i',2}},
                                    { {'d',0}, {'c',7}, {'e',9}, {'f', 14}},
                                    { {'e',0}, {'d',9}, {'f',10}},
                                    { {'f',0}, {'c',4}, {'e',10}, {'g',2}},
                                    { {'g',0}, {'f',2}, {'i',6}, {'h',1}},
                                    { {'h',0}, {'a',8}, {'g',1}, {'i',7}}
                                    };

    mst_kruskal(graph);
    vector<int> t(5);
}