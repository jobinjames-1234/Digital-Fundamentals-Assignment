#include <stdio.h>

#define CACHE_SIZE 8      
#define MEMORY_SIZE 32    
struct CacheLine {
    int valid;
    int tag;
    int data;
};
int main() {
    struct CacheLine cache[CACHE_SIZE];
    int memory[MEMORY_SIZE];
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = 0;
        cache[i].tag = -1;
        cache[i].data = -1;
    }

    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = i * 10;  
    }
    int address;
    printf("Enter memory block number (0 to %d): ", MEMORY_SIZE - 1);
    scanf("%d", &address);
    if (address < 0 || address >= MEMORY_SIZE) {
        printf("Invalid address!\n");
        return 0;
    }
    int cache_index = address % CACHE_SIZE;
    int tag = address / CACHE_SIZE;
    printf("\nMemory Block: %d\n", address);
    printf("Cache Line Index (address %% cache_size): %d\n", cache_index);
    printf("Tag (address / cache_size): %d\n\n", tag);
    if (cache[cache_index].valid && cache[cache_index].tag == tag) {
        printf("CACHE HIT!\n");
        printf("Data in cache: %d\n", cache[cache_index].data);
    } else {
        printf("CACHE MISS!\n");
        printf("Loading block %d into cache line %d...\n", address, cache_index);
        cache[cache_index].valid = 1;
        cache[cache_index].tag = tag;
        cache[cache_index].data = memory[address];
        printf("New data in cache: %d\n", cache[cache_index].data);
    }
    return 0;
}
