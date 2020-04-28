from cs50 import get_float

cash = get_float("Change owed: ")
while cash < 0:
    cash = get_float("Change owed: ")
cash = cash * 100
# print(cash)
coins = 0

while cash >= 25:
    coins += 1
    cash -= 25
    # print(cash)

while cash >= 10:
    coins += 1
    cash -= 10
    # print(cash)

while cash >= 5:
    coins += 1
    cash -= 5
    # print(cash)

while cash >= 1:
    coins += 1
    cash -= 1
    # print(cash)

print(coins)