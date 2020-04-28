import sys
import cs50

if len(sys.argv) != 2:
    print("Usage: python roster.py house")

db = cs50.SQL("sqlite:///students.db")

house = sys.argv[1]
# print(house)

result = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first",
                    house)

for row in result:
    print(row['first'], end=' ')
    if row['middle'] != None:
        print(row['middle'], end=' ')
    print(row['last'], end=', born ')
    print(row['birth'])
