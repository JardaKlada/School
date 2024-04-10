#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct Graph
{
    unordered_map<int, vector<int>> adjacency_list;
    unordered_map<int, int> vertex_to_mat_index;
    int no_of_verticles;
    int no_of_edges;
};

void printGraph(const Graph& graph)
{
    cout << "Graph:\n";
    for (const auto& [vertex, vertexes] : graph.adjacency_list)
    {
        cout << vertex << ": ";
        for(int neighbour : vertexes)
        {
            cout << neighbour << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

bool isIn(vector<int> searchIn, int searching){
    auto found = find(searchIn.begin(), searchIn.end(), searching);
    if (found == searchIn.end())
    {
        return 0;
    }
    return 1;
}

Graph readGraphFromFile(const string& filename)
{
    Graph graph;
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        stringstream sline(line);
        char separator;
        int vertex;
        vector<int> vertexes;

        while (sline >> vertex)
        {
            sline >> separator;
            vertexes.push_back(vertex);
        }

        for(int i = 1; i < vertexes.size(); i++)
        {
            auto found = find((graph.adjacency_list[vertexes[0]]).begin(), (graph.adjacency_list[vertexes[0]]).end(), vertexes[i]);
            if(found == graph.adjacency_list[vertexes[0]].end())
            {
                graph.adjacency_list[vertexes[0]].emplace_back(vertexes[i]);
            }
            auto found1 = find((graph.adjacency_list[vertexes[i]]).begin(), (graph.adjacency_list[vertexes[i]]).end(), vertexes[0]);
            if(found1 == graph.adjacency_list[vertexes[i]].end())
            {
                graph.adjacency_list[vertexes[i]].emplace_back(vertexes[0]);
            }
        }
    }

    graph.no_of_verticles = graph.adjacency_list.size();

    file.close();
    return graph;
}

vector<vector<int>> createAdjacencyMatrix (const Graph & graph) {
    int n = graph.no_of_verticles;
    vector<vector<int>> matrix (n, vector<int>(n, 0));
    for (const auto& [vertex, friends] : graph.adjacency_list)
    {
        for (int friend_ : friends){
            matrix[graph.vertex_to_mat_index.at(vertex)][graph.vertex_to_mat_index.at(friend_)] = 1;
            matrix[graph.vertex_to_mat_index.at(friend_)][graph.vertex_to_mat_index.at(vertex)] = 1;
        }
    }
    return matrix;
}

void constructIndexingMap(Graph& graph)
{
    int index = 0;
    unordered_map<int, int> res;
    for (const auto& kv : graph.adjacency_list)
    {
        res[kv.first] = index;
        index += 1;
    }
    graph.vertex_to_mat_index = res;
}

void printGraphIndexingMap(const Graph& graph)
{
    cout << "Graph vertex to index map:\n";
    for(const auto& [vertex, index] : graph.vertex_to_mat_index)
    {
        cout << vertex << ": " << index << ", ";
    }
    cout << endl;
}

void printMatrix(const vector<vector<int>>& matrix)
{
    for (auto& line : matrix)
    {
        for (int val : line)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Graph testGraph;
    string filename = "testfile.txt";
    testGraph = readGraphFromFile(filename);
    constructIndexingMap(testGraph);
    printGraph(testGraph);
    printGraphIndexingMap(testGraph);
    vector<vector<int>> adjacency_matrix = createAdjacencyMatrix(testGraph);
    printMatrix(adjacency_matrix);

    return 0;
}