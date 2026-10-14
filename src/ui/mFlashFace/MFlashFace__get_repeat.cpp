/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Bits { unsigned lo : 6; unsigned f6 : 1; };
struct Obj { char pad[0xB4]; union { s32 b4; Bits bits; }; };
struct VT { char pad[4]; char *tbl; };
struct E { s16 delta; s16 index; s32 (*fn)(void *); };
struct Host { char pad[4]; char *vtbl; };

extern "C" void func_00291880(void *, int) throw();
extern "C" s32 func_002918D8(void *, void *) throw();
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MFlashFace__get_repeat(s32 *arg0, void *arg1, s32 arg2, Host **arg3) {
    s32 buf[4];
    s32 tmp[4];
    if (arg2 > 0) {
        func_002918D8(buf, arg1);
        Host *o = *arg3;
        Obj *p = (Obj *)buf[0];
        E *e = (E *)(o->vtbl + 0x58);
        s32 r = e->fn((char *)o + e->delta);
        p->bits.f6 = (r != 0);
        func_00291880(buf, 2);
        return;
    }
    s32 *t = tmp;
    func_002918D8(t, arg1);
    Obj *q = (Obj *)t[0];
    func_002FE278(buf, (q->b4 >> 6) & 1);
    if (arg0 != buf) {
        s32 nv = buf[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_002FC870(buf, 2);
    func_00291880(t, 2);
}
