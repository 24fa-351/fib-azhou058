#include <stdio.h>
#include <stdlib.h>

int fib_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    int first_number = 0;
    int second_number = 1;
    int next_number;

    for (int i = 2; i <= n; i++) {
        next_number = first_number + second_number;
        first_number = second_number;
        second_number = next_number;
    }
    return second_number;
}

int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    } else {
         return (fib_recursive(n - 1) + fib_recursive(n - 2));
    }
}

int main(int argc, char *argv[]) {
    int input_num = atoi(argv[1]);

    FILE *file = fopen(argv[3], "r");

    int file_num;

    fscanf(file, "%d", &file_num);
    fclose(file);

    int N = input_num + file_num;

    int result;

    if (argv[2][0] == 'i') {
        result = fib_iterative(N-1);
    } else if (argv[2][0] == 'r') {
        result = fib_recursive(N-1);
    } else {
        printf("Error: Second argument must be 'i' (iterative) or 'r' (recursive)\n");
        return 1;
    }

    printf("%d\n", result);

    return 0;
}
