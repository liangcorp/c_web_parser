#pragma once

#define HTML_TABLE_HEAD_LENGTH 7
#define HTML_TABLE_TAIL_LENGTH 8

#define HTML_TABLE_ELEMENT_HEAD_LENGTH 4
#define HTML_TABLE_ELEMENT_TALI_LENGTH 5

#define HTML_TABLE_HEAD_STR "<table>"
#define HTML_TABLE_TAIL_STR "</table>"


#define HTML_TR_HEAD_STR "<tr>"
#define HTML_TR_TAIL_STR "</tr>"

#define HTML_TH_HEAD_STR "<th>"
#define HTML_TH_TAIL_STR "</th>"

#define HTML_TD_HEAD_STR "<td>"
#define HTML_TD_TAIL_STR "</td>"

typedef struct html_tag_count {
    unsigned int table_head_occurence;
    unsigned int tr_head_occurence;
    unsigned int th_head_occurence;
    unsigned int td_head_occurence;

    unsigned int table_tail_occurence;
    unsigned int tr_tail_occurence;
    unsigned int th_tail_occurence;
    unsigned int td_tail_occurence;

    int result;
} html_tag_count_t

html_tag_count_t parse_html_table(char* html_str);

