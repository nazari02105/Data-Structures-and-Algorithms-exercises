line1Split = input().split(" ")
line2Split = input().split(" ")

counter = 0
for i in range(int(line1Split[0])):
    for j in range(i, int(line1Split[0])):
        sum = 0
        for k in range(i, j+1):
            sum += int(line2Split[k])
        if sum <= int(line1Split[1]):
            counter += 1
        else:
            break


print(counter)