"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem E - zlatan
    Enero 22 de 2025
"""

from sys import stdin
from heapq import heappush, heappop

def main():
    n, m = map(int, stdin.readline().split())
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
        for _ in reversed(range(m)):
            counter, (label, serial) = heappop(pq)
            print(f"{label} {-counter}")
        n, m = map(int, stdin.readline().split())
main()