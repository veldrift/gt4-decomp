/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct Ref { char *p; int pad[3]; };
struct S00659988 { const char *name; };

struct Node { char pad0[0x10]; char key[4]; char pad14[0]; };
struct Iter { Node *n; int pad[3]; };

extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005EB048(Iter *, void *, Str *);
extern "C" void func_005EB0C8(Iter *, void *, Iter *, void *);
extern "C" s32 func_005C2A50(Str *, void *, s32, s32);
extern "C" void func_00306E80(void *);
extern "C" char *func_005C2560(Rep *, char *);
extern "C" void func_003041A0(void *, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" s32 func_00305620(void *);
extern "C" void func_00305678(void *, s32);

struct Obj { char pad0[0x28]; char map[0x1C]; s32 f44_pad; };

extern "C" void func_002EAD08(char *a0, Str *a1, Ref *a2) {
    Iter it, end, s20, s30;
    Str s40;
    char s50[0x10];
    Iter s60;
    char *s7 = a0 + 0x44;
    char *map = a0 + 0x28;
    s32 flag = 0;
    func_00576788(s7);
    func_005EB048(&it, map, a1);
    end.n = *(Node **)(map + 4);
    if (it.n == end.n || func_005C2A50(a1, (char *)it.n + 0x10, 0, -1) < 0)
        flag = 1;
    if (flag) {
        char *p50 = s50;
        Iter *p30 = &s30;
        Str *p40 = &s40;
        p30->n = it.n;
        func_00306E80(p50);
        Rep *r = (Rep *)(a1->p - 0x10);
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r, a1->p);
        } else {
            d = a1->p;
            r->ref++;
        }
        p40->p = d;
        func_003041A0((char *)p40 + 4, p50);
        Iter *p60 = &s60;
        p60->n = p30->n;
        func_005EB0C8(&s20, map, p60, p40);
        it.n = s20.n;
        func_003041B8((char *)&s40 + 4, 2);
        {
            Rep *q = (Rep *)(p40->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        func_003041B8(p50, 2);
    }
    Ref *dst = (Ref *)((char *)it.n + 0x14);
    if (dst != a2) {
        char *q = a2->p;
        if (q) func_003285A8(q);
        if (dst->p) func_003285F8(dst->p);
        dst->p = q;
    }
    if (func_00305620(a2->p) == 0)
        func_00305678(a2->p, *(s32 *)(a0 + 0x38));
    func_005767C0(s7);
}
