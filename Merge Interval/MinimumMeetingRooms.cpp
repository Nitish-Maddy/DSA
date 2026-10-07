#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Minimum Meeting Rooms (LeetCode 253 / Minimum Platforms)
// Given arrival/start times and departure/end times of meetings, find the minimum
// number of meeting rooms required so that no two overlapping meetings share a room.
//
// Approach: Two-Pointer Chronological Sweep (Event-Based Simulation)
// - We sort start and end times independently because each start time creates a demand
//   for a room (+1) and each end time releases a room (-1). The exact pair doesn't matter;
//   only the timeline of room allocation and deallocation matters.
//
// Time Complexity: O(n log n) due to sorting start and end vectors
// Space Complexity: O(1) auxiliary space (modifying in-place, excluding sort stack O(log n))

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    int n = start.size();

    // Base case: If there are no meetings, no rooms are required
    if (n == 0) return 0;

    // Step 1: Sort start times and end times independently
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int room = 0; // Current active rooms in use at any point in time
    int res = 0;  // Maximum rooms needed simultaneously (peak demand)

    // Two pointers:
    // 'i' points to the next meeting that needs to start
    // 'j' points to the earliest ending meeting currently occupying a room
    int i = 0;
    int j = 0;

    // Iterate through all start and end events
    // We only need to check while i < n because once all meetings have started,
    // subsequent events are only meetings ending (which only decrease the room count).
    while(i < n && j < n) {

        // Case 1: A new meeting starts before the earliest ongoing meeting ends
        if(start[i] < end[j])
        {
            room++;               // Allocate a new room
            res = max(res, room); // Track the peak number of rooms required
            i++;                  // Move to the next meeting to be scheduled
        }
        // Case 2: A meeting has finished (or ends at the exact start time of the next meeting)
        else {
            room--; // A meeting concluded, so a room is released
            j++;    // Move to the next earliest ending meeting
        }
    }
    return res;
}

int main() {
    // Example test case:
    // Meeting times:
    // [9:00 - 9:10], [9:40 - 12:00], [9:50 - 11:20],
    // [11:00 - 11:30], [15:00 - 19:00], [18:00 - 20:00]
    vector<int> start = {900, 940, 950, 1100, 1500, 1800};
    vector<int> end = { 910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum Meeting Rooms Required: "
         << minMeetingRooms(start, end) << endl;

    return 0;
}