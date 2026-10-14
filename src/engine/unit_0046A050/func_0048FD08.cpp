/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
struct Node { Node *next; const char *key; int val; };
struct HT { Node *b[15]; Node *freelist; };
struct Item { const char *name; };
struct Group { char pad[0x10]; u16 cnt; char pad2[2]; Item **items; };
struct TB { int a[1]; };
struct Mgr2 { char pad0[8]; int cnt8; int pad0c; int f10; int f14; };
extern HT D_008496D8;
extern "C" void func_00491DB8(Group *);
extern "C" u32 func_00494460(const unsigned char *);
extern "C" int func_0057F238(const char *, const char *) throw();

static inline int lookup(const char *k) {
    Node *n = D_008496D8.b[func_00494460((const unsigned char *)k) % 15];
    if (n) {
        do {
            if (func_0057F238(n->key, k) == 0) return n->val;
            n = n->next;
        } while (n);
    }
    return 0;
}

static inline void erase(const char *const k) {
            HT *h = &D_008496D8;
            Node *prev = 0;
            u32 index = func_00494460((const unsigned char *)k) % 15;
            Node *n = h->b[index];
            if (n) {
                do {
                    if (func_0057F238(n->key, k) == 0) {
                        if (!prev) h->b[index] = n->next; else prev->next = n->next;
                        Node *free = h->freelist;
                        n->key = 0;
                        n->next = free;
                        n->val = 0;
                        h->freelist = n;
                        break;
                    }
                    prev = n;
                    n = n->next;
                } while (n);
            }
}

extern "C" void func_0048FD08(Mgr2 *m, int idx) {
    TB *tb = (TB *)m;
    m->f14 = m->f10;
    Group *g = (Group *)tb->a[idx];
    for (int i = 0; i < g->cnt; i++) {
        Item *it = g->items[i];
        const char *k = it->name;
        if (lookup(k)) {
            erase(it->name);
        }
    }
    func_00491DB8(g);
    tb->a[idx] = 0;
    m->cnt8--;
}
