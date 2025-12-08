#pragma once

#include <stdlib.h>

#ifdef F_MEMORY_DEBUG

#define LIST_SIZE 2048

typedef struct mem_alloc_record {
    unsigned int ptr_value;
    unsigned int allocation_line;
    char *allocation_file;
} mem_alloc_record_t;

typedef struct mem_alloc_record_list {
    mem_alloc_record_t m[LIST_SIZE];
} mem_alloc_record_list_t;

#define malloc(size) f_debug_memory_malloc(size, __FILE__, __LINE__)
#define calloc(num, size) f_debug_memory_calloc(num, size, __FILE__, __LINE__)
#define realloc(ptr, size) f_debug_memory_realloc(ptr, size, __FILE__, __LINE__)
#define free(ptr) f_debug_memory_free(ptr, __FILE__, __LINE__)

void *f_debug_memory_malloc(unsigned int size, const char *file, unsigned int line);
void *f_debug_memory_calloc(unsigned int num, unsigned int size, const char *file,
			    unsigned int line);
void *f_debug_memory_realloc(void *ptr, unsigned int size, const char *file, unsigned int line);
void f_debug_memory_free(void *ptr, const char *file, unsigned int line);
void f_debug_memory_leak_check(void);

#endif
