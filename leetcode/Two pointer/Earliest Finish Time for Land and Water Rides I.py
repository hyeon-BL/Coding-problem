class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        earliest = float('inf')
        for i in range(n):
            for j in range(m):
                earliest = min(earliest, max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j])
                earliest = min(earliest, max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i])
        return earliest
