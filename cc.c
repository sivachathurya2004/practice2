#include <stdio.h>
#include <string.h>

void generateParentheses(char *result, int pos, int open, int close, int n, int testCase) {
    if (close == n) {
        // Print the current valid combination
        printf("%s\n", result);
        return;
    }

    if (open < n) {
        result[pos] = '{';
        generateParentheses(result, pos + 1, open + 1, close, n, testCase);
    }

    if (close < open) {
        result[pos] = '}';
        generateParentheses(result, pos + 1, open, close + 1, n, testCase);
    }
}

void processTestCase(int n, int testCase) {
    printf("Test Case #%d:\n", testCase);
    char result[2 * n + 1];
    result[2 * n] = '\0';  // Null-terminate the string
    generateParentheses(result, 0, 0, 0, n, testCase);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        processTestCase(N, t);
    }

    return 0;
}

