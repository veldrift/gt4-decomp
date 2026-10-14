/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *func_002459A8(char *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_00245A28(char **s, int *newline) {
    char *start = func_002459A8(*s);
    *s = start;
    int len = func_0057F260(start);
    int i;
    for (i = 0; i < len; i++) {
        if ((*s)[i] == ' ') {
            *newline = 0;
            (*s)[i] = 0;
            *s += i + 1;
            break;
        }
        if ((*s)[i] == '\n') {
            *newline = 1;
            (*s)[i] = 0;
            *s += i + 1;
            break;
        }
    }
    if (!(i < len)) *s += len;
    return start;
}
