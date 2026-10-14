/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int pos, tail, end, used; };
extern "C" int func_00538530(Obj *, unsigned *);
extern "C" int func_00538418(Obj *, int) throw();
extern "C" int func_005380D8(Obj *o, unsigned n) {
    unsigned avail = 0;
    int result = 2;
    if (o == 0) return result;
    if (n != 0) {
        result = func_00538530(o, &avail);
        if (result != 0) return result;
        result = 200;
        if (avail >= n) {
        unsigned remain = o->end - o->pos;
        if (n < remain) o->pos += n;
        else o->pos = n - remain;
        o->used -= n;
        } else return result;
        result = func_00538418(o, 0);
        if (result != 0) return result;
    }
    return 0;
}
