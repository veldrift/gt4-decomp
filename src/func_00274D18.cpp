typedef int s32;
typedef unsigned char u8;

struct Stream {
    u8 *p;
};

extern "C" void func_004EE3D8(s32 arg0, s32 arg1, const char *arg2);
extern "C" char D_0069A578[];

static inline const char *term(Stream *s) {
    s32 n = *(s32 *)(s->p - 0x10);
    if (n == 0) return D_0069A578;
    s->p[n] = 0;
    return (const char *)s->p;
}

struct Obj {
    char pad[0x268];
    s32 handle;
};

extern "C" void mNetConfPS2__virtual_82(Obj *self, s32 a, Stream *s, s32 c) {
    func_004EE3D8(self->handle, a, term(s));
}
