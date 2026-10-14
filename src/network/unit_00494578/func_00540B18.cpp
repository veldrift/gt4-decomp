typedef int s32;
struct Buf {
    char pad[0x1800];
    s32 n;
};
struct Obj {
    char pad0[8];
    char c8[0x100];
    char c108[0x100];
    s32 u208;
    s32 u20C;
    Buf *u210;
};
extern char D_006C4F40[];
extern "C" char *func_0053F398(void *, s32);
extern "C" void *func_005A6AB0(void *, void *, s32) throw();
extern "C" char *func_005A6DC8(void *, void *) throw();
extern "C" void func_00540B18(char *s, s32 len, Obj *o) {
    Buf *b = o->u210;
    if (o->u20C == 0 && len != 0 && *s != 0x20) {
        char *t = func_0053F398(o->c108, o->u208);
        if (func_005A6DC8(D_006C4F40, o->c8)) {
            func_005A6AB0((char *)b + (b->n << 8), t, 0x100);
            func_005A6AB0((char *)b + (b->n << 8) + 0xC00, s, len);
            *(char *)(len + (b->n << 8) + (s32)b + 0xC00) = 0;
            b->n = b->n + 1;
        }
    }
}
