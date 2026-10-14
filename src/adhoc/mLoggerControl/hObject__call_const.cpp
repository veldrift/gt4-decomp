/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj;
struct Handle { Obj *p; s32 pad[3]; };
struct Store { char pad0[0x14]; Obj **data; char pad18[8]; s32 count; };
struct State { char pad0[0x2C]; Store *store; };
extern char D_0083F5F0[];
extern "C" void func_0030BB18(void *);
extern "C" void hObject__send(void *, void *, const void *, s32, const void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00309378(void *, s32) throw();
extern "C" void hObject__call_const(void *self, State **arg1, s32 arg2, const void *arg3) {
    Handle h;
    func_0030BB18(&h);
    hObject__send(self, &h, D_0083F5F0, arg2, arg3);
    Store *s = (*arg1)->store;
    Obj **dst = s->data + s->count;
    if (dst != (Obj **)&h) {
        Obj *p = h.p;
        if (p) func_003285A8(p);
        if (*dst) func_003285F8(*dst);
        *dst = p;
    }
    s->count++;
    func_00309378(&h, 2);
}
