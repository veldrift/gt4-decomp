/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Entry { short delta; short index; void (*fn)(void *, void *, s32 *); };
struct Obj { char pad[0x64]; Entry *vt; };
struct Handle { Obj *p; char pad[0x14]; s32 value; };
extern "C" void func_001CF1E8(s32, s32 *) throw();
extern "C" s32 func_001CF7D0(void *) throw();
extern "C" s32 func_001D0678(s32, char *);
static inline void vcall(Obj *p, void *buf, s32 *arg) {
    Entry *e = p->vt + 0x35;
    e->fn((char *)p + e->delta, buf, arg);
}
extern "C" void func_001D05B8(s32 arg0, s32 *arg1, s32 *arg2, Handle *arg3) {
    s32 buf[0x3C];
    vcall(arg3->p, buf, arg2);
    s32 v = arg3->value;
    buf[0x37] = v;
    func_001CF1E8(arg0, buf);
    *arg1 = 2;
    *arg2 = (s32)((u32)(func_001D0678(arg0, (char *)arg3) + 0x3FF) >> 10);
    s32 q = func_001CF7D0((void *)arg0);
    s32 w = q + 0x3FF;
    q = q + 0x7FE;
    if (w < 0) w = q;
    *arg2 += w >> 10;
}
