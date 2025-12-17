#include <stdio.h>

#ifdef F_MEMORY_DEBUG

#include "memory_debug.h"

MemAllocRecordType mem_alloc_record;
MemAllocRecordListType mem_alloc_record_list;
MemFreedRecordType mem_freed_record;
MemFreedRecordListType mem_freed_record_list;

#else

#include <stdlib.h>

#endif

void *f_debug_memory_malloc(unsigned int size, const char *file, unsigned int line)
{
#undef malloc
	void *ptr = NULL;

	ptr = malloc(size);

	if (ptr == NULL) {
		printf("MEM ERROR: malloc returns NULL when trying to allocate %u bytes at line %u in file %s\n",
		       size, line, file);
		exit(1);
	}

	printf("%p malloc %u bytes of memory at line %u in file %s\n", ptr, size, line, file);
	return ptr;
}

void *f_debug_memory_calloc(unsigned int num, unsigned int size, const char *file,
			    unsigned int line)
{
#undef calloc
	void *ptr = calloc(num, size);
	if (ptr == NULL) {
		printf("MEM ERROR: calloc returns NULL when trying to allocate %u bytes at line %u in file %s\n",
		       size, line, file);
		exit(1);
	}
	printf("%p calloc %u * %u bytes of memory at line %u in file %s\n", ptr, num, size, line,
	       file);
	return ptr;
}

void *f_debug_memory_realloc(void *ptr, unsigned int size, const char *file, unsigned int line)
{
#undef realloc
	void *new_ptr = realloc(ptr, size);
	if (new_ptr == NULL) {
		printf("MEM ERROR: realloc returns NULL when trying to allocate %u bytes at line %u in file %s\n",
		       size, line, file);
		exit(1);
	}
	printf("%p realloc %u bytes of memory at line %u in file %s\n", new_ptr, size, line, file);
	return new_ptr;
}

void f_debug_memory_free(void *ptr, const char *file, unsigned int line)
{
#undef free
	printf("%p freed at line %u in file %s\n", ptr, line, file);
	free(ptr);
}

void f_debug_memory_debug_init(void)
{
    int i;

    mem_alloc_record.ptr_value = NULL;
    mem_alloc_record.allocation_line = 0;
    mem_alloc_record.allocation_file = NULL;

    for (i = 0; i < LIST_SIZE; i++) {
        mem_alloc_record_list.m[i] = mem_alloc_record;
    }
    mem_alloc_record_list.occurrences = 0;

    mem_freed_record.ptr_value = NULL;
    mem_freed_record.freed_line = 0;
    mem_freed_record.freed_file = NULL;

    for (i = 0; i < LIST_SIZE; i++) {
        mem_freed_record_list.m[i] = mem_freed_record;
    }
    mem_freed_record_list.occurrences = 0;
}

void f_debug_memory_leak_check(void)
{

}
