"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem E - zlatan
    Enero 23 de 2025
"""

from heapq import heappush, heappop

class Card:
    def __init__(self, lbl, srl):
        self.label = lbl
        self.serial = srl
        self.ocurrences = 1
def main():
    n, m = map(int, input().split())
    while n != 0 and m != 0:
        dic, pq = {}, []
        while n != 0:
            label, serial = input().split()
            if label in dic:
                dic[label].ocurrences += 1
            else:
                dic[label] = Card(label, serial)
            n -= 1
        for key in dic:
            heappush(pq, dic[key])
        while m != 0:
            print(f"{pq[0].label} {pq[0].ocurrences}")
            m -= 1
        n, m = map(int, input().split())

"""
def main():
    n, m = map(int, input().split())
    while n != 0 and m != 0:
        dic, pq = {}, []
        for _ in range(n):
            label, serial = input().split()
            key = (label, serial)
            if key in dic:
                dic[key] += 1
            else:
                dic[key] = 1
        for key in dic:
            heappush(pq, (-dic[key], (key[0], key[1])))
        for _ in range(m):
            counter, (label, serial) = heappop(pq)
            print(f"{label} {-counter}")
        n, m = map(int, input().split())
"""

main()