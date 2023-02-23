line1Split = [int(x) for x in input().split(" ")]
line2Split = [int(x) for x in input().split(" ")]

numbersSum = line2Split[0]
counter = 0
R = 0
outerLoop = 1

for i in range(line1Split[0]):
    if outerLoop == 0:
        break
    if i > 0:
        numbersSum -= line2Split[i - 1]
    #numbersSum += line2Split[i]
    for j in range(R, line1Split[0]):
        if j > i:
            if numbersSum <= line1Split[1]:
                counter += (j - i + 1)
                if R < line1Split[0] - 1:
                    R += 1
                    numbersSum += line2Split[R]
                else:
                    outerLoop = 0
            else:
                break
        elif j == i:
            if numbersSum <= line1Split[1]:
                counter += (j - i + 1)
                if R < line1Split[0] - 1:
                    R += 1
                    numbersSum += line2Split[R]
            else:
                if R < line1Split[0] - 1:
                    R += 1
                    numbersSum += line2Split[R]
                break

print(counter)