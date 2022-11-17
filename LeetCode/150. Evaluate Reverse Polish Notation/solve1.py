class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for tkn in tokens:
            if tkn not in ["+", "-", "*",  "/"]:
                st.append(int(tkn))
            else:
                match tkn:
                    case "+":
                        st[-2] = st[-2] + st[-1]
                    case "-":
                        st[-2] = st[-2] - st[-1]
                    case "*":
                        st[-2] = st[-2] * st[-1]
                    case "/":
                        st[-2] = int(st[-2] / st[-1]) # round to zero
                st.pop()
        return st[0]
