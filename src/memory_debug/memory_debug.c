#include <stdio.h>
#include <malloc.h>

#include "memory_debug.h"

void *f_debug_memory_malloc(unsigned int size, const char *file_name, unsigned int line_num) {
    printf("malloc %d bytes of memory in file %s at line %d\n", size, file_name, line_num);
    return malloc(size);
}

void *f_debug_memory_calloc(unsigned int num, unsigned int size, const char *file_name, unsigned int line_num) {

    printf("calloc %d * %d bytes of memory in file %s at line %d\n", num, size, file_name, line_num);
    return calloc(num, size);
}

void f_debug_memory_free(void *ptr, const char *file_name, unsigned int line_num) {
    printf("%p freed in file %s at line %d\n", ptr, file_name, line_num);
    free(ptr);
}
