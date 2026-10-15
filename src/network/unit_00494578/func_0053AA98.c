typedef struct T { unsigned s; unsigned us; } T;
int func_0053AA98(T *a, T *b, T *out) {
    int r = 2;
    if (a != 0 && b != 0 && out != 0) {
        unsigned as = a->s;
        unsigned bs = b->s;
        if (as == bs) {
            if (a->us > b->us) goto zero;
            out->s = 0;
            out->us = b->us - a->us;
        } else if (as < bs) {
            if (b->us < a->us) {
                out->s = (bs - as) - 1;
                out->us = 1000000 - (a->us - b->us);
            } else {
                out->s = bs - as;
                out->us = b->us - a->us;
            }
        } else {
zero:
            out->s = 0;
            out->us = 0;
            return 0;
        }
        r = 0;
    }
    return r;
}
