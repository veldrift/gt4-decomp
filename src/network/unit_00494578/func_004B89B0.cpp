/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char pad[0x30]; unsigned short data[256]; int count; char rest[0x41c-0x234]; };
struct Obj { Block blocks[2]; char pad[0x858-0x838]; int current; };
extern "C" unsigned short *func_004B4858(unsigned short *, int, int);
extern "C" char *func_004B9768(char *, unsigned short, int);
extern "C" void func_004B9820(char *, const unsigned short *);
extern "C" void func_004B89B0(Obj *o, int index, char *dst, int limit) {
    Block *b = o->blocks + o->current;
    int count = b->count;
    if (index < 0 || index >= count) return;
    unsigned short *src = func_004B4858(b->data, 256, index);
    if (!src) return;
    int half = limit / 2;
    int len = 0;
    if (*src) {
        unsigned short *scan = src;
        do { ++scan; ++len; } while (*scan);
    }
    if (half >= len) return func_004B9820(dst, src);
    char *out = dst;
    unsigned short *p = src;
    int n = 0;
    while (*p && n < limit / 2 - 1) {
        unsigned short c = *p++;
        ++n;
        out = func_004B9768(out, c, 1);
    }
    out[0] = '.';
    out[1] = '.';
    out[2] = '.';
    out[3] = 0;
}
