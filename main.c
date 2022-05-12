#include <stdio.h>
#include <string.h>
#include <math.h>

__int64 getconstructNumber( __int64 n, unsigned int k);

int getLength( __int64 number);

__int64 superDigit(__int64 number);

int sum( __int64 number);

void printResult( __int64 number, int i);

int getconstructNumber2(unsigned int n, unsigned int k);

int main() {
    unsigned int n, k;
    // taking input from user
    printf("Please enter a number (n=) :");
    scanf("%u", &n);
    printf("Please enter repetition factor (k=) :");
    scanf("%u", &k);

    __int64 concatenatedNumber = getconstructNumber(n, k);

    __int64 superNumber = superDigit(concatenatedNumber);
    printResult(concatenatedNumber, superNumber);

    return 0;
}




void printResult( __int64 concatenatedNumber, int superNumber) {
    printf("Super digit of number %lld is %d.", concatenatedNumber, superNumber);


}

__int64 superDigit(__int64 number) {
    if (getLength(number) == 1)
        return number;

    return superDigit(sum(number));

}

int sum( __int64 number) {
    int sum = 0;

    int remain=0;
    while (number != 0) {
        remain = number % 10;
        sum += remain;
        number /= 10;
    }
    return sum;
}


__int64 getconstructNumber( __int64 n, unsigned int k) {
    int length = getLength(n);
    int digitValue = pow(10, length);
    if (k == 1)
        return n;
    else
        return getconstructNumber(n, k - 1) * digitValue + n;


}
int getLength( __int64 number) {
    int length = 0;
    while (number != 0) {
        number = number / 10;
        length++;
    }
    return length;
}
