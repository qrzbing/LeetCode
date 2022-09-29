#include "global.hpp"

class TopVotedCandidate
{
    vector<int> winner;
    vector<int> win_times;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        // Save current persons in a hash map
        unordered_map<int, int> voteCounts;
        voteCounts[-1] = -1; // minium count
        int top = -1;
        win_times = times;
        for (int person : persons)
        {
            voteCounts[person] += 1;
            if (voteCounts[person] >= voteCounts[top])
            {
                top = person;
            }
            winner.emplace_back(top);
        }
    }

    int q(int t)
    {
        int pos = upper_bound(win_times.begin(), win_times.end(), t) - win_times.begin() - 1;
        return winner[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */