typedef int s32;

extern "C" void func_001D26A8(void *);
extern "C" void func_00578AF0(s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005C1628(void *);

struct VEntry_vcall_3 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_3(char *o, s32 a1) {
    VEntry_vcall_3 *e = (VEntry_vcall_3 *)(*(char **)(o + 0x4C) + 0x8);
    e->fn(o + e->delta, a1);
}

extern "C" void func_001D2518(void *arg0, s32 arg1) {
    if (*(s32 *)((char *)arg0 + 0x6E0) != 0) {
        func_001D26A8(arg0);
        func_00578AF0(*(s32 *)((char *)arg0 + 0x6E0));
    }
    if ((char *)arg0 != (char *)-0x34) {
        char *p0 = (char *)arg0 + 0x674;
        char *end = (char *)arg0 + 0x34;
        while (end != p0) {
            char *obj;
            p0 -= 4;
            obj = *(char **)p0;
            if (obj != 0) {
                vcall_3(obj, 0x3);
            }
        }
    }
    func_00574DA8(arg0, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
