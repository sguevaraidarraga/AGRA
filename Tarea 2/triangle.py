"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: triangle
    Febrero 10 de 2025
"""

from sys import stdin
from math import sqrt

def solve(ab, ratio):
    low, high = 0, ab
    c = ab*sqrt(ratio/(1+ratio))
    while high-low > 10**-10:
        mid = (low+high)/2
        if mid < c:
            low = mid
        else:
            high = mid
    return mid
def main():
    cases = int(stdin.readline())
    currCase = 1
    while cases:
        ab, ac, bc, ratio = map(float, stdin.readline().split())
        print(f"Case {currCase}: {solve(ab, ratio):.6f}")
        currCase += 1
        cases -= 1
main()