/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Node;
struct VE { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct Node {
    char pad0[4];
    char *vtbl;
    char pad8[0x54 - 8];
    Node *parent;
    Node *prev;
    Node *next;
};
struct List {
    char pad0[0xA0];
    s32 count;
    Node *first;
    Node *last;
};

extern Rep D_00659FA8;
extern char D_0082AA00[];

extern "C" void func_003285A8(void *);
extern "C" void func_005769F0(s32);
extern "C" void func_00576A28(s32);
extern "C" const char *hModule__getName(void *);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *, u32, u32, const char *, u32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void func_00206888(List *self, Node *node, Node *after) {
    if (node != 0) {
        Str str;
        func_003285A8(node);
        func_005769F0((s32)D_0082AA00);
        Node *v = after ? after->prev : self->last;
        if (v != 0)
            v->next = node;
        else
            self->first = node;
        if (after != 0)
            after->prev = node;
        else
            self->last = node;
        node->next = after;
        node->parent = (Node *)self;
        node->prev = v;
        self->count = self->count + 1;
        func_00576A28((s32)D_0082AA00);
        Str *ps = &str;
        const char *name = hModule__getName(node);
        char *d;
        Rep *r = &D_00659FA8;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        ps->p = d;
        func_005C2630(ps, 0, -1, name, func_0057F260(name));
        VE *e = (VE *)(node->vtbl + 0x190);
        e->fn((char *)node + e->delta, &str);
        Rep *q = (Rep *)(str.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
}
