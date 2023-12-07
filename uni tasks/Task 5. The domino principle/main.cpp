#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

class Solution
{
public:
    static std::vector<std::vector<int>> makeMatrix(int& n)
    {
        std::ifstream fin("in.txt");
        fin >> n;
        std::vector<std::vector<int>> graph(n, std::vector<int>());
        int N;
        for(int i = 0; i < n; ++i)
        {
            fin >> N;
            graph[i].resize(N);
            int a;
            for (int j = 0; j < N; ++j)
            {
                fin >> a;
                a--;
                graph[i][j] = a;
            }
        }
        fin.close();
        return graph;
    }

    static void BFS(std::vector<std::vector<int>>& graph, int start, int& max_distance)
    {
        std::queue<int> queue;
        std::vector<bool> used_bool(graph.size(), false);

        queue.push(start);
        used_bool[start] = true;

        int time = 0, vertexes = 0;

        while (queue.size() /*&& vertexes < graph.size()*/)
        {
            int count = queue.size();
            time++;
            vertexes += count;
            for (int j = 0; j < count; j++)
            {
                int index = queue.front();
                queue.pop();
                for (int i = 0; i < graph[index].size(); i++) {
                    check_vertex( queue, used_bool, graph[index][i]);
                }
            }
        }
        if(vertexes >= graph.size())
        {
            max_distance = time - 1;
        }
        else
        {
            max_distance = -1;
        }
    }

    static void check_vertex( std::queue<int>& queue, std::vector<bool>& used_bool, int& i);
};


void Solution::check_vertex(std::queue<int>& queue, std::vector<bool>& used_bool, int& i)
{
    if (!used_bool[i]) {
        queue.push(i);
        used_bool[i] = true;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int vertex, n, max_time;
    std::ofstream fout("out.txt");

    std::vector<std::vector<int>> graph = Solution::makeMatrix(n);

    int time = -1;
    for (int i = 0; i < n; i++)
    {
    Solution::BFS(graph, i, max_time);
        if (max_time >= time)
        {
            vertex = i + 1;
            time = max_time;
        }
    }
    if (time > -1) {
        fout << time << '\n' << vertex;
    }
    else {
        fout << "impossible";
    }
    fout.close();
}