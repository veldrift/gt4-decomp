/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

struct VT {
    char pad0[0x10];
    const char *(*fn)(int, char *, int);
    char pad14[2];
    u16 adj;
};

extern Rep D_00659FA8;
extern "C" void func_0029B9C8(void *, int);
extern "C" void func_0029BA20(void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s32 func_0057F260(const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void MGameInputData__get_name(s32 *arg0) {
    char buf[0x80];
    struct { VT *vt; s32 pad[3]; } obj;
    s32 s90[4];
    s32 sA0[4];
    typeof(obj) *po = &obj;
    func_0029BA20(po);
    s32 *pA0 = sA0;
    VT *vt = po->vt;
    const char *str = vt->fn(vt->adj, buf, 0x80);
    {
        Rep *d = &D_00659FA8;
        char *p;
        if (d->sel != 0) {
            p = func_005C2560(d);
        } else {
            p = (char *)d + 0x10;
            d->ref++;
        }
        pA0[0] = (s32)p;
    }
    func_005C2630(pA0, 0, (u32)-1, str, func_0057F260(str));
    s32 *p90 = s90;
    func_00314B20(p90, pA0);
    if (arg0 != p90) {
        s32 nv = p90[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_00312318(p90, 2);
    {
        Rep *q = (Rep *)(pA0[0] - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_0029B9C8(po, 2);
}
