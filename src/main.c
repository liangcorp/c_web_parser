#include <stdio.h>

#include "html_table_parser.h"

int main(void)
{
	char html_str[] = "<table><tr><td></td></tr></table>";

	html_tag_count_t htc = parse_html_table(html_str);

	if (htc.result != -1) {
		printf("<table> count: %d\n", htc.table_head_occurrence);
		printf("<tr> count: %d\n", htc.tr_head_occurrence);
		printf("<th> count: %d\n", htc.th_head_occurrence);
		printf("<td> count: %d\n", htc.td_head_occurrence);

		printf("<table> count: %d\n", htc.table_tail_occurrence);
		printf("<tr> count: %d\n", htc.tr_tail_occurrence);
		printf("<th> count: %d\n", htc.th_tail_occurrence);
		printf("<td> count: %d\n", htc.td_tail_occurrence);
	} else {
		printf("malformed HTML content\n");
	}

	return 0;
}
