class MyCalendar:

    def __init__(self):
        self.A, self.d = [], {}


    def book(self, start: int, end: int) -> bool:
        if not self.A:
            self.A.append(end)
            self.d[end] = start
            return True
        else:
            pos = bisect_right(self.A, start)
            if pos == len(self.A) or end <= self.d[self.A[pos]]:
                self.A.insert(pos, end)
                self.d[end] = start
                return True
            else:
                return False


            


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
