#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <set>

class SetRepr {
    typedef std::set<int> InnerRepr;

    int _uid;
public:
    SetRepr(InnerRepr repr) {
        std::map<InnerRepr, int>::iterator it;
        if ((it = sMapInnerReprAndId.find(repr)) != sMapInnerReprAndId.end()) {
            _uid = it->second;
        } else {
            _uid = sMapIdAndInnerRepr.size();
            sMapIdAndInnerRepr.insert(std::make_pair(_uid, repr));
            sMapInnerReprAndId.insert(std::make_pair(repr, _uid));
        }
    }
    SetRepr() {
        _uid = 0;
        if (sMapIdAndInnerRepr.size() == 0) {
            sMapIdAndInnerRepr.insert(std::make_pair(0, InnerRepr()));
            sMapInnerReprAndId.insert(std::make_pair(InnerRepr(), 0));
        }
    }
    static SetRepr makeUnion(const SetRepr & s1, const SetRepr & s2) {
        InnerRepr i1 = s1.getInnerRepr();
        InnerRepr i2 = s2.getInnerRepr();
        for (const auto & x : i1) {
            i2.insert(x);
        }

        return SetRepr(i2);
    }
    static SetRepr makeIntersect(const SetRepr &s1, const SetRepr & s2) {
        InnerRepr i1 = s1.getInnerRepr();
        InnerRepr i2 = s2.getInnerRepr();
        InnerRepr ii;
        for (const auto & x : i1) {
            if (i2.count(x))
                ii.insert(x);
        }

        return SetRepr(ii);
    }
    SetRepr & addSet(const SetRepr & rhs) {
        InnerRepr i = getInnerRepr();
        i.insert(rhs.getId());
        return (*this = SetRepr(i));
    }
    int size() const { return getInnerRepr().size(); }
    bool operator == (const SetRepr & rhs) const { return _uid == rhs._uid; }

    InnerRepr getInnerRepr() const { return sMapIdAndInnerRepr[getId()]; }
    int getId() const { return _uid; }

    static std::map<int, InnerRepr> sMapIdAndInnerRepr;
    static std::map<InnerRepr, int> sMapInnerReprAndId;
    static void resetRepr() {
        sMapIdAndInnerRepr.clear();
        sMapInnerReprAndId.clear();
        sMapIdAndInnerRepr.insert(std::make_pair(0, InnerRepr()));
        sMapInnerReprAndId.insert(std::make_pair(InnerRepr(), 0));
    }
};
    
std::map<int, SetRepr::InnerRepr> SetRepr::sMapIdAndInnerRepr;
std::map<SetRepr::InnerRepr, int> SetRepr::sMapInnerReprAndId;



typedef std::stack<SetRepr> SetStack;

char cmd[10];
int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        SetRepr::resetRepr();
        SetStack st;

        int nCommand;
        scanf("%d", &nCommand);
        while (nCommand--) {
            scanf("%s", cmd);
            if (!strncmp(cmd, "PUSH", 4)) {
                st.push(SetRepr());
            } else if (!strncmp(cmd, "DUP", 3)) {
                st.push(st.top());
            } else if (!strncmp(cmd, "UNION", 5)) {
                SetRepr s1 = st.top(); st.pop();
                SetRepr s2 = st.top(); st.pop();
                st.push(SetRepr::makeUnion(s1, s2));
            } else if (!strncmp(cmd, "INTERSECT", 9)) {
                SetRepr s1 = st.top(); st.pop();
                SetRepr s2 = st.top(); st.pop();
                st.push(SetRepr::makeIntersect(s1, s2));
            } else if (!strncmp(cmd, "ADD", 3)) {
                SetRepr s1 = st.top(); st.pop();
                SetRepr s2 = st.top(); st.pop();
                s2.addSet(s1);
                st.push(s2);
            }
            printf("%d\n", st.top().size());
        }
        printf("***\n");

    }

    return 0;
}
