/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long long s64;
struct A8 { s32 p0; };
struct B60 { char pad[8]; s32 p8; };
struct Q { char pad[0x60]; s32 p60; char pad2[0x70 - 0x64]; s32 p70; };
struct W { char pad[0x6C]; s32 q; };
struct Car { char b[0x10]; };
struct B32 { char x[0x20]; };
struct In { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24; char *f28; };
struct Z { char pad[0x18]; s32 p18; };
extern char *D_00622F4C;
extern char D_0068D6C8[];
extern char D_0068D6D0[];
extern "C" void func_0010F718(In *, B32 *);
extern "C" s32 func_0035E3F0(s32);
extern "C" void ShowRoomCar__structor_0(Car *);
extern "C" void ShowRoomCar__structor_1(Car *, s32);
extern "C" void func_00364868(Car *, char *, s32);
extern "C" s32 func_00364E90(Car *, s32 *, s32, s32);
extern "C" s32 func_00364FA8(Car *, s32);
extern "C" s32 func_00433260(void *, s32, s32, B32 *);
extern "C" void *func_00433C78(char *, s32);
extern "C" s32 func_00445350(char *);
extern "C" s64 func_004454C0(char *);
extern "C" s32 func_00445B88(char *);
extern "C" s32 func_004462E0(char *);
extern "C" s32 func_00446320(char *);
extern "C" char *SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" char *func_004472A0(void *);
extern "C" s32 func_004482C0(s64);
extern "C" s32 func_00448398(char *);
extern "C" s32 func_0044AC20(void);
extern "C" int func_0057F238(const char *, const char *) throw();

extern "C" void func_00116268(s32 arg0, W *arg1) {
    Car car;
    B32 out;
    In in;
    s32 tmp;
    Q *q = (Q *)arg1->q;
    char *c = (char *)((A8 *)((B60 *)q->p60)->p8)->p0 + 0x20;
    s32 id = func_00445350(c);
    char *race = SPEC_DATABASE__RaceSpec__getRaceLabel((void *)q->p70);
    char *label = func_004472A0((void *)q->p70);
    s32 k = func_0035E3F0(((Z *)((A8 *)((B60 *)q->p60)->p8)->p0)->p18);
    ShowRoomCar__structor_0(&car);
    func_00364868(&car, c, 0);
    in.f0 = func_0044AC20();
    in.f4 = func_004482C0(func_004454C0(c));
    in.f8 = func_00448398(label);
    in.fC = func_00445B88(c);
    in.f10 = func_00364E90(&car, &tmp, 0x7073, 0);
    in.f14 = func_00364FA8(&car, 0x6B67);
    in.f18 = 3;
    in.f1C = k;
    in.f20 = func_004462E0(c);
    in.f24 = func_00446320(c);
    in.f28 = D_0068D6C8;
    func_0010F718(&in, &out);
    if (func_0057F238(race, D_0068D6D0) != 0)
        func_00433260(func_00433C78(D_00622F4C + 0x26640, 0), k, id, &out);
    else
        func_00433260(func_00433C78(D_00622F4C + 0x26640, 3), k, id, &out);
    ShowRoomCar__structor_1(&car, 2);
}
