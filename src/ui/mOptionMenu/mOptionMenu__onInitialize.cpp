/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns the dotted path of a node: its parent's path (recursively), "." and its own name,
 * or the name alone at the root. Written with gcc 2.96 bastring.h members inline: default and
 * copy constructors (Rep::grab), destructor (Rep::release), operator=(const basic_string &),
 * operator=(const char *) = assign = replace(0, npos, s, n), and
 * operator+(const basic_string &, const char *) = copy + append = replace(length(), 0, s, n).
 * strlen and hModule__getName (defined above in the unit) are declared throw(), as reorg saw them. */
typedef unsigned int u32;

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

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String() : dat(D_00659FA8.grab()) {}
    String(const char *s) : dat(D_00659FA8.grab()) { assign(s); }
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    String &operator=(const char *s) { return assign(s); }
    String &operator=(const String &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};


extern "C" int HSymID__GetID(const String *);
struct Sym { int id; Sym(const String &s) { id = HSymID__GetID(&s); } };
struct Handle { void *ptr; char pad[12]; };
extern "C" {
void func_002550B8(void *, int);
void func_00255110(void *, void *);
void mWidget__setWindowY(void *, float);
void mTextFace__virtual_67();
void func_002E6B58(void *, int);
void func_002E6BB0(void *, void *);
void func_003069F8(void *, void *, const Sym *);
void func_00309378(void *, int);
int func_0030BB18(void *);
}
struct VEntry { short delta; short pad; void (*fn)(void *,int); };
struct Obj { int x; VEntry *vt; char pad[0xb8]; void *popup,*vbox,*shadow; int open,closed,changed; };
extern char D_0069C770[],D_0069C778[],D_0069C780[],D_0069C788[],D_0069C798[],D_0069C7A8[];
inline void initSym(Handle *sym, Handle *str, const char *name) {
str->ptr=D_00659FA8.grab();
func_005C2630((String *)str,0,(u32)-1,name,func_0057F260(name));
sym->ptr=(void *)HSymID__GetID((String *)str);
}
inline void release(Handle *str) { ((Rep *)str->ptr-1)->release(); }
inline void convert(Handle *t, Handle *h, Obj *o) {
func_00255110(t,h); o->popup=t->ptr; mWidget__setWindowY(t->ptr,0.0f); func_002550B8(t,2);
}
inline void convertShadow(Handle *t, Handle *h, Obj *o) {
func_00255110(t,h); o->shadow=t->ptr; mWidget__setWindowY(t->ptr,0.0f); func_002550B8(t,2);
}
inline void convertBox(Handle *t, Handle *h, Obj *o) {
func_002E6BB0(t,h); o->vbox=t->ptr; mWidget__setWindowY(t->ptr,0.0f); func_002E6B58(t,2);
}
extern "C" void mOptionMenu__onInitialize(Obj *o, int a) {
struct Frame { Handle h,t,s,u,v,w,x,y; } f;
mTextFace__virtual_67();
if (!o->popup) {
func_0030BB18(&f.h);
initSym(&f.t,&f.s,D_0069C770);
func_003069F8(o,&f.h,(Sym *)&f.t);
release(&f.s);
if(f.h.ptr) { convert(&f.t,&f.h,o); }
func_00309378(&f.h,2);
}
if(o->popup) {
if(!o->vbox) {
func_0030BB18(&f.h);
initSym(&f.u,&f.v,D_0069C778);
func_003069F8(o->popup,&f.h,(Sym *)&f.u);
release(&f.v);
if(f.h.ptr) { convertBox(&f.u,&f.h,o); }
func_00309378(&f.h,2);
}
if(o->popup && !o->shadow) {
func_0030BB18(&f.h);
initSym(&f.w,&f.x,D_0069C780);
func_003069F8(o->popup,&f.h,(Sym *)&f.w);
release(&f.x);
if(f.h.ptr) { convertShadow(&f.w,&f.h,o); }
func_00309378(&f.h,2);
}
}
VEntry *v=o->vt+104; v->fn((char *)o+v->delta,a);
initSym(&f.h,&f.t,D_0069C788);
func_003069F8(o,&o->open,(Sym *)&f.h);
release(&f.t);
initSym(&f.h,&f.t,D_0069C798);
func_003069F8(o,&o->closed,(Sym *)&f.h);
release(&f.t);
initSym(&f.h,&f.t,D_0069C7A8);
func_003069F8(o,&o->changed,(Sym *)&f.h);
release(&f.t);
}
