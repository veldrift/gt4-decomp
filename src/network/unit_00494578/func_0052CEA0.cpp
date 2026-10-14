/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct S { char pad[0x54]; int f54; int pad58; u16 f5C; u16 pad5E; unsigned f60; unsigned f64; unsigned f68; };
extern "C" void func_0053A890(void *, unsigned *);
extern "C" int func_0052CEA0(S *s, unsigned seq) {
    if (s == 0) return 2;
    u16 id = s->f5C;
    if (id != 0 && seq == id) {
        unsigned now;
        unsigned t;
        func_0053A890(&s->f54, &now);
        unsigned a2v = s->f64;
        unsigned a1v = s->f60;
        if (a2v == 0) {
            a2v = now;
            a1v = a2v >> 1;
        } else {
            unsigned sum = a2v * 7 + now;
            int d = a2v - now;
            unsigned vsum = a1v * 3;
            d = __builtin_abs(d);
            vsum += d;
            a2v = sum >> 3;
            a1v = vsum >> 2;
        }
        unsigned inc = 1;
        if (a1v != 0) inc = a1v;
        t = a2v + inc;
        s->f64 = a2v;
        s->f60 = a1v;
        s->f5C = 0;
        if (t >= 0x1F5) t = 0x1F4;
        s->f68 = t;
    }
    return 0;
}
