struct Self;
struct Conn {
    void *session;
    int handle;
    int user;
    char pad0c[0x1024-0xc];
    int code;
    char pad1028[0x2068-0x1028];
    void (*callback)(Self *, int, int);
};
struct Self {
    char pad0[0x3c];
    int busy;
    int success;
    Conn *conn;
};
struct Iface { char pad[0x18]; void (*release)(void *); };
extern Iface *D_0064B4B0;
extern "C" int func_0053BD78(Self *, int *) throw();
extern "C" void func_00540EB0(int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_0053D370(Self *self) {
    int status = 0;
    int err = func_0053BD78(self, &status);
    if (err != 0 || status != 0) {
        self->success = 1;
        if (self->conn->code != 200 || status == 0) {
            self->success = 0;
            err = 0xd6dc;
        }
        func_00540EB0(self->conn->handle);
        self->conn->handle = 0;
        D_0064B4B0->release(self->conn->session);
        self->conn->session = 0;
        func_005A48D8(&self->conn->code, 0, 0x100c);
        self->conn->callback(self, err, self->conn->user);
        Conn *conn = self->conn;
        self->busy = 0;
        conn->callback = 0;
    }
    return err;
}
