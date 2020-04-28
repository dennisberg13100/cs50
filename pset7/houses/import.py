import sys
import csv
import cs50

if len(sys.argv) != 2:
    print("Usage: python import.py database.csv")

data = []
dataTitle = []
dataContend = []

db = cs50.SQL("sqlite:///students.db")

with open(sys.argv[1], 'r') as csvfile:
    file = csv.reader(csvfile)
    for row in file:
        row[0] = row[0].split()
        data.append(row)

dataTitle = data[0]
dataContend = data
dataContend.pop(0)

# print(dataContend)
for row in dataContend:
    first = row[0][0]
    if len(row[0]) == 2:
        middle = None
        last = row[0][1]
    else:
        middle = row[0][1]
        last = row[0][2]
    house = row[1]
    birth = row[2]
    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
               first, middle, last, house, birth)
