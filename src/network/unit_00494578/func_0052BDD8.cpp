struct A {
    char p[0x68];
    unsigned short id;
    char p2[2];
    unsigned short count;
};
struct B {
    char p0[0x14];
    char pad14[0x58];
    unsigned short id;
    char p6e[6];
    unsigned short count;
    char p76[0xE];
    int h84;
};
struct Seg {
    void *base;
    int len;
};
struct Gather {
    Seg seg[8];
    int total;
    int count;
};
struct Pkt {
    int w0;
    char b4;
    char b5;
    unsigned short s6;
    unsigned short s8;
    char rest[0x40];
};
struct Ops {
    char pad[0x30];
    void (*fn)(int, int, void *);
};
struct Node {
    int w0;
    char pad[0x10];
    unsigned short flags;
};
extern Ops *D_0064B710;
extern "C" Node *func_0052DD60(void *);
extern "C" void func_0052D550(void *);
extern "C" int func_005288E8(void) throw();
extern "C" void func_0052AA88(A *, B *, unsigned short, int, unsigned char *) throw();
extern "C" int func_0052AB68(A *, void *, Gather *, int, int) throw();

extern "C" int func_0052BDD8(A *arg0, B *arg1) {
    unsigned char out[4];
    Gather g;
    Pkt pkt;
    struct {
        unsigned short flags;
        unsigned short len;
    } t;
    int s1;
    unsigned short a2;
    Node *n;
    int r;
    void *s3 = (char *)arg1 + 0x14;

    goto check;
pending:
    if (!(n->flags & 0x800)) return 0;
    goto discard;
check:
    n = func_0052DD60(s3);
    if (n && n->w0) goto pending;
ready:
    pkt.b4 = 2;
    pkt.w0 = 0x02080016;
    pkt.s6 = arg1->id;
    pkt.s8 = arg0->id;
    pkt.b5 = 0;
    if (func_005288E8() != 1) goto simple;
    s1 = 0x4C;
    D_0064B710->fn(-1, arg1->h84, pkt.rest);
    a2 = 0xC000;
    goto send;
discard:
    func_0052D550(s3);
    arg1->count = arg1->count + 0xFFFF;
    goto ready;
simple:
    s1 = 0xC;
    a2 = 0x4000;
send:
    func_0052AA88(arg0, arg1, a2, s1, out);
    ((unsigned char *)&t.flags)[0] = out[0];
    ((unsigned char *)&t.flags)[1] = out[1];
    t.flags &= 0xF800;
    if (t.flags & 0x6000) t.len = 4;
    else t.len = 2;
    g.count = 0;
    g.total = 0;
    {
        char *lp = (char *)&g.seg[0].len;
        char *bp = (char *)&g.seg[0].base;
        *(int *)lp = s1;
        *(void **)bp = &pkt;
        int c = g.count + 1;
        g.total = g.total + s1;
        g.count = c;
        if (c < 8) {
            int *length = (int *)(lp + c * 8);
            void **base = (void **)(bp + c * 8);
            *length = t.len;
            *base = out;
            g.total = g.total + t.len;
            g.count = g.count + 1;
        }
    }
    r = func_0052AB68(arg0, s3, &g, 0x8800, 0);
    if (r != 0) arg1->count = arg1->count + 0xFFFF;
    return r;
}
