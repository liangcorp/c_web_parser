#include <stdio.h>

#include "html_table_parser.h"

int main(void)
{
	char html_str[] = "<table><tr><td></td><td></td></tr></table>";

	html_tag_count_t htc = { 0, 0, 0, 0, 0, 0, 0, 0 };
	result_t result = get_html_table_tag_count(&htc, html_str);

	if (result.is_ok) {
		printf("<table> count: %d\n", htc.table_head_occurrence);
		printf("<tr> count: %d\n", htc.tr_head_occurrence);
		printf("<th> count: %d\n", htc.th_head_occurrence);
		printf("<td> count: %d\n", htc.td_head_occurrence);

		printf("<table> count: %d\n", htc.table_tail_occurrence);
		printf("<tr> count: %d\n", htc.tr_tail_occurrence);
		printf("<th> count: %d\n", htc.th_tail_occurrence);
		printf("<td> count: %d\n", htc.td_tail_occurrence);
	} else {
		printf("%s", result.error_message);
	}

	return 0;
}
