#include <unordered_set>

class PRDS_MRU {

	public:
    int mruIndex = -1;

	PRDS_MRU(int count) {}

};

int Page_Replacement_MRU(vector<int>& pages, int nextpage, PRDS_MRU *p)
{

    bool found = false;
    int i;
    nextpage = abs(nextpage);

    /*
       Check if nextpage is in the pages array, if so return -1 and update mruIndex
    */
    for (i = 0; i < pages.size(); i++)
    {
        if (abs(pages[i]) == nextpage)
        {
            found = true;
            p->mruIndex = i;
            return -1;
        }
    }

    if (not found)
    {
        /*
           Check if there is an empty slot, if so return index for that slot
        */
        for (i = 0; i < pages.size(); i++) {
            if (pages[i] == 0) {
                pages[i] = nextpage;

                p->mruIndex = i;
                return p->mruIndex;
            }
        }
        /*
           Get the page to be replaced
        */

        return p->mruIndex;
    }

  return -1;
}
