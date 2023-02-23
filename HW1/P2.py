inputLine1 = input()
inputLine2 = input()

line1Split = inputLine1.split(" ")
line2Split = inputLine2.split(" ")

counter = 0
for i in range(int(line1Split[0])):
    sumOfNumbers = 0
    for j in range(i, int(line1Split[0])):
        sumOfNumbers += int(line2Split[j])
        if sumOfNumbers <= int(line1Split[1]):
            counter += 1
        else:
            break


print(counter)