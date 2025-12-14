// Last updated: 12/14/2025, 4:15:39 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int freeDays = 0;
        int lastMeetingEnd = 0; // Track the end of last merged meeting

        for (auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Count free days before the next meeting
            if (start > lastMeetingEnd + 1) {
                freeDays += (start - lastMeetingEnd - 1);
            }
            
            // Merge overlapping intervals
            lastMeetingEnd = max(lastMeetingEnd, end);
        }

        // Count free days after the last meeting till total `days`
        if (lastMeetingEnd < days) {
            freeDays += (days - lastMeetingEnd);
        }

        return freeDays;
    }
};
