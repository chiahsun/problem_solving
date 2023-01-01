# solve1.py

Use BFS. Integer tuple encoding

Runtime: 1184 ms

Your runtime beats 14.49 % of python3 submissions.

# solve2.py

Use character encoding

Runtime: 1480 ms

Your runtime beats 8.69 % of python3 submissions.

# solve3.py

No need to use distance map. Use queue swap trick.

Runtime: 904 ms

Your runtime beats 33.33 % of python3 submissions.

# solve4.py

Early return if next equals target

Runtime: 744 ms

Your runtime beats 68.12 % of python3 submissions.

# solve5.py

Ue yield for cleaner code

Runtime: 784 ms

Your runtime beats 52.17 % of python3 submissions.

# solve6.py

Enumerate is faster than range. [SO](https://stackoverflow.com/questions/4852944/what-is-faster-for-loop-using-enumerate-or-for-loop-using-xrange-in-python?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)

Runtime: 676 ms

Your runtime beats 79.71 % of python3 submissions.

# solve7.py

Change string concat method which is faster.(+ is faster than "".join) [SO](https://stackoverflow.com/questions/1228299/change-one-character-in-a-string/1228327#1228327) [Reference solution](http://bookshadow.com/weblog/2017/12/24/leetcode-open-the-lock/)
(Maybe it reuse original string if possible and there is only three elements)
("".join is O(n) I think and "+" should be O(n^2)) (Or changed?)


Runtime: 620 ms

Your runtime beats 84.06 % of python3 submissions.


# solve8.py

A* search

Runtime 388 ms Beats 97.12%

Memory 15.5 MB Beats 18.40%
