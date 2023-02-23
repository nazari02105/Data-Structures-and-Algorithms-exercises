#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    int numbers[number];
    int numbers2[number];
    for (int i = 0; i<number; ++i){
        if (i == number-1){
            int x;
            scanf("%d", &x);
            numbers[i] = x;
            numbers2[i] = 0;
        }
        else{
            int x;
            scanf("%d ", &x);
            numbers[i] = x;
            numbers2[i] = 0;
        }
    }

    int mainMax = 0;
    for (int i = number - 1; i>=0; --i){
        int counter = i+1;
        while (counter < number && numbers[i] > numbers[counter]){
            if (numbers[counter] != -1){
                numbers[counter] = -1;
                numbers2[i] += 1;
                if (numbers2[counter] > numbers2[i]){
                    numbers2[i] = numbers2[counter];
                }
                if (mainMax < numbers2[i]){
                    mainMax = numbers2[i];
                }

            }
            counter += 1;
        }
    }
    printf("%d", mainMax);






















//    int toDelete = -1;
//    int max = -1;
//    for (int i = 0; i<number; ++i){
//        int thisTime = 0;
//        for (int j = i-1; j >= 0; --j){
//            if (numbers[j] > numbers[i]){
//                thisTime += 1;
//                if (toDelete != i && toDelete != -1){
//                    numbers[toDelete] = -1;
//                }
//                toDelete = i;
//                break;
//            }
//            else{
//                if (j == 0){
//                    if (toDelete != i && toDelete != -1){
//                        numbers[toDelete] = -1;
//                        toDelete = -1;
//                    }
//                    thisTime = 0;
//                    break;
//                }
//                else{
//                    if (numbers[j] != -1){
//                        thisTime += 1;
//                    }
//                }
//            }
//        }
//        if (thisTime > max){
//            max = thisTime;
//        }
//    }
//
//
//    printf("%d", max);

    return 0;
}
