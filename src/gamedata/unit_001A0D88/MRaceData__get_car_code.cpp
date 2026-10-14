/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct VEnt1 { s16 delta; s16 idx; s32 (*fn)(void *); };
struct VT58 { char pad[0x58]; VEnt1 e; };
struct Obj58 { char pad[4]; VT58 *vt; };

extern Rep D_00659FA8;
extern "C" void func_001A0AF8(void *, s32) throw();
extern "C" s32 func_001A0B50(void *, s32) throw();
extern "C" void func_00312318(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(s32, s32);
extern "C" s32 func_00447CA0(s32, char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(void *, s32, s32, const char *, s32);

static inline void setp(char **d, char *p) { *d = p; }
static inline void str_release(char **pp) {
    Rep *q = (Rep *)(*pp - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MRaceData__get_car_code(s32 *arg0, s32 arg1, s32 arg2, Obj58 **arg3) {
    s32 o[4];
    char buf[0x90];
    char *s[4];
    s32 s1 = 0;
    if (arg2 > 0) {
        Obj58 *a1 = *arg3;
        VEnt1 *e1 = &a1->vt->e;
        s1 = e1->fn((char *)a1 + e1->delta);
    }
    func_001A0B50(o, arg1);
    s32 t = o[0];
    t += 0x10;
    func_001A0AF8(o, 2);
    if (func_00447CA0(SPEC_DATABASE__RaceSpec__getEnemyCode(t, s1), buf) != 0) {
        char **ps = s;
        char *q;
        if (D_00659FA8.sel != 0) {
            q = func_005C2560(&D_00659FA8);
        } else {
            q = (char *)&D_00659FA8 + 0x10;
            D_00659FA8.ref = D_00659FA8.ref + 1;
        }
        setp(ps, q);
        func_005C2630(ps, 0, -1, buf, func_0057F260(buf));
        func_00314B20(o, s);
        if (arg0 != o) {
            s32 v = o[0];
            if (v != 0) func_003285A8(v);
            s32 old = *arg0;
            if (old != 0) func_003285F8(old);
            *arg0 = v;
        }
        func_00312318(o, 2);
        str_release(s);
    }
}
