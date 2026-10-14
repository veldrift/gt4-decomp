/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { int a, b, c, d, e; };
extern "C" void func_003FC108(char *s)
{
    unsigned m = 0xFFFF00FF;
    char *x = s + 0xC;
    char *y = s + 0x10;
    E *p = (E *)(s + 0x80);
    int off = 0;
    for (int i = 0; i < 3; i++) {
        int o = off + 0x70;
        p->c = (p->c & m) | 0x100;
        *(int *)(x + o) = 0;
        *(int *)(y + o) = 0;
        off += 0x14;
        p++;
    }
}
