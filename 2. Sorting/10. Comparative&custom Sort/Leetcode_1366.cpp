// 1366. Rank Teams by Votes
// Problem:
// In a special ranking system, each voter gives a rank from highest to lowest to all teams.
// The votes array contains all such rankings. Rank the teams based on the votes following:
// higher counts at rank 1 are better, then rank 2, and so on; ties broken alphabetically.
//
// Link: `https://leetcode.com/problems/rank-teams-by-votes/`
//
// Constraints (LeetCode):
// - 1 <= votes.length <= 1000
// - 1 <= votes[i].length <= 26
// - votes[i] are permutations of uppercase English letters (teams are unique per vote)
//
// Expected Complexity:
// - Counting votes: O(V * T) where V = number of votes, T = teams per vote
// - Sorting with comparator: O(T log T * T) in worst case due to T-level comparison
// - Overall: O(V*T + T^2 log T)
// - Space: O(T^2)

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

// Solution Complexity:
// - Time: O(V*T + T^2 log T)
// - Space: O(T^2)