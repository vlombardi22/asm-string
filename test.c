#include <stdint.h>
#include <stdio.h>

typedef uint64_t u64;

typedef struct {
    char *buf;
    u64 len;
    u64 cap;
} string;

typedef struct {
    char const *buf;
    u64 len;
} str;

str str_from_c_string(char const *s);
void str_print(str self);

str string_as_str(string const *self);

string string_new(void);
string string_from_str(str);
void string_push_char(string *self, char c);
void string_push_str(string *self, str s);
void string_delete(string self);

int main() {
    str s = str_from_c_string("Hello");
    string st = string_from_str(s);
    string_push_str(&st, str_from_c_string(", world!"));
    string_push_char(&st, '\n');
    str_print(string_as_str(&st));
    string_delete(st);
    return 0;
}
