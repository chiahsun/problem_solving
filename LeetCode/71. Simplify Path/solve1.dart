class Solution {
  String simplifyPath(String path) {
    List<String> st = [];
    print(path.split('/'));
    for (String s in path.split('/')) {
        if (s == '.' || s == '') continue;
        else if (s == '..') {
            if (!st.isEmpty) st.removeLast();
        } else {
            st.add(s);
        }
    }
    return "/" + st.join('/');
  }
}
