typedef int s32;
typedef unsigned int u32;
struct Ent { u32 w; char pad[0x3C]; };
struct Self { Ent *f0; short f4; };
extern char D_006A3AA8[];
extern "C" void *func_0045B4D8(void *a, void *b, s32 c);
extern "C" void GT4Model__BinStreamWriter__write8u(void *stream, s32 value);
extern "C" s32 func_003E9190(Self *self, s32 key);
extern "C" void func_0045AF78(void *a, s32 b);
extern "C" void func_003E93D0(Ent *p, void *q);
extern "C" void func_0045B548(void *a, void *b);
extern "C" void func_003E91E0(Self *self, void *arg1, s32 arg2) {
    char tmp[16];
    func_0045B4D8(tmp, arg1, (s32)D_006A3AA8);
    GT4Model__BinStreamWriter__write8u(arg1, 0);
    s32 v = func_003E9190(self, arg2);
    func_0045AF78(arg1, v);
    short idx = self->f4;
    if (idx >= 0) {
        do {
            Ent *p = (Ent *)((char *)self->f0 + (idx << 6));
            u32 w = p->w;
            s32 f = (w >> 13) & 7;
            s32 nx = (s32)(w << 19) >> 19;
            if (f == arg2) {
                func_003E93D0(p, arg1);
            }
            idx = nx;
        } while (idx >= 0);
    }
    func_0045B548(tmp, arg1);
}
