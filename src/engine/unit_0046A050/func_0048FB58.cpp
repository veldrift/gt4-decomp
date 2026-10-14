typedef unsigned int u32;
typedef unsigned short u16;
struct Node { int next; int key; int val; };
struct HT { Node *b[15]; int freelist; };
struct Item { const char *name; };
struct Group { char pad[0x10]; u16 cnt; char pad2[2]; Item **items; };
extern HT D_008496D8;
extern "C" Group *func_00491D90(int);
extern "C" void func_00491798(Group *);
extern "C" void func_00491DD8(Group *);
extern "C" u32 func_00494460(const unsigned char *);
extern "C" int func_0057F238(const char *, const char *);

static inline int lookup(const char *k) {
    Node *n = D_008496D8.b[func_00494460((const unsigned char *)k) % 15];
    if (n) {
        do {
            if (func_0057F238((const char *)n->key, k) == 0) return n->val;
            n = (Node *)n->next;
        } while (n);
    }
    return 0;
}

extern "C" Group *func_0048FB58(int a, int b) {
    int i = 0;
    Group *g = func_00491D90(b);
    func_00491798(g);
    for (i = 0; i < g->cnt; i++) {
        Item *it = g->items[i];
        const char *k = it->name;
        if (lookup(k) == 0) {
            HT *h = &D_008496D8;
            k = it->name;
            u32 hv = func_00494460((const unsigned char *)k) % 15;
            Node *n = h->b[hv];
            Node *prev = 0;
            if (n) {
                do {
                    if (func_0057F238((const char *)n->key, k) == 0) {
                        n->val = (int)it;
                        goto next;
                    }
                    prev = n;
                    n = (Node *)prev->next;
                } while (n);
            }
            {
                Node *nn = (Node *)h->freelist;
                int nx = nn->next;
                h->freelist = nx;
                nn->key = (int)k;
                nn->val = (int)it;
                nn->next = 0;
                if (!prev) h->b[hv] = nn; else prev->next = (int)nn;
            }
        }
    next:;
    }
    func_00491DD8(g);
    return g;
}
