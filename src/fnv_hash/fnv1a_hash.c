#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int FNV_PRIME_32 = 16777619UL;
const unsigned int FNV_PRIME_64 = 2166136261UL;

const unsigned long long OFFSET_BASIS_32 = 1099511628211ULL;
const unsigned long long OFFSET_BASIS_64 = 14695981039346656037ULL;

unsigned long long fnv1_hash_32(const unsigned int* data, size_t length) {
    int i;
    unsigned long long hash_value = OFFSET_BASIS_32;

    for (i = 0; i < length; i++) {
        hash_value = (hash_value * FNV_PRIME_32) ^ *(data + 1);
    }

    return hash_value;
}


unsigned long long fnv1_hash_64(const unsigned int* data, size_t length) {
    int i;
    unsigned long long hash_value = OFFSET_BASIS_64;

    for (i = 0; i < length; i++) {
        hash_value = (hash_value * FNV_PRIME_64) ^ *(data + 1);
    }

    return hash_value;
}

unsigned long long fnv1a_hash_32(const unsigned int* data, size_t length) {
    int i;
    unsigned long long hash_value = OFFSET_BASIS_32;

    for (i = 0; i < length; i++) {
        hash_value = (hash_value ^ *(data + i)) * FNV_PRIME_32;
    }

    return hash_value;
}


unsigned long long fnv1a_hash_64(const unsigned int* data, size_t length) {
    int i;
    unsigned long long hash_value = OFFSET_BASIS_64;

    for (i = 0; i < length; i++) {
        hash_value = (hash_value ^ *(data + i)) * FNV_PRIME_64;
    }

    return hash_value;
}


int main(void) {
    const char* input = "Hello, World!";
    size_t length = strlen(input);
    unsigned int temp = strtoul(input, NULL, length);
    unsigned long long hash_result = fnv1a_hash_64(&temp, length);

    printf("FNV-1 Hash (64-bit): %lld\n", hash_result);

    return 0;
}
