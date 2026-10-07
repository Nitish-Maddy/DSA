#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Job {
    int start;
    int end;
    int load;
};

int maxCPULoad(vector<Job>& jobs) {

    //Sort jobs according to start time
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.start < b.start;
    });
    
    //Min-heap;
    //{end time, CPU Load}
    priority_queue<pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>>> minHeap;

    int currentLoad = 0;
    int maxLoad = 0;
    
    for(Job job : jobs) {

        //Remove jobs that have already finished
        while(!minHeap.empty() && minHeap.top().first <= job.start) {
            currentLoad -= minHeap.top().second;
            minHeap.pop();
        }

        //Add current job
        minHeap.push({job.end, job.load});
        currentLoad += job.load;
        
        //Update maximum CPU load
        maxLoad = max(maxLoad, currentLoad);
    }

    return maxLoad;

}

int main() {

    vector<Job> jobs = { {1,4,3}, {2,5,4}, {7,9,6} };

    cout << "Maximum CPU Load = "
         << maxCPULoad(jobs) << endl;

    return 0;
}