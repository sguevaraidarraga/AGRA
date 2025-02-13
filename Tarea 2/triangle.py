"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: triangle
    Febrero 13 de 2025
"""

from sys import stdin
from math import sqrt

def solve(ab, ratio):
    low, high = 0, ab
    while high-low > 10**-10:
        mid = (low+high)/2
        r = mid**2 / (ab**2 - mid**2)
        if r < ratio:
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