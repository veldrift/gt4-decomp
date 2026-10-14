/* compiler: ee-gcc2.96-nogcse */
struct Self;
struct Conn {
    void *session; int handle; int flags;
    char pad[0x2050-12];
    int (*connect)(struct Self *, int, int);
    int (*cb2)(struct Self *, int, int);
    void (*cb3)(struct Self *, int, int);
};
struct Self { char pad[0x3C]; unsigned state; int x40; struct Conn *conn; };
struct Iface { char pad[0x18]; void (*release)(void *); };
extern struct Iface *D_0064B4B0;
extern int D_0064C114, D_0064C118, D_0064C11C, D_0064C120;
extern int D_0064C124, D_0064C128, D_0064C12C, D_0064C130;

extern "C" {
int func_0053DA30(struct Self *) throw();
int func_0053BF40(struct Self *, int *) throw();
int func_0053C590(struct Self *) throw();
int func_0053C6D0(struct Self *) throw();
int func_0053C880(struct Self *) throw();
int func_0053CBA8(struct Self *) throw();
int func_0053CE50(struct Self *) throw();
int func_0053D370(struct Self *) throw();
int func_0053D450(struct Self *) throw();
int func_0053D6F8(struct Self *) throw();
int func_0053D7F8(struct Self *) throw();
int func_0053DAC0(struct Self *) throw();
}
extern "C" int func_0053EFD0(struct Self *self) {
    int err = 0;
    if (!self) return 2;
    switch (self->state) {
    case 0: err = func_0053DA30(self); break;
    case 1:
        if (D_0064C114 == 0) {
            int status = 0;
            err = func_0053BF40(self, &status);
            if (err != 0 || status != 0) {
                D_0064C124 = err;
                D_0064C114 = 1;
                D_0064B4B0->release(self->conn->session);
                self->conn->session = 0;
                self->conn->connect(self, err, self->conn->flags);
                struct Conn *c = self->conn;
                self->state = 0;
                c->connect = 0;
            }
        } else {
            self->conn->connect(self, D_0064C124, self->conn->flags);
            struct Conn *c = self->conn;
            self->state = 0;
            c->connect = 0;
        }
        break;
    case 2:
        if (D_0064C118 == 0) err = func_0053C590(self);
        else {
            self->conn->cb2(self, D_0064C128, self->conn->flags);
            struct Conn *c = self->conn;
            self->state = 0;
            c->cb2 = 0;
        }
        break;
    case 3: {
        struct Conn *c = self->conn;
        int flags;
        if ((c->flags & 0x1000) && D_0064C11C == 0) {
            err = func_0053C6D0(self); break;
        }
        if ((c->flags & 0x800) && D_0064C120 == 0) {
            err = func_0053C6D0(self); break;
        }
        flags = c->flags;
        if (flags & 0x1000) c->cb3(self, D_0064C12C, flags);
        else c->cb3(self, D_0064C130, flags);
        self->state = 0;
        self->conn->cb3 = 0;
        break;
    }
    case 4: err = func_0053C880(self); break;
    case 5: err = func_0053CBA8(self); break;
    case 6: err = func_0053CE50(self); break;
    case 7: err = func_0053D370(self); break;
    case 8: err = func_0053D450(self); break;
    case 9: err = func_0053D6F8(self); break;
    case 10: err = func_0053D7F8(self); break;
    }
    if (err == 0 && self->conn) err = func_0053DAC0(self);
    return err;
}
