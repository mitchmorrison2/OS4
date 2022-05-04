#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class PRDS_LRUclean {

   public:
    int capacity = -1;
    int* times;
    int counter = 0;
   PRDS_LRUclean(int count) {
       capacity = count;
       times = new int[count];
   }

};

int Page_Replacement_LRUclean(vector<int>& pages, int nextpage, PRDS_LRUclean *p) {
    int i;
    int posnextpage = abs(nextpage);
    int negCount = 0;

    // check if it already exists in pages
    for (i = 0; i < pages.size(); i++) {
        if (abs(pages[i]) == posnextpage) {
            p->times[i] = p->counter;
            p->counter++;
            return -1;
        }
    }

    // find min(times) and use that index for replace
    int min = -1;
    int minVal = INT_MAX;
    for (int b = 0; b < p->capacity; b++) {
        if (pages[b] == 0) {
            min = b;
            break;
        }
        else if (p->times[b] < minVal && pages[b] > 0) {
            minVal = p->times[b];
            min = b;
        }
        else if (pages[b] < 0) {
            negCount++;
        }
    }
    if (min != INT_MAX && negCount != p->capacity) {
        // all frames are not negatives - the current frame is not a negative value
        pages[min] = nextpage;
        p->times[min] = p->counter;
        p->counter++;
        return min;
    }
    if (negCount == p->capacity) {
        // all are negative find the minVal again
        int min = -1;
        int minVal = INT_MAX;
        for (int b = 0; b < p->capacity; b++) {
            if (p->times[b] < minVal) {
                min = b;
                minVal = p->times[b];
                p->times[b] = p->counter;
                p->counter++;
            }
        }
        return min;
    }

  return -1;
}
