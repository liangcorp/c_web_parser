#pragma once

typedef enum { false, true } bool;

typedef struct result {
	bool is_ok;
	char error_message[100];
} result_t;
