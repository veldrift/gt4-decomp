/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Rep2 {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n);
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep2) + res);
    }
};

extern "C" char *strobe__toUpper(Rep2 *r);
extern "C" void free(void *p) throw();
extern Rep2 D_00659E20;

inline void Rep2::operator delete(void *p, u32 n) { free(p); }

inline char *Rep2::grab() {
    if (selfish)
        return strobe__toUpper(this);
    ++ref;
    return data();
}

extern "C" u32 func_0057F260(const char *s) throw();
extern char D_006BFF30[];
extern char D_006BFF28[];

struct String2;
extern "C" String2 *strobe__Any__setMember(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" int func_00608D98(const String2 *self, const String2 *other, u32 pos, u32 n);

struct String2 {
    char *dat;
    Rep2 *rep() const { return (Rep2 *)dat - 1; }
    String2() : dat(D_00659E20.grab()) {}
    String2(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    String2(const String2 &str) : dat(str.rep()->grab()) {}
    u32 length() const { return rep()->len; }
    char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return D_006BFF30;
        terminate();
        return data();
    }
    ~String2() { rep()->release(); }
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_0057F260(s)); }
    int compare(const String2 &str) const { return func_00608D98(this, &str, 0, (u32)-1); }
    bool operator==(const String2 &str) const { return compare(str) == 0; }
    String2 &operator=(const String2 &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

struct Url {
    int type;
    String2 user;
    String2 pass;
    String2 host;
    int port;
    String2 path;
    Url() : type(0), port(80) {}
    Url &operator=(const Url &o) {
        if (&o != this) {
            type = o.type;
            user = o.user;
            pass = o.pass;
            host = o.host;
            port = o.port;
            path = o.path;
        }
        return *this;
    }
};

struct Address {
    unsigned char bytes[8];
};

struct Http;
extern "C" String2 func_004E7460(Http *h, const String2 &host) throw();
extern "C" void func_00522408(Address *out, const char *name);
extern "C" int func_00520D88(void *out, Address addr, int port, void *input);

struct Http {
    char pad0[0x38];
    void *conn;
    char data[0xC];
    int error;
    char pad4c[0x44];
    Url direct;
    Url proxy;
    String2 address;
    String2 host;
};

extern "C" int func_004E8608(Http *self) {
    Url url;
    if (self->proxy.host == String2(D_006BFF28))
        url = self->direct;
    else
        url = self->proxy;
    if (self->conn != 0)
        return 1;
    if (self->host.compare(url.host) != 0) {
        self->host = url.host;
        self->address = func_004E7460(self, self->host);
    }
    if (self->address == String2(D_006BFF28))
        return 0;
    Address addr;
    func_00522408(&addr, self->address.c_str());
    int port = url.port;
    return (self->error = func_00520D88(&self->conn, addr, port, self->data)) == 0;
}
