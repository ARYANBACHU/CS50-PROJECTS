from cs50 import get_int

count = 0
truth = False
card = get_int("Number: ")
backup = card
type = 0

while backup != 0:
    backup //= 10
    count += 1

two = card // (10 ** (count - 2))
one = card // (10 ** (count - 1))

if (count == 13 or count == 16) and one == 4:
    truth = True
    type = 1
elif count == 15 and (two == 34 or two == 37):
    truth = True
    type = 2
elif count == 16 and (51 <= two <= 55):
    truth = True
    type = 3
else:
    print("INVALID")
    exit()

if truth:
    sum = 0
    sum2 = 0
    for i in range(count):
        digit = card % 10
        card //= 10

        if i%2 == 1:
            num = digit * 2
            if num >= 10:
                sum = sum + num%10
                num //= 10
                sum = sum + num
            else:
                sum = sum + num
        else:
            sum2 = sum2 + digit

    if(sum + sum2)%10 == 0:
        if type == 1:
            print("VISA")
        if type == 2:
            print("AMEX")
        if type == 3:
            print("MASTERCARD")
    else:
        print("INVALID");
