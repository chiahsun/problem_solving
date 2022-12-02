class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.time_to_live = timeToLive
        self.d = {}
        

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.d[tokenId] = currentTime

    def renew(self, tokenId: str, currentTime: int) -> None:
        if tokenId in self.d:
            old_time = self.d[tokenId]
            if old_time+self.time_to_live > currentTime:
                self.d[tokenId] = currentTime

    def countUnexpiredTokens(self, currentTime: int) -> int:
        cnt = 0
        for token, time in self.d.items():
            if time+self.time_to_live > currentTime:
                cnt += 1
        return cnt
        


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)
