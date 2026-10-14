struct VE { short delta; short idx; void *(*fn)(void *); };
struct Obj { int x; char *vt; };
extern char D_0069B0C0[];
extern "C" const char *hModule__getName(void *a);
extern "C" void func_005D4AD8(const char *fmt, ...);

extern "C" int mEvent__onEvent(void *self, int a1, Obj *o) {
    if (o != 0) {
        VE *e = (VE *)(o->vt + 0x50);
        const char *s0 = hModule__getName(e->fn((char *)o + e->delta));
        func_005D4AD8(D_0069B0C0, s0, hModule__getName(o));
    }
    return 0;
}
