"""
    Arboles y Grafos 2025-1
    Santiago Guevara Idarraga
    Problem B - drutojan
    Enero 24 de 2025
"""

from collections import deque

class Person:
    def __init__(self, list):
        self.timeSpent = 0
        self.namesList = list
    def __str__(self):
        return f"{self.timeSpent}"
def main():
    cases = int(input())
    names = ["Ja", "Sam", "Sha", "Sid", "Tan"]
    currCase = 1
    while cases:
        data = {}
        mins, arrivalTime, sitting = input().split()
        mins, arrivalTime = int(mins), int(arrivalTime)
        for i in range(len(names)):
            ln = deque(input().split())
            ln.popleft()
            p = Person(ln)
            data[names[i]] = p
        i = 0
        while i < arrivalTime:
            p = data[sitting]
            i += mins
            if i < arrivalTime:
                p.timeSpent += mins
            else:
                p.timeSpent += mins-(i-arrivalTime)
            sitting = p.namesList[0]
            p.namesList.popleft()
            p.namesList.append(sitting)
            i += 2
        print(f"Case {currCase}:")
        for key in data:
            print(f"{key} {data[key]}")
        currCase += 1
        cases -= 1
main()