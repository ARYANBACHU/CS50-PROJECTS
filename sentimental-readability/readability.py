from cs50 import get_string

text = get_string("Text: ")
words = 1
letters = 0
sentences = 0

for i in range(len(text)):
    a = text[i]
    if a.isalpha():
        letters += 1
    if a == '!' or a == '?' or a == '.':
        sentences += 1
    if a == ' ':
        words += 1

l = (letters/words) * 100
s = (sentences/words) * 100
index = (0.0588 * l) - (0.296 * s) - 15.8
ind = round(index)

if ind >= 16:
    print("Grade 16+")
elif ind < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(ind))

