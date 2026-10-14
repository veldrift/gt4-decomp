struct Inner { char p[0x24]; float f24; };
struct Sub { char p[0xC]; int w; int h; };
struct Obj {
    Inner *in;
    char p[0x1C];
    Sub sub;
    int f34;
    int f38;
};
extern "C" void func_001C97D8(void *, void *);
extern "C" void *func_001CB340(void *, int, int);

extern "C" void func_001C9B18(Obj *o, char *dst, int y) {
    Sub *s = &o->sub;
    int h = s->h;
    int w = s->w;
    int flag = o->in->f24 < 1.0f;
    if (flag) {
        y -= o->f38;
        if (y >= 0 && y < h) {
            dst += o->f34 * 3;
            for (int i = 0; i < w; i++) {
                func_001C97D8(dst, func_001CB340(s, i, y));
                dst += 3;
            }
        }
    } else {
        y -= o->f38;
        if (y >= 0 && y < w) {
            dst += o->f34 * 3;
            for (int i = 0; i < h; i++) {
                func_001C97D8(dst, func_001CB340(s, w - y - 1, i));
                dst += 3;
            }
        }
    }
}
