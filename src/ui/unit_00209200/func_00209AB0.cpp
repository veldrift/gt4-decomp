typedef int s32;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Node { char pad[0x14]; void *f14; };
struct Tree { char pad[4]; Node *f4; };
struct Iter { Node *node; char pad[0xC]; };
struct Elem { s32 v; };
struct Elem16 { Elem v; char pad[0xC]; };
struct Pair { Str key; Elem val; char pad[8]; };

extern "C" void func_0020A4C8(void *, const void *);
extern "C" void func_0020A4E0(void *, int);
extern "C" void func_0020A700(void *);
extern "C" void func_0020A938(void *, const void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005D5878(void *, void *, void *);
extern "C" void func_005D5940(void *);
extern "C" void func_005D5AD0(void *, void *, void *);

extern "C" void func_00209AB0(char *arg0, Str *arg1, s32 *arg2) {
    if (*arg2 == 0) {
        func_005D5940(arg0 + 0x10);
        return;
    }
    Tree *t = (Tree *)(arg0 + 0x10);
    Iter it;
    Iter end;
    Elem16 e16;
    Iter ret;
    Pair pr;
    func_005D5878(&it, t, arg1);
    end.node = t->f4;
    if (it.node == end.node) {
        Elem *pe = &e16.v;
        func_0020A700(pe);
        func_0020A938((void *)pe->v, arg2);
        Pair *pp = &pr;
        char *src = arg1->p;
        Rep *r = (Rep *)src - 1;
        char *p;
        if (r->sel != 0) {
            p = func_005C2560(r);
        } else {
            p = src;
            r->ref++;
        }
        pp->key.p = p;
        func_0020A4C8(&pp->val, pe);
        func_005D5AD0(&ret, t, pp);
        func_0020A4E0(&pr.val, 2);
        {
            Rep *q = (Rep *)(pp->key.p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        func_0020A4E0(pe, 2);
    } else {
        func_0020A938(it.node->f14, arg2);
    }
}
