class Solution:
  def helper(self, mws, l, r, arr, dp) -> int:
    if l == r:
      dp[l] = arr[l]
      return dp[l]

    if dp[l] != -1:
      return dp[l]

    maxRes = 0
    maxEle = arr[l]

    mpws = min(mws, r - l + 1) # max possible window slide in this situation

    for wsize in range(1, mpws + 1):
      maxEle = max(maxEle, arr[l + wsize - 1])
      subsetRes = maxEle * wsize
      maxNextRes = self.helper(mws, l + wsize, r, arr, dp) if (l + wsize <= r) else 0
      maxRes = max(maxRes, subsetRes + maxNextRes)

    dp[l] = maxRes
    return dp[l]

  def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
    # sliding window?
    l, r = 0, len(arr) - 1
    dp=[-1] * len(arr)
    return self.helper(k, l, r, arr, dp)

"""
1 <= arr.length <= 500
0 <= arr[i] <= 10e9
1 <= k <= arr.length
"""

# test case generator
import random as r

mlen = 500
mval = 10**4
k = 2

ipt=[]

for _ in range(mlen):
    ipt.append(r.randint(1, mval))

print(f"[{','.join(map(str, ipt))}]")
