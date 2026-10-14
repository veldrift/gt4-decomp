/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {
    long key;
    long val;
};

struct Pool {
    char pad[0x30];
    struct Entry *items;
    char pad2[4];
    int count;
};

extern "C" void func_00576788(void *p);
extern "C" int func_004859A0(void *p, long key) throw();
extern "C" void func_005767C0(void *p);
extern "C" void *func_005A47D4(void *dst, const void *src, unsigned n) throw();

extern "C" int func_004859F0(Pool *p, long a1, long a2) {
    int found = 0;
    func_00576788(p);
    int r = func_004859A0(p, a1);
    if (r < 0) {
        r = ~r;
        int count = p->count;
        struct Entry *e = &p->items[r];
        if (r != count) {
            func_005A47D4(e + 1, e, (unsigned)(count - r) * 16);
        }
        e->key = a1;
        found = 1;
        e->val = a2;
        p->count = p->count + 1;
    }
    func_005767C0(p);
    return found;
}
