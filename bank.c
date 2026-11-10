#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    FILE *fp = fopen("bank.txt", "a");
    struct Account a;
    printf("Enter Account No: ");
    scanf("%d", &a.accNo);
    printf("Enter Name: ");
    scanf("%s", a.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &a.balance);
    fprintf(fp, "%d %s %.2f\n", a.accNo, a.name, a.balance);
    fclose(fp);
    printf("Account Created Successfully!\n");
}

void displayAll() {
    FILE *fp = fopen("bank.txt", "r");
    struct Account a;
    if (fp == NULL) { printf("No accounts found!\n"); return; }
    printf("\n--- All Accounts ---\n");
    while (fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {
        printf("Acc No: %d | Name: %s | Balance: %.2f\n", a.accNo, a.name, a.balance);
    }
    fclose(fp);
}

void depositWithdraw(int type) {
    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Account a;
    int accNo, found = 0;
    float amount;
    printf("Enter Account No: ");
    scanf("%d", &accNo);
    printf("Enter Amount: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &a.accNo, a.name, &a.balance) != EOF) {
        if (a.accNo == accNo) {
            found = 1;
            if (type == 1) {
                a.balance += amount;
                printf("Deposited! New Balance: %.2f\n", a.balance);
            } else {
                if (a.balance >= amount) {
                    a.balance -= amount;
                    printf("Withdrawn! New Balance: %.2f\n", a.balance);
                } else {
                    printf("Insufficient Balance!\n");
                }
            }
        }
        fprintf(temp, "%d %s %.2f\n", a.accNo, a.name, a.balance);
    }
    if (!found) printf("Account Not Found!\n");
    fclose(fp); fclose(temp);
    remove("bank.txt"); rename("temp.txt", "bank.txt");
}

int main() {
    int ch;
    do {
        printf("\n--- BANKING SYSTEM ---\n");
        printf("1.Create Account 2.Display All 3.Deposit 4.Withdraw 5.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        if (ch == 1) createAccount();
        else if (ch == 2) displayAll();
        else if (ch == 3) depositWithdraw(1);
        else if (ch == 4) depositWithdraw(2);
    } while (ch != 5);
    printf("Thank you!\n");
    return 0;
}