class Solution:
  def lastNonEmptyString(self, s: str) -> str:
    ctr = Counter(s)

    mx = 0
    for item in ctr:
      mx = max(mx, ctr[item])

    valid = set()
    for item in ctr:
      if ctr[item] == mx:
        valid.add(item)

    ans = []
    x = len(s) - 1
    while x >= 0:
      if s[x] in valid:
        ans.append(s[x])
        valid.remove(s[x])
      x -= 1

    ansRev = ''.join(ans)[::-1]

    return ansRev

# topic: misc, string, counter
# time complexity: O(n), space complexity: O(1)
