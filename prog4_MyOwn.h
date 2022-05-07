class PRDS_MyOwn {

	public:

    int capacity = -1;
    int* times;
    int counter = 0;
	PRDS_MyOwn(int count) {
        capacity = count;
        times = new int[count];
	}

};

int Page_Replacement_MyOwn(vector<int>& pages, int nextpage, PRDS_MyOwn *p)
{
    // this page replacement algorithm is the same as LRU except there is no priority to the pages that are dirty
    if (pages.size()) {

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
            } else if (p->times[b] < minVal) {
                minVal = p->times[b];
                min = b;
            }
        }
        if (min != INT_MAX) {
            // return min value and update counter
            pages[min] = nextpage;
            p->times[min] = p->counter;
            p->counter++;
            return min;
        }
    }

  return -1;
}
