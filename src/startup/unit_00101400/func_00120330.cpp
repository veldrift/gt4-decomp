/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
typedef long s64;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
struct G { char pad[0x1D0]; s32 flag; };
extern void *D_00618710;
extern "C" G *func_00123500(void *a);
extern "C" char *func_00123540(void *a);
struct Car { char p[0x10]; };
extern "C" void ShowRoomCar__structor_0(Car *);
extern "C" void ShowRoomCar__structor_1(Car *, s32);
extern "C" void func_00364868(Car *, const char *, s32);
extern "C" float func_00364E78(Car *, s32 *);
extern "C" s64 func_004454C0(const char *);
extern "C" s32 func_00448820(s64, char *);
extern "C" s32 func_004489A0(char *, s32);
extern "C" const char *func_004726B8(void *);
extern "C" float func_004729A0(void *, float);
extern "C" void func_0057DA20(char *, const char *, ...);
extern char PDISTD__UNIT_MANAGER[];
struct S5 { s32 a; char b; };
extern S5 D_0068DD40;
extern char D_0068DD48[];

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}
static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}
static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}
static inline void construct(String *str) {
    str->dat = grab(&D_00659FA8);
}

extern "C" String *func_00120330(String *ret, void *a1, void *a2) {
    Car car;
    char buf[32];
    s32 tmp[4];
    if (D_00618710 && func_00123500(a2)->flag == 0) {
        s32 flag = 0;
        ShowRoomCar__structor_0(&car);
        char *name = func_00123540(a2);
        func_00364868(&car, name, 0);
        if (func_00448820(func_004454C0(name), buf) != 0) {
            flag = func_004489A0(buf, 3) != 0;
        }
        float f = func_00364E78(&car, tmp);
        if (f == 0.0f) flag = 1;
        if (flag) {
            ((S5 *)buf)->a = D_0068DD40.a;
            ((S5 *)buf)->b = D_0068DD40.b;
        } else {
            s32 v = (s32)(func_004729A0(PDISTD__UNIT_MANAGER, f) + 0.5f);
            func_0057DA20(buf, D_0068DD48, v, func_004726B8(PDISTD__UNIT_MANAGER));
        }
        construct(ret, buf);
        ShowRoomCar__structor_1(&car, 2);
    } else {
        construct(ret);
    }
    return ret;
}
