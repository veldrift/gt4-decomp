/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[0xA0];
    s32 *key;
    s32 a4;
    char pad1[0xB4 - 0xA8];
    u32 b4;
};
struct Node { s32 pad[2]; s32 v8; };

extern "C" void mTextFace__virtual_67(void);
extern "C" s32 func_0025A7E0(s32 *, void *);
extern "C" void func_0026A118(void *, int);
extern "C" void func_0026AAD8(s32 *, s32, void *, s32, s32, s32);
extern "C" void func_00291048(void *, int);
extern "C" s32 func_00293AD0(void *);
extern "C" s32 func_00293B00(void *);
extern "C" s32 func_00293B30(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void mFlashFace__virtual_67(Obj *self) {
    s32 buf[4];
    s32 tmp[4];
    s32 **key = &self->key;
    mTextFace__virtual_67();
    if ((*key)[-4] != 0 && self->a4 == 0) {
        s32 *dst = (s32 *)((char *)self + ((self->b4 >> 1) & 4) + 0xA8);
        s32 s1, s2, s0;
        s32 *t = tmp;
        func_0025A7E0(t, self);
        s1 = t[0];
        s2 = func_00293AD0(self);
        s0 = func_00293B00(self);
        func_0026AAD8(buf, s1, key, s2, s0, func_00293B30(self));
        if (dst != buf) {
            s32 nv = buf[0];
            if (nv != 0)
                func_003285A8(nv);
            if (*dst != 0)
                func_003285F8(*dst);
            *dst = nv;
        }
        func_00291048(buf, 2);
        func_0026A118(t, 2);
        Node *n = (Node *)*(s32 *)((char *)self + ((self->b4 >> 1) & 4) + 0xA8);
        self->a4 = (s32)n;
        if (n != 0)
            n->v8 = 1;
    }
}
