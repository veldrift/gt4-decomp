typedef int s32;
struct In { s32 f0; };
struct Obj { char p[0x44]; In *f44; };
struct Vt { char p[0x18]; void (*f18)(s32); };
extern Vt *D_0064B4B0;
extern "C" s32 func_00538C68(void *);
extern "C" s32 func_0053E0B8(Obj *o) {
    Obj *local = 0;
    if (o == 0) return 2;
    local = o;
    if (o->f44 != 0) {
        D_0064B4B0->f18(o->f44->f0);
        func_00538C68(&local->f44);
    }
    func_00538C68(&local);
    return 0;
}
