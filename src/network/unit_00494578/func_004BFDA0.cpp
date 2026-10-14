/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
struct Entry { int flags; u8 pad4; u8 type; char pad6[10]; u8 f10; u8 len; char rest[10]; u8 text[0x55]; u8 extra[3]; };
struct Obj { char pad[0x34]; Entry *entry; };
extern "C" int func_004BF4D0(Obj *, int, Entry *, u8 *, u8 *, int) throw();
extern "C" void *func_004C4070(void *, const void *, unsigned);
extern "C" int func_004C4DE8(u16 *);
extern "C" int func_004C8718(Obj *, u16 *, int, u16 *, Entry *);
extern "C" int func_004C8ED0(u16 *);
extern "C" void func_004C8F08(u16 *, u16 *);
extern "C" void func_004C9138(u8 *, u16 *, int);
extern "C" u8 *func_004C9198(u8 *, u8 *);
extern "C" int func_004BFDA0(Obj *o, Entry *e, u16 *input, int *state, int mode) {
    u8 text[0x60];
    u16 name[0x30];
    u8 extra[0x80];
    u16 tmp[0x40];
    int r;
    if (e->len == 0) { *state = 0; return 0; }
    if (e->flags & 0x100000) {
        int t = e->type;
        switch(t) {
        case 0: case 1: case 2: case 10: case 11: case 12: case 13: case 14: case 15: case 16: break;
        default:
            *state = 0;
            Entry *old = o->entry;
            if (old->len != 0) {
                r = func_004BF4D0(o, 0x300, old, old->text, old->extra, 3);
                if (r < 0 && (r & 0x7f00) != 0x3a00) return r;
            }
            return 0;
        }
    }
    if (input != 0) {
        int n = func_004C4DE8(input);
        if (n < 0 && n >= -(int)e->len) {
            *state = 0;
            Entry *old = o->entry;
            if (old->len != 0) {
                r = func_004BF4D0(o, 0x300, old, old->text, old->extra, 3);
                if (r < 0 && (r & 0x7f00) != 0x3a00) return r;
            }
            return 0;
        }
    }
    r = func_004C8718(o, tmp, 0x74, input, e);
    if (r < 0) {
        if ((r & 0x7f00) == 0x1e00) { *state = 0; return 0; }
        return r;
    }
    func_004C9138(extra, tmp, r);
    func_004C8F08(name, input);
    input = name + func_004C8ED0(name);
    int len = e->len;
    func_004C9138(text, input - len, len);
    if (o->entry->len != 0 && *state != 0) {
        r = func_004BF4D0(o, 0x300, e, text, extra, 2);
        if (r < 0) {
            if ((r & 0x7fff) == 0x1e6d) { *state = 0; return 0; }
            if ((r & 0x7f00) == 0x3a00) { *state = 0; return 0; }
            return r;
        }
    }
    if (*state == 0) *state = 1;
    if (mode == 1) {
        if (e->f10 != 0 || !(e->flags & 0x100000)) {
            r = func_004BF4D0(o, 0x300, e, text, extra, 3);
            if (r < 0) {
                if ((r & 0x7f00) == 0x3a00) { *state = 0; return 0; }
                return r;
            }
        }
    }
    if (e->flags & 0x100000) {
        r = func_004BF4D0(o, 0x300, e, text, extra, 1);
        if (r < 0) {
            if ((r & 0x7f00) == 0x3a00) { *state = 0; return 0; }
            return r;
        }
    }
    func_004C4070(o->entry, e, 0x1c);
    func_004C9198(o->entry->text, text);
    func_004C9198(o->entry->extra, extra);
    return 0;
}
