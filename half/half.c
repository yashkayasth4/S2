#include <stdio.h>
float calculateIndividualShare(float,float,float);
int main() {
    float billAmount, taxPercent, tipPercent;
    printf("Enter the bill amount before tax and tip: ");
    scanf("%f", &billAmount);
    printf("Enter the sales tax percent: ");
    scanf("%f", &taxPercent);
    printf("Enter the tip percent: ");
    scanf("%f", &tipPercent);
    float individualShare = calculateIndividualShare(billAmount, taxPercent, tipPercent);
    printf("Each person owes: $%.2f\n", individualShare);
    return 0;
}
float calculateIndividualShare(float billAmount, float taxPercent, float tipPercent) {
    float totalBill = billAmount + (billAmount * (taxPercent / 100));
    float tipAmount = totalBill * (tipPercent / 100);
    float individualShareWithoutTip = totalBill / 2;
    float individualShareWithTip = individualShareWithoutTip + (tipAmount / 2);
    return individualShareWithTip;
}