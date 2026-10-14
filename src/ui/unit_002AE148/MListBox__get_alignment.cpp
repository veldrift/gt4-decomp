typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)(((VObj *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}

extern "C" void *func_002AE9C0(void *, void *) throw();
extern "C" void func_002AE968(void *, s32) throw();
extern "C" void func_002F9360(void *, f32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct Ctx { char pad[0xFC]; f32 v; };

extern "C" void MListBox__get_alignment(s32 *arg0, void *arg1, s32 mode, s32 *arg3) {
    s32 buf0[4];
    s32 h[4];
    if (mode == 0) {
        func_002AE9C0(buf0, arg1);
        s32 *p = h;
        func_002F9360(p, ((Ctx *)buf0[0])->v);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_003285A8(nv);
            if (arg0[0] != 0)
                func_003285F8(arg0[0]);
            arg0[0] = nv;
        }
        func_002F7B68(p, 2);
        func_002AE968(buf0, 2);
    } else if (mode == 1) {
        func_002AE9C0(buf0, arg1);
        Ctx *c = (Ctx *)buf0[0];
        f32 x = vcall_60((char *)arg3[0]);
        if (x < 0.0f)
            x = 0.0f;
        if (x > 1.0f)
            x = 1.0f;
        c->v = x;
        func_002AE968(buf0, 2);
    }
}
