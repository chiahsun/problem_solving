class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        for c in s:
            if c == ']':
                pos = len(st)
                while pos-1 >= 0 and st[pos-1] != '[':
                    pos -= 1
                content = "".join(st[pos:])
                # print('content: ', content)
                st = st[:pos-1]
                pos = len(st)
                while pos-1 >=0 and st[pos-1].isnumeric():
                    pos -= 1
                # print('repeat: ', st[pos:])
                repeat = int("".join(st[pos:]))
                st = st[:pos]
                # print('st: ', st, 'content: ', content, 'repeat: ', repeat)
                st.append(content * repeat)
            else:
                st.append(c)
        #print(st)
        return "".join(st)
                    

