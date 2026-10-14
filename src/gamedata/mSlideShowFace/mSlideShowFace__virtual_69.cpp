/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct Face { char pad[0xA8]; s32 fA8; s32 fAC; };

extern Rep D_00659FA8;
extern "C" void func_001AAFD0(void *, s32);
extern "C" void func_002319A0(s32, void *);
extern "C" void func_00239F08(void *, int);
extern "C" void func_0023A538(void *, s32, void *, void *, void *);
extern "C" void mColorChipFace__virtual_69(void *, s32, s32);
extern "C" void func_002ED5C0(void *, int);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00692DE0[];

extern "C" void mSlideShowFace__virtual_69(Face *self, s32 arg1) {
    mColorChipFace__virtual_69(self, arg1, 0);
    if (self->fAC == 2) func_001AAFD0(self, arg1);
    if (self->fA8 != 0) {
        char obj[0x30];
        Str s;
        char h[16];
        const char *name;
        Str *ps;
        self->fA8 = 0;
        self->fAC = 3;
        name = D_00692DE0;
        ps = &s;
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
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
        char *ph = h;
        func_002EFBF0(ph);
        func_0023A538(obj, arg1, self, ps, ph);
        func_002319A0(arg1, obj);
        func_00239F08(obj, 2);
        func_002ED5C0(ph, 2);
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
}
