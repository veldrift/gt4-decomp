typedef int s32;
struct Car { char p0[0x20]; char x[0x3444 - 0x20]; s32 idx; };
struct Lst { s32 count; char p[4]; s32 cars; };
struct Wnd { char p[0x60]; s32 lst; char q[0xC]; s32 spec; };
struct Obj { char p[0x6C]; s32 w; };
struct Self { char p0[0x46C]; s32 f46C; char p1[0x478 - 0x470]; s32 f478; char p2[0x4A0 - 0x47C]; s32 f4A0; };
extern "C" {
char *func_00445450(char *);
s32 func_00445AE8(char *, char *);
s32 func_004472A0(s32);
char *func_005A609C(char *, char *);
}
#define LST(o) ((Lst *)((Wnd *)(o)->w)->lst)
#define CAR(o, off) ((Car *)*(s32 *)((off) + LST(o)->cars))
extern "C" void func_001186F8(char *self, Obj *o) {
    s32 cnt = LST(o)->count;
    s32 i = 0;
    if (cnt > 0) {
        do {
            s32 off = i << 2;
            i++;
            Car *car = CAR(o, off);
            s32 idx = car->idx;
            func_005A609C(self + (idx << 7) + 4, func_00445450(car->x));
            func_00445AE8(CAR(o, off)->x, self + idx * 0x10 + 0x304);
        } while (i < cnt);
    }
    ((Self *)self)->f478 = cnt;
    s32 first = CAR(o, 0)->idx;
    ((Self *)self)->f46C = 0;
    ((Self *)self)->f4A0 = first;
    func_005A609C(self + 0x408, (char *)func_004472A0(((Wnd *)o->w)->spec));
}
