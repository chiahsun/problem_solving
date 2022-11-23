class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rs, re, cs, ce = 0, len(matrix), 0, len(matrix[0])
        res = []
        while ce > cs and re > rs:
            for i in (i for i in range(cs, ce) if rs < re):
                res.append(matrix[rs][i])
            rs += 1
            for i in (i for i in range(rs, re) if cs < ce):
                res.append(matrix[i][ce-1])
            ce -= 1
            # https://stackoverflow.com/questions/6981717/pythonic-way-to-combine-for-loop-and-if-statement
            for i in (i for i in range(ce-1, cs-1, -1) if rs < re):
                res.append(matrix[re-1][i])
            re -= 1
            for i in (i for i in range(re-1, rs-1, -1) if cs < ce):
                res.append(matrix[i][cs])
            cs += 1
        return res

