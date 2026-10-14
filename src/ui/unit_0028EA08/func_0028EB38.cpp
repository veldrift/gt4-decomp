/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Key { char p[0x10]; unsigned lo; int hi; };
struct Node { Node *next; Node *prev; Key *key; };
struct List { int pad; Node *head; };
struct It { Node *n; int pad[3]; };
struct Str { const char *name; };

extern "C" void func_0028E360(void *a, void *b) throw();
extern "C" void *func_00326750(unsigned int size, int align, const char *name);
extern "C" Str *func_005DD7F0(void);

static inline bool ne(const It &a, const It &b) { return a.n != b.n; }
static inline void setn(It &a, Node *n) { a.n = n; }
static inline void inc(It &a) { a.n = a.n->next; }
static inline Key *&get(const It &a) { return a.n->key; }
static inline bool less(Key *a, const It &it) {
    bool result;
    Key *b = get(it);
    if (a->hi < b->hi) result = true;
    else if (b->hi < a->hi) result = false;
    else result = a->lo < b->lo;
    return result;
}

extern "C" void func_0028EB38(List *l, Key **k) {
    It first;
    It last;
    It res;
    It pos;
    setn(first, l->head->next);
    setn(last, l->head);
    while (ne(first, last) && less(*k, first))
        inc(first);
    setn(pos, first.n);
    Node *n = (Node *)func_00326750(0xC, 4, func_005DD7F0()->name);
    Key **kp = &n->key;
    if (kp) func_0028E360(kp, k);
    n->next = pos.n;
    n->prev = pos.n->prev;
    pos.n->prev->next = n;
    pos.n->prev = n;
    setn(res, n);
}
