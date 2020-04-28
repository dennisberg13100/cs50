from cs50 import get_string

text = get_string("Text: ")
# print(text)
textLength = len(text)
# print(textLength)

letters = 0
words = 1
sentences = 0

for i in range(textLength):
    if text[i] == " ":
        words += 1
    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
    elif text[i].isalpha() == True:
        letters += 1

L = letters * 100 / words
S = sentences * 100 / words
index = round((L * 0.0588) - (S * 0.296) - 15.8)
# print(letters)
# print(words)
# print(sentences)
# print(index)

if index < 2:
    print("Before Grade 1")
elif index > 15:
    print("Grade 16+")
else:
    print(f"Grade {index}")