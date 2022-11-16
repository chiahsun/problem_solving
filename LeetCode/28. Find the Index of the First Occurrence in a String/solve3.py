class Solution:
    # sadsadsadsac
    # sadsadsac
    # ---01234-
    # 01234578
    #    sadsadsac
    #    01234

    # aabaaac
    # -0-011-

    # issipi
    # ---0-0

    # saasabsacsacsad
    def strStr(self, haystack: str, needle: str) -> int:
        N = len(needle)
        prev = [-1] * N
        for i in range(1, N):
            pos = prev[i-1]
            while pos >= 0:
                if needle[i] == needle[pos+1]:
                    prev[i] = pos+1
                    break
                else:
                    pos = prev[pos]
            if pos < 0 and needle[i] == needle[0]:
                # print('i: ', i, ' set 0')
                prev[i] = 0
        # print(prev)
        pos = -1
        for i in range(len(haystack)):
            c = haystack[i]
            # print('Get: ', c, ' at pos: ', pos)
            while pos >= 0 and needle[pos+1] != c:
                pos = prev[pos]
            if pos >= 0:
                pos += 1
            elif needle[0] == c:
                pos = 0
            #print(' > pos: ', pos)    
            if pos == N-1:
                return i-N+1
        return -1

            

