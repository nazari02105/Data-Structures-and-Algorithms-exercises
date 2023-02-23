#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check (char* statement, int fixedStart, int fixedEnd, int first, int end){
    for (int i = 0; i<=first-fixedStart; ++i){
        if (*(statement+fixedStart+i) != *(statement+end+i)){
            return 0;
        }
    }
    return 1;
}

int main() {
    int number;
    scanf("%d", &number);
    getchar();
    for (int i = 0; i<number; ++i){
        int sum = 0;
        char* statement = malloc(1000000);
        gets(statement);
        int fixedStart = 0;
        int first = 0;
        int fixedEnd = strlen(statement) - 1;
        int end = fixedEnd;
        int firstNumber = 0;
        int secondNumber = 0;

        if (fixedEnd == 0){
            printf("1\n");
        }
        else {
            while (first < end) {
                firstNumber += (int) *(statement+first);
                secondNumber += (int) *(statement+end);
                if (firstNumber != secondNumber){
                    first += 1;
                    end -= 1;
                    if (first - end == 1) {
                        sum += 1;
                    }
                    if (first - end == 0) {
                        sum += 1;
                    }
                }
                else{
                    int secure = 0;
                    int result = check(statement, fixedStart, fixedEnd, first, end);
                    if (result == 0){
                        first += 1;
                        end -= 1;
                    }
                    if (result == 1) {
                        secure = 1;
                        sum += 2;
                        first += 1;
                        end -= 1;
                        fixedStart = first;
                        fixedEnd = end;
                        firstNumber = 0;
                        secondNumber = 0;
                    }
                    if (first - end == 1 && secure == 0) {
                        sum += 1;
                    }
                    if (first - end == 0) {
                        sum += 1;
                    }
                }
            }
            printf("%d\n", sum);
        }
        free(statement);
    }
    return 0;
}
