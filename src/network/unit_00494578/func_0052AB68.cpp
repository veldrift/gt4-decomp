struct Seg {
    void *base;
    int len;
};
struct Gather {
    Seg seg[8];
    int total;
    int count;
};
struct Node;
struct S;
extern "C" Node *func_0052DD98(S *, int);
extern "C" int func_0052D5A8(S *, Node *, Gather *);
extern "C" void *func_005A48D8(void *, int, unsigned);

extern "C" int func_0052AB68(void *a0, S *arg1, Gather *q, unsigned short a3, int t0) {
    char hdr[16];
    Gather g;
    int sp60;
    sp60 = t0;
    func_005A48D8(hdr, 0, 0x10);
    *(unsigned short *)(hdr + 0xC) = a3;
    char *qlp = (char *)q + 4;
    if (q->count < 8) {
        q->seg[q->count].base = hdr;
        q->seg[q->count].len = 0x10;
        q->total = q->total + 0x10;
        q->count = q->count + 1;
    }
    g.count = 0;
    g.total = 0;
    char *glp = (char *)&g.seg[0].len;
    char *gbp = (char *)&g;
    *(int *)glp = 4;
    *(void **)gbp = &sp60;
    g.total = g.total + 4;
    g.count = g.count + 1;
    int i = 0;
    if (q->count > 0) {
        do {
            int c = g.count;
            if (c < 8) {
                g.seg[c].base = q->seg[i].base;
                int len = q->seg[i].len;
                g.seg[c].len = len;
                g.total = g.total + len;
                g.count = g.count + 1;
            }
            i++;
        } while (i < q->count);
    }
    q->count = q->count - 1;
    q->total = q->total - q->seg[q->count].len;
    Node *node = func_0052DD98(arg1, q->total);
    if (!node) return 3;
    return func_0052D5A8(arg1, node, (Gather *)gbp) == 0 ? 0 : 3;
}
