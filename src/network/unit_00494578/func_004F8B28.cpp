/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { s32 u0, id, tag, u0C; };
struct Tab {
    Ent e[0x20];
    s32 count;
    s32 key;
};
extern "C" s32 func_004F8B28(Tab *t, s32 *out) {
    s32 key = t->key;
    s32 n = 0;
    if (key != -1) {
        Ent *p = t->e;
        Ent *end = p + t->count;
        if (p != end) {
            s32 none = -1;
            s32 *dst = out;
            do {
                s32 id = p->id;
                if (id != none && p->tag == key) {
                    s32 v = id;
                    if (n > 0) {
                        s32 *q = out;
                        s32 k = n;
                        do {
                            s32 cur = *q;
                            k -= 1;
                            if (v < cur) {
                                *q = v;
                                v = cur;
                            }
                            q += 1;
                        } while (k != 0);
                    }
                    *dst = v;
                    dst += 1;
                    n += 1;
                }
                p += 1;
            } while (p != end);
        }
    }
    return n;
}
