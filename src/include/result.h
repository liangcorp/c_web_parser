#pragma once

#include <stdbool.h>

typedef struct result {
	bool is_ok;
	char error_message[100];
} ResultType;
