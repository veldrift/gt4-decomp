/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { unsigned unused, pos, end, total; char *data; };
extern "C" int func_005385B0(S *, unsigned *);
extern "C" int func_00538418(S *, int) throw();
extern "C" int func_00538180(S *s, unsigned size) {
    unsigned avail = 0;
    int result = 2;
    if (s == 0) return result;
    if (size != 0) {
        result = func_005385B0(s, &avail);
        if (result != 0) return result;
        result = 200;
        if (avail >= size) {
            unsigned tail = s->end - s->pos;
            if (size < tail) s->pos += size;
            else s->pos = size - tail;
            s->total += size;
        } else return result;
        result = func_00538418(s, 0);
        if (result != 0) return result;
    }
    return 0;
}
