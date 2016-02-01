#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

const bool debug = false;
char buf[300];
const int M = 5000+5;

struct HashMap {
    typedef std::string key_type;
    typedef int value_type;
    typedef std::pair<key_type, value_type> pair_type;
    typedef std::list<pair_type> list_type;
    typedef typename list_type::iterator list_iterator;
    std::vector<list_type> _vecList;
    int _size;
    HashMap() { clear(); }
    void clear() {
        _vecList.clear();
        _vecList.resize(M);
        _size = 0;
    }

    unsigned int hashCode(const std::string & s) {
        unsigned int sum = 0;
        for (auto c : s) {
            sum *= 31;
            sum += (c - 'a');
        }
        return sum % _vecList.size();
    }

    std::pair<bool, list_iterator> find(const key_type & key) {
        unsigned int index = hashCode(key);
        for (auto it = _vecList[index].begin(); it != _vecList[index].end(); ++it)
            if (key == it->first)
                return std::make_pair(true, it);
        return std::make_pair(false, _vecList[index].end());
    }

    int count(const key_type & key) { 
        return find(key).first ? 1 : 0;
    }

    void insert(const pair_type & pr) {
        unsigned int index = hashCode(pr.first);
        if (not find(pr.first).first) {
            _vecList[index].insert(_vecList[index].end(), pr);
            ++_size;
        }
    }
    int size() const { return _size; }
    value_type operator [] (const key_type & key) {
        return find(key).second->second;
    }
};


HashMap mapLanguageAndId;
HashMap mapWordAndId;
std::vector<std::string> vecWord;

const std::string & get_word(int word_id) { return vecWord[word_id]; } 

int get_lanuage_id() {
    scanf("%s", buf);
    if (not mapLanguageAndId.count(buf)) {
        mapLanguageAndId.insert(std::make_pair(buf, mapLanguageAndId.size()));
    }
    
    return mapLanguageAndId[buf];
}

int get_word_id() {
    scanf("%s", buf);
    if ((not mapWordAndId.count(buf))) {
        vecWord.push_back(buf);
        mapWordAndId.insert(std::make_pair(buf, mapWordAndId.size()));
    }
    return mapWordAndId[buf];
}

struct Edge {
    int _to, _word_id;
    Edge(int to, int word_id) : _to(to), _word_id(word_id) { }
    int to() const { return _to; }
    int cost() const { return word().size(); }
    int word_id() const { return _word_id; }
    const std::string & word() const { return get_word(_word_id); } 
}; 

std::vector<Edge> edges[M];
int distance[M][26];
const int NOT_REACHABLE = -1;

struct Now {
    int _position, _distance, _word_id;
    Now(int position, int distance, int word_id)
      : _position(position), _distance(distance), _word_id(word_id) { }
    const std::string & word() const { return get_word(_word_id); }
    int position() const { return _position; }
    int distance() const { return _distance; }
    bool operator < (const Now & rhs) const { return distance() > rhs.distance(); }
};

int main() {
    int nWord;
    while (scanf("%d", &nWord) == 1 and nWord) {
        mapLanguageAndId.clear();
        vecWord.clear(); vecWord.push_back("@");
        mapWordAndId.clear(); mapWordAndId.insert(std::make_pair("@", 0));

        int start_language = get_lanuage_id();
        int end_language = get_lanuage_id();

        for (int i = 0; i < M; ++i) {
            edges[i].clear();
            for (int k = 0; k < 26; ++k)
                distance[i][k] = NOT_REACHABLE;
        }

        
        std::priority_queue<Now> pq;
        for (int i = 0; i < nWord; ++i) {
            int from_language = get_lanuage_id();
            int to_language = get_lanuage_id();
            int word_id = get_word_id();
            int word_length = get_word(word_id).size();
            edges[from_language].push_back(Edge(to_language, word_id));
            edges[to_language].push_back(Edge(from_language, word_id));
            if (from_language == start_language or to_language == start_language) {
                if (from_language == start_language)
                    pq.push(Now(from_language, 0, 0));
                if (to_language == start_language)
                    pq.push(Now(to_language, 0, 0));
            } 
        }

        for (int i = 0; i < 26; ++i)
            distance[start_language][i] = 0;

        int min_end_distance = NOT_REACHABLE;
        while (not pq.empty()) {
            Now t = pq.top(); pq.pop();
            int cur_position = t.position();
            int cur_distance = t.distance();
            const std::string & cur_word = t.word();
            int cur_word_init_pos = cur_word[0] - 'a';
            if (debug)
                printf("pos : %d, dist : %d, word: %s\n", cur_position, cur_distance, cur_word.c_str());

            if (min_end_distance != NOT_REACHABLE and min_end_distance < cur_distance)
                break;

            for (const auto & e : edges[cur_position]) {
                int next_position = e.to();
                int next_distance = cur_distance + e.cost();
                int next_word_id = e.word_id();
                const std::string & next_word = e.word();
                int next_word_init_pos = next_word[0] - 'a';
                int old_distance = distance[next_position][next_word_init_pos];
                if (debug)
                    printf("    try next_pos %d next_dist %d next_word %s\n", next_position, next_distance, next_word.c_str());
                if (next_word[0] != cur_word[0] and (old_distance == NOT_REACHABLE or old_distance > next_distance)) {
                    if (debug)
                        printf("    add next_pos %d next_dist %d next_word %s\n", next_position, next_distance, next_word.c_str());
                    distance[next_position][next_word_init_pos] = next_distance;
                    pq.push(Now(next_position, next_distance, next_word_id));
                    if (next_position == end_language)
                        if (min_end_distance == NOT_REACHABLE or min_end_distance > next_distance)
                            min_end_distance = next_distance;
                }
            }
        }

        if (min_end_distance == NOT_REACHABLE)
            printf("impossivel\n");
        else
            printf("%d\n", min_end_distance);

    }

    return 0;
}
