#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int isPrime(int n) {
    if (n <= 1)
        return 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    
    return 1;
}


void generateFibonacci(int n) {
    int a = 0, b = 1;
    
    printf("Fibonacci Series: ");
    printf("%d ", a);
    
    for (int i = 1; i < n; i++) {
        printf("%d ", b);
        int temp = a + b;
        a = b;
        b = temp;
    }
    
    printf("\n");
}

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        
        generateFibonacci(10);  
    }
    else {
       
        wait(NULL);
        
        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {  
            if (isPrime(i))
                printf("%d ", i);
        }
        
        printf("\n");
    }
    
    return 0;
}
