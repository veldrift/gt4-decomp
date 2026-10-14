typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *self, s32 idx);
};

extern "C" void func_00378F28(void *a, s32 b, void *c, void *d, void *e);

extern "C" void func_00375B80(char *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    char *s = arg0 + arg3 * 0x19C;
    char *p2 = s + 0xE0;
    s = s + 0x10;
    VEntry *e = (VEntry *)(*(char **)arg0 + 0xD8);
    void *r = e->fn(arg0 + e->delta, arg3);
    func_00378F28(r, arg1, p2, s, arg0 + 0x9C0);
}
