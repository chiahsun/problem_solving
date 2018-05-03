class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        std::map<std::string, std::vector<std::string> > m; // content, path
        
        for (const auto & line : paths) {
            char dir[100], file_name[100], file_content[100];
            int nread;
            int ret = sscanf(line.c_str(), "%s%n", dir, &nread);
            int offset = nread;
            
            while ((ret = sscanf(line.c_str()+offset, "%*[ ]%[^(](%[^)])%n", file_name, file_content, &nread)) != 0) {
                std::string path = dir;
                path += "/";
                path += file_name;
                m[file_content].push_back(path);
                offset += nread;
                if (offset >= line.size()) break;
            }
        }
        
        std::vector<std::vector<std::string> > ans;
        for (const auto & pr : m) {
            if (pr.second.size() > 1) {
                ans.push_back(pr.second);
            }
        }
        return ans;
    }
};

