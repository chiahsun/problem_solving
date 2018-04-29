/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *end = head;
        while (end != NULL && end->next != NULL) { end = end->next; }

        return sortList(head, end);
    }
    
    ListNode* sortList(ListNode *lo, ListNode *hi) {
        if (hi == lo) { return lo; }
        if (hi == lo->next) { 
            if (hi->val < lo->val)
                std::swap(lo->val, hi->val);
            return lo;
        }
        
        ListNode* mid;
        int median = findMedianFromThreeNumber(lo, hi, mid);
        std::cout << "Start partition from median " << median << std::endl;
        print_list(lo, hi);
        ListNode *pl, *pv, *ph, *pmid;
        pl = pv = ph = lo;
        int count = 0;
        for (int step = 0; ; ++step) {
            const int cur_value = pv->val;
            std::cout << "Start for loop step " << step << " cur value " << cur_value << " median " << median << std::endl;
            if (cur_value > median) {
                std::cout << "  > step " << step << ": " << std::flush;
                if (ph == hi) {
                     pmid = pl;
                     break;
                } else {
                    ph = ph->next;
                    std::swap(pv->val, ph->val);
                }
            } else if (cur_value == median) {
                std::cout << "  = step " << step << ": " << std::flush;
                if (ph == hi) {
                    pmid = pl;
                    break;
                } else {
                    ph = ph->next;
                    pv = pv->next;
                }
                std::swap(pv->val, ph->val);
            } else {
                std::cout << "  < step " << step << ": " << std::flush;
                std::swap(pl->val, pv->val);
                if (pv == hi) {
                    pmid = pl;
                    break;
                }
                pl = pl->next; ++count;
                pv = pv->next;
                ph = (ph != hi) ? ph->next : ph;
                std::swap(pv->val, ph->val);
            }
            print_list(lo, hi);
        }
        std::cout << "End for loop" << std::endl;
        print_list(lo, hi);
      
        std::cout << "Go mid test+++" << std::endl; 
        while (pmid != hi && pmid != mid && pmid->val == median) {
            pmid = pmid->next;
        }
        sortList(lo, pmid);
        sortList(pmid, hi);
        return lo;
    }
    
    // lo, hi should not be NULL
    int findMedianFromThreeNumber(ListNode *lo, ListNode *hi, ListNode * & outMid) {
        ListNode *p1 = lo;
        outMid = p1;
        for (ListNode *p2 = lo, *p0 = lo; p2 != hi;) {
            p0 = p1;
            p1 = p1->next; outMid = p1;
            p2 = p2->next;
            if (p2 != hi) p2 = p2->next;
        }
        
        int value[3] = {lo->val, p1->val, hi->val};
        std::sort(value, value+sizeof(value)/sizeof(value[0]));
        
        return value[1];
    }
};
