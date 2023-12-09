#include <fstream>
#include <set>
#include <vector>

class Solution {

public:
    static void read(std::vector<std::vector<std::pair<long long, long long>>>& graph_Dijkstra)
    {
        std::ifstream fin("input.txt");
        long long n, m;
        fin >> n >> m;
        graph_Dijkstra.resize(n);
        long long u_i, v_i, w_i;
        for(long long i = 0; i < m; ++i)
        {
            fin >> u_i >> v_i >> w_i;
            u_i--;
            v_i--;
            auto pair1 = std::make_pair(v_i, w_i);
            graph_Dijkstra[u_i].push_back(pair1);
            auto pair2 = std::make_pair(u_i, w_i);
            graph_Dijkstra[v_i].push_back(pair2);
        }
    }

    static long long makeMinPath(std::vector<std::vector<std::pair<long long, long long>>>& graph_Dijkstra)
    {
        long long start = 0;
        long long n = graph_Dijkstra.size();

        std::vector<long long> distance(n, LLONG_MAX);
        std::set<std::pair<long long, long long>> set;

        distance[start] = 0;
        set.insert(std::make_pair(distance[start], start));

        while (set.size())
        {
            long long i = set.begin()->second;
            set.erase(set.begin());
            for(long long j= 0; j < graph_Dijkstra[i].size(); ++j)
            {
                long long vertex_index = graph_Dijkstra[i][j].first;
                long long weight = graph_Dijkstra[i][j].second;

                if(distance[i] + weight < distance[vertex_index])
                {
                    auto to_change = std::make_pair(distance[vertex_index], vertex_index);
                    set.erase(to_change);
                    distance[vertex_index] = distance[i] + weight;
                    to_change = std::make_pair(distance[vertex_index], vertex_index);
                    set.insert(to_change);
                }
            }
        }
        return distance[n - 1];
    }

    static void right(long long& ansver)
    {
        std::ofstream fout("output.txt");
        fout << ansver;
        fout.close();
    }
};

int main() {
    std::vector<std::vector<std::pair<long long, long long>>> graph_Dijkstra;
    Solution::read(graph_Dijkstra);
    long long answer = Solution::makeMinPath(graph_Dijkstra);
    Solution::right(answer);

    return 0;
}