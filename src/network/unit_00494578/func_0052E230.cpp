struct Range { unsigned lo, hi, len, used; };
extern "C" int func_0052DE00(Range *, int) throw();
extern "C" int func_0052E158(Range *, unsigned *) throw();
extern "C" int func_0052E188(Range *, unsigned *) throw();
extern "C" int func_0052E1D8(Range *, unsigned *) throw();
extern "C" int func_0052E230(Range *r, int arg1, unsigned n) {
    unsigned total;
    unsigned tail;
    tail = 0;
    total = 0;
    int result = func_0052E158(r, &total);
    if (result) return result;
    if (total < n) return 301;
    result = func_0052E188(r, &tail);
    if (result) return result;
    if (tail >= n) goto done;
    result = func_0052E1D8(r, &total);
    if (result) return result;
    if (total - tail >= n) {
        r->hi = 0;
    } else {
        result = func_0052DE00(r, arg1);
        if (result) return result;
    }
done:
    return 0;
}
