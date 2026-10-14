/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
struct Global;
extern Global D_006235A8;
struct Obj { s64 w[0x20]; };
extern "C" s32 func_00443240(Obj *);
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *, s64, void *);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *, s64);
extern "C" void func_004442B8(Obj *) throw();
extern "C" s32 func_00444860(Obj *, s64);
extern "C" s32 func_004449C0(Obj *);
extern "C" s64 func_004457B0(Obj *);
#define S(d, s) o->w[(d) / 8] = F[(s) / 8]
extern "C" s32 func_00444690(Obj *o, s64 id) {
    s64 F[30];
    if (!SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id)) return 0;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &F[0]);
    s64 nx = F[1];
    if (nx == -1 || !SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, F[1])) return 0;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, F[1], &F[4]);
    func_004442B8(o);
    o->w[1] = id;
    S(0x00, 0x00); S(0x20, 0x20); S(0x28, 0x28); S(0x30, 0x48); S(0x38, 0x78); S(0x40, 0x68); S(0x48, 0x70);
    S(0x50, 0x30); S(0x58, 0xD8); S(0x60, 0xE0); S(0x68, 0xE8);
    S(0x70, 0x60); S(0x78, 0x58); S(0x80, 0x50); S(0x88, 0x90); S(0x90, 0x98); S(0x98, 0xA0);
    S(0xA0, 0xA8); S(0xA8, 0x80); S(0xB0, 0x88); S(0xB8, 0xC8); S(0xC0, 0xC0); S(0xC8, 0xD0); S(0xD0, 0xB8);
    S(0xD8, 0xB0); S(0xE0, 0x38); S(0xE8, 0x40);
    o->w[0x1E] = -1;
    func_004449C0(o);
    s64 r = func_004457B0(o);
    o->w[2] = r;
    if (r == -1) return 0;
    ((u8 *)o)[0x18] = 0;
    if (F[2] != -1) func_00444860(o, F[2]);
    return func_00443240(o) != 0;
}
