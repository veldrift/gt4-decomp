/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;

struct Arg { char pad0[4]; char *unk4; };
struct Local { char d[0x20]; };

extern "C" void CarGeometry__structor_0(Local *, Arg *, s32);
extern "C" u16 *func_0038DC18(Local *);
extern "C" s32 CarGeometry__GetNumCrew(Local *) throw();

static inline bool valid(Local *p) { return func_0038DC18(p) != 0; }

extern "C" s32 func_00386C70(s32 arg0, Arg *arg1) {
    Local loc;
    char *p;

    CarGeometry__structor_0(&loc, arg1, 0);
    if (!valid(&loc)) {
        return 0;
    }
    for (;;) {
    p = arg1->unk4;
    s32 v = *func_0038DC18(&loc) & 2;
    if (v) {
        return 0;
    }
    if (p != 0) {
        v = *(s32 *)(p + 0xF8A0);
        v = v < 3;
        if (!v) {
            return 1;
        }
    }
    return CarGeometry__GetNumCrew(&loc);
    }
}
