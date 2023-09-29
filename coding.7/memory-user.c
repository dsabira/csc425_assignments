#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide the memory size in megabytes\n");
        return 1;
    }

    long long requestedMegabytes = atoll(argv[1]);
    if (requestedMegabytes <= 0) {
        fprintf(stderr, "Error: Invalid memory size\n");
        return 1;
    }

    long long requestedBytes = requestedMegabytes * 1024 * 1024;
    char *memoryBlock = (char *)malloc(requestedBytes);

    if (memoryBlock == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }

    printf("Allocated memory size: %lld bytes\n", requestedBytes);

    while (1) {
        for (long long i = 0; i < requestedBytes; i++) {
            memoryBlock[i] += 1;
        }
    }

    free(memoryBlock);
    return 0;
}
