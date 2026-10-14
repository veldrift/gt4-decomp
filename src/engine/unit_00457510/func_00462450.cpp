/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned int PDISTD__LOCALE;
extern char D_00846958[3];
extern "C" char *func_0048EDA0(unsigned int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" char *func_00462450() {
    char *s = func_0048EDA0(PDISTD__LOCALE);
    if (func_0057F238(s, "DB") == 0) s = (char *)"UK";
    int a = s[0];
    if (((unsigned char *)0x006D0E79)[a] & 1) a += 32;
    D_00846958[0] = a;
    int b = s[1];
    D_00846958[2] = 0;
    if (((unsigned char *)0x006D0E79)[b] & 1) b += 32;
    D_00846958[1] = b;
    return D_00846958;
}
