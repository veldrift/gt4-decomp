/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern "C" void func_001A0AF8(void *, s32) throw();
extern "C" s32 func_001A0B50(void *) throw();
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_002EEEB0(void *, s32, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_00447CA0(s64, char *);
extern "C" s32 func_00448CD0(s32, s64 *);
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

extern "C" void MRaceData__getAllowedCarList(s32 *arg0) {
    s32 o[4];
    s64 arr[60];
    s32 h[4];
    char buf[0x80];
    func_001A0B50(o);
    if (func_00448CD0(o[0] + 0x10, arr) != 0) {
        s32 *ph = h;
        s64 *p = arr;
        func_002EFBF0(ph);
        for (s32 i = 0; i < 60; i++) {
            s64 v = *p++;
            if (v != -1 && func_00447CA0(v, buf) != 0) {
                s32 x280[4];
                s32 x290[4];
                char *s[4];
                char **ps = s;
                s32 *px = x280;
                s32 s2 = *ph;
                char *q;
                if (D_00659FA8.sel != 0) {
                    q = func_005C2560(&D_00659FA8);
                } else {
                    q = (char *)&D_00659FA8 + 0x10;
                    D_00659FA8.ref = D_00659FA8.ref + 1;
                }
                setp(ps, q);
                func_005C2630(ps, 0, -1, buf, func_0057F260(buf));
                func_00314B20(x290, s);
                func_002EEEB0(px, s2, x290);
                func_00309378(px, 2);
                func_00312318(x290, 2);
                str_release(s);
            }
        }
        if (arg0 != ph) {
            s32 t = *ph;
            if (t != 0) func_003285A8(t);
            s32 old = *arg0;
            if (old != 0) func_003285F8(old);
            *arg0 = t;
        }
        func_002ED5C0(ph, 2);
    }
    func_001A0AF8(o, 2);
}
