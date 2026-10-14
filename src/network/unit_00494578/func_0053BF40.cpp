struct Conn {
    void *session;
    char pad4[0x4];
    unsigned int type;
    char pad0C[0x18 - 0xC];
    char hdr[0xA24 - 0x18];
    char name[0x207C - 0xA24];
    char body[1];
};
struct Self { char pad0[0x44]; Conn *conn; };
struct Iface {
    char pad0[0x34];
    int (*f34)(void *, void *, int *, char *, int, int *);
    char pad38[0x6C - 0x38];
    void (*f6C)(void *);
};
extern char D_006C3C60[], D_006C3C90[], D_006C3CC8[], D_006C3CF8[];
extern Iface *D_0064B4B0;
extern "C" int func_0053A890(void *, unsigned int *);
extern "C" int func_0053B858(char *, void *);
extern "C" int func_00594470(const char *, const char *, unsigned int);

extern "C" int func_0053BF40(Self *self, int *out) {
    int sp0[4];
    int sp10 = 0;
    int sp14 = 0;
    D_0064B4B0->f6C(sp0);
    int r = D_0064B4B0->f34(self->conn->session, sp0, &sp10, self->conn->body, 0x800, &sp14);
    if (r != 0) {
        *out = 1;
        return r;
    }
    if (sp14 != 0) {
        *out = 1;
        self->conn->body[sp14] = 0;
        sp14 = func_0053B858(self->conn->body, self->conn->hdr);
        if (sp14 == 200) {
            Conn *c = self->conn;
            switch (c->type) {
            case 0x20:
                if (func_00594470(D_006C3C60, c->name, 0x200) != 0) return 0xD6DB;
                break;
            case 0x40:
                if (func_00594470(D_006C3C90, c->name, 0x200) != 0) return 0xD6DB;
                break;
            case 0x1000:
                if (func_00594470(D_006C3CC8, c->name, 0x200) != 0) return 0xD6DB;
                break;
            case 0x800:
                if (func_00594470(D_006C3CF8, c->name, 0x200) != 0) return 0xD6DB;
                break;
            default: return 6;
            }
        } else {
            return 0xD6DC;
        }
    } else {
    unsigned int v;
    func_0053A890(self->conn->hdr - 8, &v);
    if (v >= 0x1389) {
        *out = 1;
        return 0xD6D9;
    }
    }
    return 0;
}
