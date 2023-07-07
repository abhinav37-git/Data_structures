#include <iostream>
using namespace std;

#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    int graph[][V] = {{0, 16, 11, 6},
                    {8, 0, 13, 16},
                    {4, 7, 0, 9},
                    {5, 12, 2, 0}};
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}
