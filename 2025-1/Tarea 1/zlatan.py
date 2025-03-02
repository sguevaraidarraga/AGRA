"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem E: zlatan
    Enero 29 de 2025
"""

from sys import stdin
from heapq import heappush, heappop

class Card:
    def __init__(self, lbl, srl):
        self.label = lbl
        self.serial = srl
        self.ocurrences = 1
    def __lt__(self, b):
        ans = False
        if self.ocurrences != b.ocurrences:
            ans = self.ocurrences > b.ocurrences
        elif self.serial != b.serial:
            ans = self.serial > b.serial
        return ans
def main():
    n, m = map(int, stdin.readline().split())
    while n != 0 and m != 0:
        dic, pq, v = {}, [], []
        while n != 0:
            label, serial = stdin.readline().split()
            serial = int(serial)
            if label in dic:
                dic[label].ocurrences += 1
            else:
                dic[label] = Card(label, serial)
            n -= 1
        for key in dic:
            heappush(pq, dic[key])
        while m != 0:
            v.append(heappop(pq))
            m -= 1
        v.sort(key=lambda card: card.label)
        for i in v:
            print(f"{i.label} {i.ocurrences}")
        n, m = map(int, stdin.readline().split())
main()