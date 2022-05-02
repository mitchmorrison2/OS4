#include <unordered_set>

class PRDS_MRU {

	public:
    int mruValue;
    unordered_set<int> frames;
    int capacity = -1;

	PRDS_MRU(int count) {
        capacity = count;
    }

};

int Page_Replacement_MRU(vector<int>& pages, int nextpage, PRDS_MRU *p)
{
//    auto it = p->frames.find(nextpage);
//    if (it != p->frames.end()) {
//        return -1;
//    }
//    if (p->frames.find(abs(nextpage)) != p->frames.end()) {
//
//    }
  return -1;
}
