/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Obj {
    char *items;
    s32 count;
};
extern char D_006A39D8[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, s32);
extern "C" void func_0045AF58(void *, s32);
extern "C" void func_0045AF78(void *, s32);
extern "C" void func_0045B548(void *, void *);
extern "C" s32 func_003E4F60(Obj *, void *) throw();
extern "C" s32 func_003E31E0(void *) throw();
extern "C" void func_003E55F8(void *, void *);

extern "C" void func_003E5408(Obj *self, void *w) {
    s32 buf[4];
    s32 i = 0;
    func_0045B4D8(buf, w, D_006A39D8);
    GT4Model__BinStreamWriter__write8u(w, 0);
    func_0045AF78(w, self->count);
    if (self->count > 0) {
        s32 off = 0;
        do {
            char *it = self->items + off;
            off += 0x60;
            s32 ok = func_003E4F60(self, it);
            func_0045AF58(w, ok);
            if (ok) {
                s32 f = func_003E31E0(it) ^ 1;
                func_0045AF58(w, f);
                if (f) func_003E55F8(it, w);
            }
            i++;
        } while (i < self->count);
    }
    func_0045B548(buf, w);
}
