class Solution {
  bool isValid(String s) {
    // https://api.flutter.dev/flutter/dart-core/List-class.html
    List<String> st = [];
    for (String c in s.split('')) {
        switch(c) {
            case '(':
            case '[':
            case '{':
                st.add(c);
            case ')':
                if (st.isEmpty || st.last != '(') return false;
                st.removeLast();
            case ']':
                if (st.isEmpty || st.last != '[') return false;
                st.removeLast();
             case '}':
                if (st.isEmpty || st.last != '{') return false;
                st.removeLast();
            default:
        }
    }
    return st.isEmpty;
  }
}
