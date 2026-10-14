/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Ent { s32 a; const char *name; };

extern Rep D_00659FA8;
extern char D_00693330[];
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, s32, void *);
extern "C" s32 func_002EFBF0(void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" Ent *func_00448E10(s32 *);
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" s32 func_0057F260(const char *) throw();
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(void *);
extern "C" void *func_005C2630(void *, u32, u32, const char *, u32);

extern "C" void MDatabase__getAllTunerList(s32 *arg0) {
    s32 obj[4];
    s32 r10[4];
    s32 r20[4];
    s32 r30[4];
    s32 r40[4];
    s32 i = 0;
    Ent *items = func_00448E10(obj);
    s32 *p10 = r10;
    func_002EFBF0(p10);
    if (obj[0] > 0) {
        Ent *e = items;
        s32 *p30 = r30;
        do {
            if (func_0057F238(e->name, D_00693330) != 0) {
                s32 *p40 = r40;
                const char *name = e->name;
                s32 *p20 = r20;
                s32 s3 = p10[0];
                {
                    Rep *d = &D_00659FA8;
                    char *p;
                    if (d->sel != 0) {
                        p = func_005C2560(d);
                    } else {
                        p = (char *)d + 0x10;
                        d->ref++;
                    }
                    p40[0] = (s32)p;
                }
                func_005C2630(p40, 0, (u32)-1, name, func_0057F260(name));
                func_00314B20(p30, p40);
                func_002EEEB0(p20, s3, p30);
                func_00309378(p20, 2);
                func_00312318(p30, 2);
                {
                    Rep *q = (Rep *)(p40[0] - 0x10);
                    if (--q->ref == 0) {
                        s32 cap = q->cap + 0x10;
                        func_00326798(q, cap, 4, func_005C11A8()->name);
                    }
                }
            }
            i++;
            e++;
        } while (i < obj[0]);
    }
    if (arg0 != p10) {
        s32 nv = p10[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_002ED5C0(p10, 2);
}
