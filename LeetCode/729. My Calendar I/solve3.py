from sortedcontainers import SortedDict
class MyCalendar:

    def __init__(self):
        self.d = SortedDict()


    def book(self, start: int, end: int) -> bool:
        if not self.d:
            self.d[end] = start
            return True
        else:
            keys = list(self.d.keys())
            pos = bisect_right(keys, start)
            if pos == len(self.d) or end <= self.d[keys[pos]]:
                self.d[end] = start
                return True
            else:
                return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
