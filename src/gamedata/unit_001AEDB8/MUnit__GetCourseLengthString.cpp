/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VE { short d; short i; f32 (*fn)(void *); };
struct Obj { char pad[4]; void *vt; };

extern Rep D_00659FA8;
extern s32 PDISTD__UNIT_MANAGER[];
extern void *D_00624984;
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" char *func_00472898(s32 *);
extern "C" f32 func_00472C28(s32 *, f32);
extern "C" void func_00490A40(void *, char *, const char *, int, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00693038[];

extern "C" void MUnit__GetCourseLengthString(s32 *arg0, s32 arg1, Obj **arg2) {
    char buf[0x80];
    s32 h[8];
    Str s;
    if (arg1 > 0) {
        Obj *o = *arg2;
        VE *ve = (VE *)((char *)o->vt + 0x60);
        f32 v = func_00472C28(PDISTD__UNIT_MANAGER, ve->fn((char *)o + ve->d));
        func_00490A40(D_00624984, buf, D_00693038, (s32)(v * 100.0f + 0.5f), func_00472898(PDISTD__UNIT_MANAGER));
        Str *ps = &s;
        char *pb = buf;
        {
            Rep *r = &D_00659FA8;
            char *p;
            if (r->sel != 0) {
                p = func_005C2560(r);
            } else {
                p = (char *)(r + 1);
                r->ref++;
            }
            ps->p = p;
        }
        func_005C2630(ps, 0, -1, pb, func_0057F260(pb));
        s32 *ph = h;
        func_00314B20(ph, ps);
        if (arg0 != ph) {
            s32 nv = *ph;
            if (nv != 0) func_003285A8(nv);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = nv;
        }
        func_00312318(ph, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
}
