typedef unsigned char u8;
typedef unsigned short u16;
struct Obj {
    unsigned handle; int kind; unsigned state;
    char pad[0x58-12]; unsigned expected, count;
    char pad60[4]; char data[0x10]; char pad74[0x84-0x74];
    int context; void (*cb)(int, int, int, u16, int);
};
struct API { char pad[0x80]; int (*copy)(void *, const void *); };
struct Hooks { char pad[0x58]; void (*set)(unsigned, unsigned); };
extern API *D_0064B4B0;
extern Hooks *D_0064B710;
extern "C" int func_0051DCF8(unsigned) throw();
extern "C" int func_00520250(int, int, int, int);
extern "C" int func_00538F98(u8 *, u16 *);
extern "C" int func_0051E798(Obj *self, int type, u8 *p, unsigned len) {
    u16 val, tag;
    int mode = 0;
    unsigned consumed = 3;
    int a = p[0], b = p[1], c = p[2];
    p += 3;
    if (len < consumed) return 0xCB20;
    if (func_00520250(self->kind, a, b, c) == 0) {
        self->state = 11;
        if (self->cb) {
            unsigned handle = self->handle;
            self->cb(self->context, 0, 0, 0, 3);
            if (func_0051DCF8(handle) == 0) return 0xCB23;
        }
        return 0;
    }
    if (type == 7) {
        if (consumed + 1 >= len) return 0xCB20;
        u8 *q = p;
        consumed = 5;
        func_00538F98(q, &val);
        p += 2;
        self->expected = val;
    } else {
        if (type != 6) return 0xCB20;
        if (consumed >= len) return 0xCB20;
        unsigned code = *p++;
        consumed = 4;
        switch (code) {
        case 0: mode = 2; break;
        case 1: mode = 4; break;
        case 2: mode = 5; break;
        case 3: mode = 6; break;
        case 4: mode = 7; break;
        case 5: mode = 8; break;
        case 6: mode = 9; break;
        default: return 0xCB20;
        }
    }
    if (consumed + 1 >= len) return 0xCB20;
    u8 *q = p;
    p += 2;
    func_00538F98(q, &tag);
    if (len < consumed + 18) return 0xCB20;
    D_0064B4B0->copy(self->data, p);
    if (type == 7) {
        self->count = tag;
        if (D_0064B710) D_0064B710->set(self->handle & 0x7FFFFFFF, self->expected);
        if (self->kind == 0) {
            self->state = type;
        } else if (self->kind == 1) {
            self->state = 5;
        } else {
            return 4;
        }
        return 0;
    }
    self->state = 11;
    if (self->cb) {
        unsigned handle = self->handle;
        self->cb(self->context, 0, 0, tag, mode);
        if (func_0051DCF8(handle) == 0) return 0xCB23;
    }
    return 0;
}
