/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
struct C { char pad[0x236]; u8 f236; };
struct B { char pad[0x463 - 0]; s8 f463; };
struct O { char pad[0x10]; C *f10; };
extern "C" int func_0036C850(O *o) {
    char *b = (char *)o + 0x104;
    C *c = o->f10;
    int v = *(u8 *)(b + 0x526);
    int a = *(u8 *)(b + 0x520);
    if (v != 0) {
        int nv = v + 0xFF;
        *(u8 *)(b + 0x526) = nv;
        u8 low = nv;
        if (low == 0 && *(s8 *)(b + 0x463) != 0) {
            *(u8 *)(b + 0x526) = 1;
        }
    } else {
        if (*(s8 *)(b + 0x463) > 0 && a < c->f236) {
            *(u8 *)(b + 0x526) = 1;
            return a + 1;
        }
        if ((s8)*(u8 *)(b + 0x463) < 0 && a > 0) {
            *(u8 *)(b + 0x526) = 1;
            return a - 1;
        }
    }
    return -1;
}
