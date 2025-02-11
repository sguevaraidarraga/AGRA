"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B: triangle
    Febrero 10 de 2025
"""

from math import sqrt
from os import stdin

def solve(AB, ratio):
    low, high = 0, AB
    c = AB*sqrt(ratio/(1+ratio))
    while high-low > 10**-10:
        mid = (low+high)/2
        if mid < c:
            low = mid
        else:
            high = mid
    return mid
def main():
    k = 1
    print(f"Case {k}: {round(solve(100, 2), 7)}")
main()