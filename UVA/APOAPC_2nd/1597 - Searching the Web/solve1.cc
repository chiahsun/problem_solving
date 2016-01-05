#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <algorithm>

const bool debug = false;

char buf[100];
char buf1[100];
char buf2[100];
char buf3[100];

typedef std::vector<std::string> Article;

typedef int StringId;
typedef int ArticleId;
typedef int LineNo;

const static std::vector<LineNo> EMPTY_LINENO_VEC;

struct Bucket {
    std::string _string;
    std::vector<ArticleId> _vecArticleId;
    std::map<ArticleId, std::vector<LineNo> > _mapArticleAndVecLineNo;
    Bucket(const std::string & s) : _string(s) { }
    const std::string & getString() const { return _string; }
    const std::vector<ArticleId> & getArticles() const { return _vecArticleId; }
    const std::vector<LineNo> & getLineNoFromArticle(ArticleId articleId) const { 
        if (not _mapArticleAndVecLineNo.count(articleId))
            return EMPTY_LINENO_VEC;
        return _mapArticleAndVecLineNo.find(articleId)->second; 
    }
     
    void addEntry(ArticleId articleId, LineNo lineNo) {
        if (getArticles().size() == 0 or getArticles().back() != articleId)
            _vecArticleId.push_back(articleId);
        if (_mapArticleAndVecLineNo[articleId].size() == 0 or _mapArticleAndVecLineNo[articleId].back() != lineNo)
            _mapArticleAndVecLineNo[articleId].push_back(lineNo);
    }

};

std::string get_alpha_num_string(const std::string & s) {
    int begin = 0;
    while (begin < s.size() and (not isalnum(s[begin]))) { ++begin; }
    if (begin >= s.size())
        return "";
    int end = begin;
    while (end < s.size() and isalnum(s[end])) { ++ end; }
    return s.substr(begin, end - begin);
}

std::string tolower_string(std::string s) {
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
    return s;
}

int getBucketId( const std::string & vocab
               , const std::map<std::string, StringId> & mapStringAndStringId
               , const std::vector<Bucket> & vecBucket) {
    auto it = mapStringAndStringId.find(vocab);
    if (it != mapStringAndStringId.end()) 
        return it->second; 
    
    return -1;
}

const std::vector<LineNo> & getLineNoFromArticleId( const std::string & vocab
                                                  , ArticleId articleId
                                                  , const std::map<std::string, StringId> & mapStringAndStringId
                                                  , const std::vector<Bucket> & vecBucket) { 
    int bucketId = getBucketId(vocab, mapStringAndStringId, vecBucket) ;
    if (bucketId >= 0) 
        return vecBucket[bucketId].getLineNoFromArticle(articleId);
    
    return EMPTY_LINENO_VEC;
}


const static std::vector<ArticleId> EMPTY_VEC;
const std::vector<ArticleId> & getArticlesFromString(const std::string & vocab, const std::map<std::string, StringId> & mapStringAndStringId, const std::vector<Bucket> & vecBucket) {
    int bucketId = getBucketId(vocab, mapStringAndStringId, vecBucket);
    if (bucketId >= 0) 
        return vecBucket[bucketId].getArticles();
    return EMPTY_VEC;
}

int main() {
    int nArticle;
    scanf("%d\n", &nArticle);

    std::vector<Article> vecArticle;
    while (nArticle--) {
        Article article;
        std::string line;
        do {
            line.clear();
            char c;
            while ((c = getchar()) != '\n') line.push_back(c);
            line.push_back('\n');
            if (line == "**********\n")
                break;
            article.push_back(line);
        } while (true);
        
        vecArticle.push_back(article);
    }

    std::map<std::string, StringId> mapStringAndStringId;
    std::vector<Bucket> vecBucket;
    std::string s;
    for (ArticleId posArticle = 0; posArticle < vecArticle.size(); ++posArticle) {
        const Article & article = vecArticle[posArticle];
        for (int posLine = 0; posLine < article.size(); ++posLine) {
            const std::string & line = article[posLine];
            for (int begin = 0, end = 0; begin < line.size(); begin = end+1) {
                while (begin < line.size() and (not isalpha(line[begin]))) { ++begin; }
                end = begin;
                while (end < line.size() and isalpha(line[end])) { ++end; }
                if (end > begin) {
                    std::string vocab = tolower_string(line.substr(begin, end-begin));
                    if (not mapStringAndStringId.count(vocab)) {
                        vecBucket.push_back(Bucket(vocab));
                        mapStringAndStringId.insert(std::make_pair(vocab, mapStringAndStringId.size()));
                    }
                    vecBucket[mapStringAndStringId[vocab]].addEntry(posArticle, posLine);
                }

                    
            }
        
        }
    }
    
    int nQuery;
    scanf("%d\n", &nQuery);

    while (nQuery--) {
        scanf("%[^\n]\n", buf);
        int nArg = sscanf(buf, "%s%s%s", buf1, buf2, buf3);
        if (debug) {
            printf("Current buf: %s\n", buf);
            printf("Current buf split : %s %s %s\n", buf1, buf2, buf3);
        }
        int printCnt = 0;
        if (nArg == 1) {
            int bucketId = getBucketId(buf1, mapStringAndStringId, vecBucket);
            bool isFirstArticle = true;
            if (bucketId >= 0) {
                const Bucket & curBucket = vecBucket[bucketId];
                for (ArticleId articleId : curBucket.getArticles()) {
                    if (isFirstArticle)
                        isFirstArticle = false;
                    else
                        printf("----------\n");

                    for (LineNo lineNo : curBucket.getLineNoFromArticle(articleId)) {
                        printf("%s", vecArticle[articleId][lineNo].c_str());
                        ++printCnt;
                    }
                }
            }
        } else if (nArg == 3) {
            const std::vector<ArticleId> & s1 = getArticlesFromString(buf1, mapStringAndStringId, vecBucket);
            const std::vector<ArticleId> & s2 = getArticlesFromString(buf3, mapStringAndStringId, vecBucket);
            std::set<ArticleId> s3;
            if (!strncmp(buf2, "AND", 3)) {
                set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
            } else { // OR
                set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
            }

            bool isFirstArticle = true;
            for (ArticleId id : s3) {
                std::set<LineNo> setLineNo;
                const std::vector<LineNo> & vec1 = getLineNoFromArticleId(buf1, id, mapStringAndStringId, vecBucket);
                const std::vector<LineNo> & vec2 = getLineNoFromArticleId(buf3, id, mapStringAndStringId, vecBucket);
                setLineNo.insert(vec1.begin(), vec1.end());
                setLineNo.insert(vec2.begin(), vec2.end());

                if (not setLineNo.empty()) {
                    if (isFirstArticle)
                        isFirstArticle = false;
                    else
                        printf("----------\n");
                    for (LineNo lineNo : setLineNo) {
                        printf("%s", vecArticle[id][lineNo].c_str());
                    }
                    ++printCnt;
                }
            }
        
        } else if (nArg == 2) {
            std::string vocab(buf2);
            const std::vector<ArticleId>& vec = getArticlesFromString(vocab, mapStringAndStringId, vecBucket);

            bool isFirstArticle = true;
            for (ArticleId articleId = 0, posVec = 0; articleId < vecArticle.size(); ++articleId) {
                bool isOk = true;
                if (posVec < vec.size()) {
                    if (vec[posVec] == articleId) {
                        ++posVec;
                        isOk = false;
                    } 
                }
                if (isOk) {
                    if (isFirstArticle)
                        isFirstArticle = false;
                    else
                        printf("----------\n");

                    for (const auto & s : vecArticle[articleId]) {
                        printf("%s", s.c_str());
                    }
                    ++printCnt;
                }

            }
        }

        if (printCnt == 0) 
            printf("Sorry, I found nothing.\n");
        printf("==========\n");

        
    }

    return 0;
}
