#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "result.h"

#ifdef F_MEMORY_DEBUG

#define LIST_SIZE 2048

typedef struct MemAllocRecord {
    unsigned int *ptr_value;
    unsigned int allocation_line;
    char *allocation_file;
} MemAllocRecordType;

typedef struct MemAllocRecordList {
    MemAllocRecordType m[LIST_SIZE];
    unsigned int occurrences;
} MemAllocRecordListType;

typedef struct MemFreedRecord {
    unsigned int *ptr_value;
    unsigned int freed_line;
    char *freed_file;
} MemFreedRecordType;

typedef struct MemFreedRecordList {
    MemFreedRecordType m[LIST_SIZE];
    unsigned int occurrences;
} MemFreedRecordListType;

#define malloc(size) f_debug_memory_malloc(size, __FILE__, __LINE__)
#define calloc(num, size) f_debug_memory_calloc(num, size, __FILE__, __LINE__)
#define realloc(ptr, size) f_debug_memory_realloc(ptr, size, __FILE__, __LINE__)
#define free(ptr) f_debug_memory_free(ptr, __FILE__, __LINE__)

void *f_debug_memory_malloc(unsigned int size, const char *file, unsigned int line);
void *f_debug_memory_calloc(unsigned int num, unsigned int size, const char *file,
			    unsigned int line);
void *f_debug_memory_realloc(void *ptr, unsigned int size, const char *file, unsigned int line);
void f_debug_memory_free(void *ptr, const char *file, unsigned int line);

void f_debug_memory_debug_init(void);
void f_debug_memory_leak_check(void);

#endif
