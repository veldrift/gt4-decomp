/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b; unsigned char *data; };
struct Entry { short delta, index; int (*fn)(void *, unsigned, unsigned); };
struct Obj { int f0; void *dev; char pad8[0x48]; unsigned size,start; int f58; unsigned sectors; int f60,count; char pad68[12]; unsigned free; Entry *vt; };
extern "C" Buf *func_004CA820(void *, unsigned) throw();
extern "C" void func_004CA938(void *, Buf *) throw();
static inline unsigned decode(unsigned v, int n) {
    if (n & 1) return (v >> 4) & 0xffff;
    return v & 0xfff;
}
extern "C" int func_004CDAA0(Obj *o, unsigned prev, unsigned remain) {
    unsigned first = 0;
    unsigned value;
    int n = prev + 1;
    int pass = 1;
    if (o->free < remain) return -28;
    do {
        unsigned pos = n + n / 2;
        unsigned sec = pos / o->size;
        unsigned off = pos % o->size;
        while (remain && sec < o->sectors) {
            Buf *buf = func_004CA820(o->dev, o->start + sec);
            if (!buf) return -5;
            while (n < o->count && off < o->size) {
                if (off == o->size - 1) {
                    Buf *next = func_004CA820(o->dev, o->start + sec + 1);
                    if (!next) break;
                    value = (next->data[0] << 8) | buf->data[off];
                    func_004CA938(o->dev, next);
                } else {
                    unsigned char *p = buf->data + off;
                    value = (p[1] << 8) | p[0];
                }
                if (n & 1) value = (value >> 4) & 0xffff;
                else value &= 0xfff;
                if (!value) {
                    if (prev) {
                        Entry *e = o->vt + 4;
                        if (e->fn((char *)o + e->delta, prev, n) < 0) continue;
                    }
                    prev = n;
                    --remain;
                    if (!first) first = prev;
                    --o->free;
                    if (!remain) break;
                }
                ++n;
                off = n + n / 2;
            }
            func_004CA938(o->dev, buf);
            ++sec;
            off %= o->size;
        }
        n = 2;
        if (!remain) break;
    } while (--pass != -1);
    if (!first) return -28;
    {
        Entry *e = o->vt + 2;
        value = ((int (*)(void *))e->fn)((char *)o + e->delta);
        {
            Entry *e = o->vt + 4;
            e->fn((char *)o + e->delta, prev, value);
        }
    }
    return first;
}
