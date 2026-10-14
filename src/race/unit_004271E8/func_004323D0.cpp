/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned func_0057F260(const char *) throw();
extern "C" int func_005A5AD8(const char *, const char *, ...) throw();
extern char D_006A5730[];

extern "C" char *func_004323D0(char *base, char *str) {
    int k;
    unsigned char c1;
    int x;
    int n;
    unsigned idx;
    if (func_0057F260(str) >= 8) str += 2;
    if (str[0] != 'l') return 0;
    if (str[1] == '0' && str[2] == 'b') k = 0;
    else if (str[1] == '0' && str[2] == 'a') k = 1;
    else if (str[1] == 'i' && str[2] == 'b') k = 2;
    else if (str[1] == 'i' && str[2] == 'a') k = 3;
    else if (str[1] == '0' && str[2] == 's') k = 4;
    else if (str[1] == '0' && str[2] == 'c') k = 5;
    else if (str[1] == '0' && str[2] == 'm') k = 6;
    else return 0;
parse:
    n = 0;
    func_005A5AD8(str + 3, D_006A5730, &n);
    x = n;
    n = x - 1;
    idx = -1;
    if (k < 5) idx = k * 16 + n;
    else if (k == 5) idx = n + 80;
    else if (k == 6) idx = n + 85;
    if (idx >= 0x7D) return 0;
    return base + idx * 0x1F8 + 4;
}
