def solve(add, digit, low, high, list):
    if digit >= 10:
        return
    add = add*10 + digit
    if add >= low and add <= high:
        list.append(add)
    if add > high:
        return
    solve(add,digit+1,low,high,list)
class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        l = []
        for i in range(1,10):
            solve(0,i,low,high,l)
        l.sort()
        return l
        