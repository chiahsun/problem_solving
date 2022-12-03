class MyCalendar:

    def __init__(self):
        self.A = []


    def book(self, start: int, end: int) -> bool:
        if not self.A:
            self.A.append((start, end))
            return True
        else:
            self.A.sort(key=lambda pr: pr[1])
            pos = bisect_right(self.A, start, key=lambda x: x[1])
            if pos == len(self.A) or end <= self.A[pos][0]:
                self.A.append((start, end))
                return True
            else:
                return False


            


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
