/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reports a finished network race: fetches the server's XML, follows XML/URL_List/gameFinishURL,
 * posts the result form to the Finish_Game action and checks the returned status id.
 * Real C++ objects (MHttp, MDomNode handle, MNetwork, parameter list, basic_string) so that the
 * compiler emits the destructor chain at every early return, as the original did. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long s64;

struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s) throw();

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" s32 func_005C2A50(const String *self, const String *other, u32 pos, u32 n);

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const String &str) : dat(str.rep()->grab()) {}
    String(const char *s) : dat(D_00659FA8.grab()) { assign(s); }
    ~String() { rep()->release(); }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    s32 compare(const String &str, u32 pos = 0, u32 n = (u32)-1) const { return func_005C2A50(this, &str, pos, n); }
};
inline bool operator!=(const String &a, const String &b) { return a.compare(b) != 0; }

extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

struct Node;
struct NodeImpl {
    char pad[0x30];
    String text;
    String getText() const { return text; }
    Node child(const String &name) __asm__("func_00209F20");
    Node attr(const String &name) __asm__("func_00209C30");
};
struct Node {
    NodeImpl *p;
    Node() __asm__("func_00209200");
    Node(const Node &);
    ~Node() __asm__("func_00208F18");
    Node &operator=(const Node &rhs) {
        if (this != &rhs) {
            NodeImpl *n = rhs.p;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
        return *this;
    }
    NodeImpl *operator->() const { return p; }
    bool isNull() const { return p == 0; }
};

extern "C" void free(void *) throw();
extern char D_0068D088[];
extern char D_0068D090[];
extern char D_0068D0A0[];
extern char D_0068D0B0[];
extern char D_0068D0C0[];
extern char D_0068D0C8[];
extern char D_0068D0D0[];
extern char D_0068D0E0[];
extern char D_0068D0F0[];
extern char D_0068D100[];
extern char D_0068D108[];
extern char D_0068D110[];
extern char D_0068D118[];
extern char D_0068D128[];
extern char D_0068D138[];
extern char D_0068D148[];
extern char D_0068D150[];
extern char D_0068D158[];
extern char D_0068D160[];
extern char D_0068D168[];
extern char D_0068D170[];
extern char D_0068D178[];


struct Str2 {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    Str2(const Str2 &);
    ~Str2() { Rep *r = rep(); if (--r->ref == 0) free(r); }
    u32 length() const { return rep()->len; }
    const char *c_str() const {
        if (length() == 0) return D_0068D158;
        dat[length()] = 0;
        return dat;
    }
};

struct Params {
    void *p;
    Params() __asm__("func_002EFBF0");
    Params(const Params &);
    ~Params() __asm__("func_002ED5C0");
};

struct Http {
    void setUrl(const char *url) __asm__("func_004E82C0");
    Str2 getCookie() __asm__("func_004E83B8");
};
struct HttpImpl {
    char pad[0x10];
    Http http;
    void init(char *p) __asm__("func_001D9E68");
    void finish() __asm__("func_001D9C40");
    Node get(const String &url) __asm__("func_001DA4F0");
    Node post(const String &url, const Params &params) __asm__("func_001DA628");
};
struct MHttp {
    HttpImpl *p;
    MHttp() __asm__("func_001D72E0");
    MHttp(const MHttp &);
    ~MHttp() __asm__("func_001D6E80");
    HttpImpl *operator->() const { return p; }
};
struct NetImpl {
    const char *getUrl() __asm__("func_001F15F8");
    const char *getPath() __asm__("func_001F15D0");
    void setCookie(const char *s) __asm__("func_001F15D8");
    s32 getGameId() __asm__("func_001F7450");
};
struct MNetwork {
    NetImpl *p;
    MNetwork() __asm__("func_001DC8F0");
    MNetwork(const MNetwork &);
    ~MNetwork() __asm__("func_001DC5F8");
    NetImpl *operator->() const { return p; }
};

struct Car { char pad[0x5B6]; u8 valid; char pad2[0x718 - 0x5B7]; s32 total; };
struct Entry { char pad[0x20]; s64 key; };
struct Grid { char pad[8]; Entry **entries; };
struct Race { char pad[0x70]; s32 id; };
struct Course { char pad[0x60]; Grid *grid; char pad2[0x84 - 0x64]; Race *race; };

extern "C" Car *func_0034C190(s32, s32);
extern "C" s32 func_0035E3F0(Car *);
extern "C" s64 func_004454C0(s64 *);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" void func_0010D540(Params *, Node *, const char *, const char *) throw();
extern char *D_00622F4C;

extern "C" void func_0010D8F0(Course *self, s32 index, s32 state) {
    MHttp http;
    Node root;
    MNetwork net;
    http->init(D_00622F4C + 0x3A0A8);
    http->http.setUrl(net->getUrl());
    if ((root = http->get(net->getPath())).isNull()) return;
    if ((root = root->child(D_0068D088)).isNull()) return;
    if ((root = root->child(D_0068D090)).isNull()) return;
    if ((root = root->child(D_0068D0A0)).isNull()) return;
    if ((root = http->get(root->getText())).isNull()) return;
    if ((root = root->child(D_0068D088)).isNull()) return;
    if ((root = root->child(D_0068D0B0)).isNull()) return;
    Params params;
    Node node;
    s32 total = 0x157529FF;
    Car *car = func_0034C190(self->race->id, index);
    if (car->valid) total = car->total;
    s32 fastest = func_0035E3F0(car);
    s64 key = func_004454C0(&self->grid->entries[index]->key);
    char buf[0x80];
    if ((node = root->attr(D_0068D0C0)).isNull()) return;
    String action(node->getText());
    func_0057DA20(buf, D_0068D0C8, net->getGameId());
    func_0010D540(&params, &root, D_0068D0D0, buf);
    switch (state) {
    case 0:
    case 1:
        buf[0] = '1';
        break;
    default:
        buf[0] = '3';
        break;
    }
    buf[1] = 0;
    func_0010D540(&params, &root, D_0068D0E0, buf);
    func_0010D540(&params, &root, D_0068D0F0, D_0068D100);
    func_0010D540(&params, &root, D_0068D108, D_0068D110);
    func_0057DA20(buf, D_0068D0C8, total);
    func_0010D540(&params, &root, D_0068D118, buf);
    func_0057DA20(buf, D_0068D0C8, fastest);
    func_0010D540(&params, &root, D_0068D128, buf);
    func_0010D540(&params, &root, D_0068D138, D_0068D100);
    func_0057DA20(buf, D_0068D148, key);
    func_0010D540(&params, &root, D_0068D150, buf);
    if ((root = http->post(action, params)).isNull()) return;
    http->finish();
    net->setCookie(http->http.getCookie().c_str());
    if ((root = root->child(D_0068D088)).isNull()) return;
    if ((root = root->child(D_0068D0B0)).isNull()) return;
    if ((root = root->child(D_0068D160)).isNull()) return;
    if ((node = root->child(D_0068D168)).isNull()) return;
    String id(node->getText());
    if (id != D_0068D170) {
        if ((node = root->child(D_0068D178)).isNull()) return;
    }
}
