#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define _Countof(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MAXLINE 128

static const char *const PARTS[] = {
    "hydraulic pump",
    "PLC module",
    "servo motor";
}

static const char *const MSG_WELCOME   = "Hej. Welcome to the spare parts inventory!";
static const char *const MSG_PROMPT    = "Which part do you need? ";
static const char *const MSG_HAVE_FMT  = "I've got %s here for you \n";
static const char *const MSG_BYE_HINT  = "Press Enter to exit...";
static const char *const MSG_NO_STOCK    = "I am afraid we don't have any %s in the inventory \n";
static const char *const MSG_USERQ_1    = {"Do you actually have any parts?", "Is there anything in stock at all?"};

static void trim_newline(char *s){ s[strcspn(s, "\n")] = '\0'; }

static int find_part_index(const char *needle){
    for (size_t i = 0; i < _Countof(PARTS); ++i)
        if (strcmp(needle, PARTS[i]) == 0) return (int)i;
    return -1;
}

static int is_any_parts_query(const char *s){
    return strcmp(s, MSG_USERQ_1) == 0;
}

static void list_inventory(void){
    size_t n = _Countof(PARTS);
    printf("We have %lu %s!\n", (unsigned long)n, (n == 1 ? "part" : "parts"));
    for (size_t i = 0; i < n; ++i) puts(PARTS[i]);
}

int main(void){
    char line[MAXLINE];
    puts(MSG_WELCOME);
    for(;;){
        printf("%s", MSG_PROMPT);
        if(!fgets(line, sizeof line, stdin)) return 0;
        trim_newline(line);

        int idx = find_part_index(line);
        if (idx >= 0){
            printf(MSG_HAVE_FMT, PARTS[idx]);
            puts(MSG_BYE_HINT);
            if(!fgets(line, sizeof line, stdin)){}
            return 0;
        }

        if is_any_parts_query(line) {
            list_inventory();
            continue;
        }

        printf(MSG_NO_STOCK, line);
    }
}
