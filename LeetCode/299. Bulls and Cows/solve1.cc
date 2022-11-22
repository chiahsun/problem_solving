class Solution {
public:
    string getHint(string secret, string guess) {
        int cntS[10] = {0};
        int cntG[10] = {0};
        
        for (int i = 0; i < secret.size(); ++i) {
            ++cntS[secret[i]-'0'];
            ++cntG[guess[i]-'0'];
        }
        
        int cntB = 0;
        for (int i = 0; i < 10; ++i)
            cntB += std::min(cntS[i], cntG[i]);
            
        int cntA = 0;
        for (int i = 0; i < secret.size(); ++i)
            if (secret[i] == guess[i]) {
                ++cntA;
                --cntB;
            }
                
        return std::to_string(cntA) + "A" + std::to_string(cntB) + "B";
        
    }
};
