#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = 1024; // 1 KB

    // Allocate memory
    char *str = malloc(size);

    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    memset(str, 'A', size);

    printf("PID: %d\n", getpid());
    printf("Allocated %zu bytes at %p\n", size, (void *)str);

    printf("Press Enter to reallocate...\n");
    getchar();

    // Increase allocation to 20 MB
    size = 20 * 1024 * 1024;

    char *temp = realloc(str, size);

    if (temp == NULL) {
        free(str);
        return 1;
    }

    str = temp;
    memset(str, 'B', size);

    printf("Reallocated %zu bytes at %p\n", size, (void *)str);

    printf("Press Enter to free memory...\n");
    getchar();

    // Free memory
    free(str);
    str = NULL;

    printf("Memory freed\n");

    printf("Press Enter to exit...\n");
    getchar();

    return 0;
}
