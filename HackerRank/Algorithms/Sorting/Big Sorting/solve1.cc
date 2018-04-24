#include <bits/stdc++.h>

using namespace std;

struct BigIntComparator {
  bool operator() (const std::string & x, const std::string & y) const {
      if (x.size() != y.size()) return x.size() < y.size();
      for (int i = 0; i < x.size(); ++i) {
          if (x[i] != y[i]) {
              return x[i] < y[i];
          }
      }
      return false;
  }  
} bigIntComparator;

/*
 * Complete the bigSorting function below.
 */
vector<string> bigSorting(vector<string> unsorted) {
    /*
     * Write your code here.
     */
    std::sort(unsorted.begin(), unsorted.end(), bigIntComparator);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int unsorted_itr = 0; unsorted_itr < n; unsorted_itr++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[unsorted_itr] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

