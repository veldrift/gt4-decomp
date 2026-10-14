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


struct Value {
 void *p;
 Value(const Value &);
 Value(const String &) __asm__("func_00314B20");
 ~Value() __asm__("func_00312318");
};
struct Result {
 void *p;
 Result(const Result &);
 ~Result() __asm__("func_00309378");
};
struct ParamsImpl {
 Result append(const Value &) __asm__("func_002EEEB0");
};
struct Params { ParamsImpl *p; ParamsImpl *operator->() const { return p; } };
extern char D_0068D080[];
extern "C" void func_0010D540(Params *params, Node *root, const char *name, const char *value) {
 Node n = (*root)->child(name);
 if (!n.isNull()) {
  if ((n = n->attr(D_0068D080)).isNull()) return;
  (*params)->append(n->getText());
  (*params)->append(String(value));
 }
}
