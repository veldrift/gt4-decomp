/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { unsigned long long key; char rest[0x230]; };
struct Tab { int pad; Row *rows; int count; };
extern "C" unsigned long long func_00447C78(int);
extern "C" void func_00432EB8(Row *) throw();
extern "C" Row *func_00433AA0(Tab *t, int a) {
    unsigned long long k = func_00447C78(a);
    int n = t->count;
    for (int i = 0; i < n; ++i) {
        Row *r = t->rows + i;
        if (r->key == k) return r;
        if (r->key == (unsigned long long)-1 || k < r->key) {
            if (r->key != (unsigned long long)-1) {
                for (int j = n - 1; i < j; --j) {
                    Row *d = t->rows + j;
                    Row *s = d - 1;
                    if (s->key != (unsigned long long)-1) *d = *s;
                }
            }
            func_00432EB8(r);
            r->key = k;
            return r;
        }
    }
    return 0;
}
