/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Vec { s32 pad0; s32 *begin; s32 *end; s32 *cap; };
struct VGet { short delta, index; s32 (*fn)(void *); };
struct Obj { char *vt0; char *vt; s32 pad8; Vec *vec; };
extern "C" void func_00309378(void *, s32) throw();
extern "C" int func_0030BB18(void *);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char **HObject__tf(void);
extern "C" s32 *func_005D84B0(s32 *, s32, void *, s32);
extern "C" s32 func_002F3508(s32);

extern "C" void func_0030B678(Obj *self, s32 idx, s32 *val) {
    Vec *v = self->vec;
    if (v == 0) {
        s32 pad[4];
        s32 it[4];
        s32 buf[4];
        VGet *g = (VGet *)(self->vt + 0x50);
        s32 sz = g->fn((char *)self + g->delta);
        Vec *nv = (Vec *)func_00326750(0x100, 4, "std_vector");
        s32 n = func_002F3508(sz);
        nv->begin = 0;
        nv->end = 0;
        s32 bytes = n * 4;
        nv->cap = 0;
        s32 *mem = (s32 *)func_00326750(bytes, 4, *HObject__tf());
        nv->begin = mem;
        nv->end = mem;
        nv->cap = (s32 *)((char *)mem + bytes);
        it[0] = (s32)mem;
        func_0030BB18(buf);
        nv->end = func_005D84B0((s32 *)it[0], n, buf, 0);
        func_00309378(buf, 2);
        self->vec = v = nv;
    }
    s32 *dst = v->begin + idx;
    if (dst != val) {
        s32 nv = *val;
        if (nv != 0)
            func_003285A8(nv);
        if (*dst != 0)
            func_003285F8(*dst);
        *dst = nv;
    }
}
