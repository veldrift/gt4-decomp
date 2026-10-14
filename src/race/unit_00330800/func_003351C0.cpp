/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rd { s32 p0; s32 size; s32 p8; s32 pC; };
struct Obj { s32 u0; s32 u4; s32 u8; };

extern char D_0069F138[];
extern "C" bool func_0045B1E0(void *);
extern "C" void func_0045B620(void *, void *);
extern "C" void func_0045B768(void *, void *, char *);

extern "C" bool func_003351C0(Obj *arg0) {
    Rd r;
    s32 d = arg0->u8 - arg0->u0;
    func_0045B768(&r, arg0, D_0069F138);
    if (r.size < 0) {
        arg0->u8 = arg0->u0 + d;
        return true;
    }
    func_0045B620(&r, arg0);
    bool res = !func_0045B1E0(arg0);
    arg0->u8 = arg0->u0 + d;
    return res;
}
