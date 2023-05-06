class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)

        maxValue = 0

        for item in boxTypes:
            if item[0] <= truckSize:
                truckSize -= item[0]
                maxValue += item[1] * item[0]
            else:
                maxValue += item[1] * truckSize
                break

        return maxValue
