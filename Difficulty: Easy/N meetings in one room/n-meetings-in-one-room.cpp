//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> schedules;
        for(int i=0;i<n;i++) schedules.push_back(make_pair(start[i],end[i]));
        sort(schedules.begin(),schedules.end(),[](auto& a, auto& b) {
            return a.second<b.second;
        });
        int latestEndTime=-1,meetings=0;
        for(int i=0;i<n;i++) {
            int startTime=schedules[i].first,endTime=schedules[i].second;
            if(startTime>latestEndTime) {
                latestEndTime=endTime;
                meetings++;
            }
        }
        return meetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends