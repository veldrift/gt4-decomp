/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    int vt;
    char pad4[0x10];
    void *owner;
};
struct Flags {
    unsigned char n;
    char pad[3];
    float val;
};
struct Item {
    int flag;
    int x;
    int y;
    char pad[0x2C];
};
struct Self {
    char pad0[0x34];
    int f34;
    char pad38[0x44 - 0x38];
    int f44;
    char pad48[0x84 - 0x48];
    float f84;
    char pad88[0xC0 - 0x88];
    Item items[4];
};

extern char D_006AAB70[];
extern char D_006AA8A8[];
extern "C" {
Node *func_00450FE0(Self *);
int func_00451008(Self *);
Node *func_00451020(Self *);
Node *func_00451078(Self *, int);
Node *func_004510B0(Self *);
void func_00454698(int, Node *, const char *, int);
const char *func_00454A78(int, int);
Flags *func_00454B08(int, unsigned);
int func_0057F238(const char *, const char *) throw();
}

extern "C" void func_00450D88(Self *self) {
    Node *n;
    self->f34 = 0;
    self->f44 = 0;
    n = func_00450FE0(self);
    char *base4;
    if (n != 0) {
        func_00454698(n->vt, n, D_006AAB70, 0xB);
        base4 = (char *)self + 4;
        n->owner = base4;
    } else {
        base4 = (char *)self + 4;
    }
    n = func_00451020(self);
    if (n != 0) {
        func_00454698(n->vt, n, 0, 0);
        n->owner = (char *)self + 0xC;
    }
    for (int i = 0; i < 2; i++) {
        n = func_00451078(self, i == 0);
        if (n != 0) {
            func_00454698(n->vt, n, 0, 0);
        }
    }
    n = func_004510B0(self);
    if (n != 0) {
        func_00454698(n->vt, n, 0, 0);
    }
    Flags *f = func_00454B08(func_00451008(self), 0x800000);
    if (f != 0) {
        int c = f->n;
        if (c > 0) {
            self->f84 = f->val;
        }
    } else {
        self->f84 = 0;
    }
    int obj = func_00451008(self);
    if (obj != 0) {
        for (int i = 0; i < 4; i++) {
            const char *s = func_00454A78(obj, i);
            int r = 0;
            if (s != 0) {
                r = func_0057F238(s, D_006AA8A8) == 0;
            }
            self->items[i].flag = r;
        }
    }
    int *q = (int *)(base4 + 0xC4);
    for (int i = 3; i >= 0; i--) {
        q[-1] = 0;
        q[0] = 0;
        q += 14;
    }
}
