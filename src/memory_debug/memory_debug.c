#include <stdio.h>

#ifdef F_MEMORY_DEBUG

#include "memory_debug.h"

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
