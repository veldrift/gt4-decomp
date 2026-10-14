/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inner { char pad[0x494]; float f; char pad2[0x526-0x498]; unsigned char type; };
extern "C" void func_003F3368(char *o) {
    Inner *p = (Inner *)(o + 0x104);
    signed char *out = (signed char *)(o + 0x6c4);
    struct { signed char value; } flag;
    flag.value = 0;
    if (p->f > 0x1.ccccccp-1f && p->type == 11) flag.value = 1;
    *out = flag.value;
}
