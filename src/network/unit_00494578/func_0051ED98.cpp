struct Obj { unsigned handle; char pad[0x80]; int context; char gap[4]; void (*cb)(int, unsigned short, unsigned char *, unsigned); };
extern "C" int func_0051DCF8(unsigned) throw();
extern "C" int func_00538F98(unsigned char *, unsigned short *);
extern "C" int func_0051ED98(Obj *o, int type, unsigned char *data, unsigned len) {
    unsigned short decoded;
    unsigned short tag;
    unsigned consumed = 0;
    if ((unsigned)(type - 2) >= 2) {
        if (type != 10) return 2;
    }
    if (type == 10) {
        tag = 0xFFFF;
    } else {
        consumed = 1;
        if (consumed >= len) return 0xCB20;
        unsigned char *p = data;
        data += 2;
        func_00538F98(p, &decoded);
        consumed = 2;
        tag = decoded;
    }
    void (*cb)(int, unsigned short, unsigned char *, unsigned) = o->cb;
    if (cb) {
        unsigned handle = o->handle;
        cb(o->context, tag, data, len - consumed);
        if (func_0051DCF8(handle) == 0) return 0xCB23;
    }
    return 0;
}
