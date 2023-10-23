#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("bst.in");
    int n, m;
    fin >> n;
    fin >> m;
    int value; std::string l_r; int who_parent;
    std::vector<int> Value(n);
    std::vector<int> Who_Parent(n);
    std::vector<std::pair<long long, long long>> Interval(n);
    std::ofstream fout("bst.out");
    Value[0] = m;
    Who_Parent[0] = 0;
    Interval[0] = std::make_pair(LLONG_MIN, LLONG_MAX);
    for (int i = 1; i < n; ++i)
    {
        fin >> value >> who_parent >> l_r;
        Value[i] = value;
        Who_Parent[i] = who_parent;
        l_r == "L" ?
        Interval[i] = std::make_pair(Interval[Who_Parent[i] - 1].first, Value[Who_Parent[i] - 1]) :
        Interval[i] = std::make_pair(Value[Who_Parent[i] - 1], Interval[Who_Parent[i] - 1].second);
        if (!(Interval[i].first <= value && value < Interval[i].second))
        {
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
    return 0;
}