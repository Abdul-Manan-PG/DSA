// 1366. Rank teams by votes

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";
        if (votes.size() == 1) return votes[0];

        string teams = votes[0];
        const int numTeams = teams.size();
        
        // Initialize vote_count: teams × ranks (all 0)
        vector<vector<int>> vote_count(26, vector<int>(numTeams, 0)); // Assuming uppercase letters
        
        // Count votes for each team at each rank
        for (const string& vote : votes) {
            for (int rank = 0; rank < vote.size(); rank++) {
                char team = vote[rank];
                vote_count[team - 'A'][rank]++;
            }
        }
        
        // Custom comparator to sort teams based on vote counts
        auto cmp = [&](char a, char b) {
            for (int rank = 0; rank < numTeams; rank++) {
                if (vote_count[a - 'A'][rank] != vote_count[b - 'A'][rank]) {
                    return vote_count[a - 'A'][rank] > vote_count[b - 'A'][rank];
                }
            }
            return a < b; // If all ranks are equal, sort alphabetically
        };
        
        sort(teams.begin(), teams.end(), cmp);
        return teams;
    }
};

int main(){
    vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    Solution sol;
    cout << sol.rankTeams(votes); // Output: "ACB" (since A has the most 1st-place votes)
    return 0;
}