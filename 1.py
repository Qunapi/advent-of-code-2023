file = open("data-1.txt")

lines = []
numbers = []


for line in file.readlines():
    first_digit = ""
    last_digit = ""

    line = line.replace("one", "one1one")
    line = line.replace("two", "two2two")
    line = line.replace("three", "three3three")
    line = line.replace("four", "four4four")
    line = line.replace("five", "five5five")
    line = line.replace("six", "six6six")
    line = line.replace("seven", "seven7seven")
    line = line.replace("eight", "eight8eight")
    line = line.replace("nine", "nine9nine")

    for char in line:
        if char.isdigit():
            if first_digit == "":
                first_digit = char
            last_digit = char
    numbers.append([first_digit, last_digit])

sum = 0

for number in numbers:
    result_value = f"{number[0]}{number[1]}"
    print(result_value)
    int_value = int(result_value)
    sum += int_value

print(sum)
