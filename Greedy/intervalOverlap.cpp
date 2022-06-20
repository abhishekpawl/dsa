/* https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/110297/offering/1280151?leftPanelTab=0 */
#include <bits/stdc++.h>

struct Interval {
    int start;
    int end;
};

bool comp(Interval a, Interval b) {
    return a.start < b.start;
}

bool checkOverlappingIntervals(long* start, long* end, int n)
{
    Interval arr[n];
    
    for(int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
    }
    
    sort(arr, arr+n, comp);
    
    for(int i = 1; i < n; i++) {
        if(arr[i].start < arr[i-1].end) {
            return true;
        }
    }
    
    return false;
}
