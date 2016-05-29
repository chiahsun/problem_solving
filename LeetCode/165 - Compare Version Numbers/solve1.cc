ass Solution {
public:
    int parseInt(const std::string & s, int & start) {
        const char* content = s.c_str();
        char* end;
        int x = strtol(s.c_str()+start, &end, 10);
        if (end - content < s.size()) ++end;
        start = (end - content);

        return x;
    }
    
    int compareVersion(string version1, string version2) {
        int i = 0, k = 0;
        
        while (i < version1.size() or k < version2.size()) {
            int x = parseInt(version1, i);
            int y = parseInt(version2, k);
            
            if (x < y) return -1;
            else if (x > y) return 1;
        }
        
        return 0;
    }
};
