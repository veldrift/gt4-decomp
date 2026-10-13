typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
};

struct HeapName {
    const char *name;
};

/* rb-tree node: colour, parent, left, right, then the pair (key Str at +0x10, Val at +0x14) */
struct Node {
    s32 color;
    s32 parent;
    s32 left;
    s32 right;
    Str key;
    s32 vtype;
    s32 vval;
};

/* the tree lives at +8 of the map: allocator at +0, header at +4, node count at +8 */
struct Tree {
    s32 alloc;
    Node *header;
    s32 count;
};

extern "C" void func_005EACC8(void *ret, void *t, void *k);
extern "C" s32 func_005C2A50(void *self, void *other, u32 pos, u32 n);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_005EAD48(void *ret, void *t, void *a2, void *a3);
extern "C" HeapName *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void func_002EAA50(char *arg0, Str *arg1, s32 arg2) {
    s32 it[4];      /* sp+0x00: out iterator from func_005EACC8, later the result */
    s32 hdr[4];     /* sp+0x10: header temporary */
    s32 ret20[4];   /* sp+0x20: out value of func_005EAD48 */
    s32 p30[4];     /* sp+0x30: node pointer kept for the call (through pa) */
    s32 k40[4];     /* sp+0x40: Str temporary (char *, int), through pk */
    s32 p50[4];     /* sp+0x50: node pointer argument for func_005EAD48 */
    s32 s60[4];     /* sp+0x60: zero word, stored into k40[1] */
    Tree *tree = (Tree *)(arg0 + 8);
    s32 missing = 0;
    s32 *pa;
    s32 *pk;
    s32 *q50;

    func_005EACC8(it, tree, arg1);
    hdr[0] = (s32)tree->header;
    if ((Node *)it[0] == tree->header ||
        func_005C2A50(arg1, &((Node *)it[0])->key, 0, (u32)-1) < 0) {
        missing = 1;
    }

    if (missing != 0) {
        char *src = arg1->p;
        pa = p30;
        pa[0] = it[0];
        s60[0] = 0;
        pk = k40;
        Rep *r = (Rep *)(src - 0x10);
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
            d = src;
        }
        pk[0] = (s32)d;
        pk[1] = s60[0];
        q50 = p50;
        q50[0] = pa[0];
        func_005EAD48(ret20, tree, q50, pk);
        it[0] = ret20[0];

        Rep *q = (Rep *)(pk[0] - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }

    Node *n = (Node *)it[0];
    n->vtype = arg2;
}
