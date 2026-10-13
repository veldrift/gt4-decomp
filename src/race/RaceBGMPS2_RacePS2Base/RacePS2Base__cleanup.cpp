typedef int s32;
typedef short s16;

struct VEntry_340 {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

extern "C" void func_0044E520(void);
extern "C" void func_003CF550(void *);
extern "C" void func_00389F40(void *);
extern "C" void func_00397CD0(void *);

extern "C" void func_0033C210(char *arg0) {
    char *tmp;
    VEntry_340 *e;

    func_0044E520();
    func_003CF550(arg0 + 0x3628);
    func_00389F40(arg0);
    tmp = *(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4);
    if (tmp != 0) {
        func_00397CD0(*(char **)(tmp + 0x80));
    }
    e = (VEntry_340 *)(*(char **)(arg0 + 0x64) + 0x340);
    e->fn(arg0 + e->delta);
}
