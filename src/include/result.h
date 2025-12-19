#pragma once

#include "bool.h"

typedef struct Result {
	bool is_ok;
	char error_message[100];
} ResultType;
