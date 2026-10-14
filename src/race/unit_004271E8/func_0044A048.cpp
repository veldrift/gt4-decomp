struct Obj;
extern "C" long long func_00449F58(Obj *);
extern "C" long long func_00449F68(Obj *, int) throw();
extern "C" int func_00449F80(Obj *, int);

extern "C" long long func_0044A048(Obj *o, long long key, int arg2) {
    long long r;
    if (key == 0x1F) return 0xF800LL << 21;
    int n = (int)func_00449F58(o);
    r = -1;
    int i;
    for (i = 0; i < n; i++) {
        r = func_00449F68(o, i);
        long long h = (r & (-1LL << 32)) >> 32;
        int e = func_00449F80(o, i);
        if (key == h && arg2 == e) break;
        r = -1;
        if ((unsigned long long)key < (unsigned long long)h) break;
    }
    return r;
}
