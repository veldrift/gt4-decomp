/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; void **p; };
struct Reader { char pad[0x24]; int n; char tail[8]; ~Reader(); };
extern "C" void func_002117A0(void *);
extern "C" void func_0020E348(void *,void *);
extern "C" int func_0020E538(void *,void *,int);
extern "C" int func_0024DB78(void *,void *);
extern "C" void func_002688E8(void *,void *);
extern "C" void func_00265D10(void *,int);
extern "C" void func_0020E640(void *);
extern "C" void func_0020E430(void *,int);
extern "C" void func_00211408(void *,int);
inline Reader::~Reader() { func_0020E430(this,2); }
struct Buffer { char b[0x810]; ~Buffer() { func_00211408(this,2); } };
extern "C" bool func_00269290(Obj *self,void *src) {
    Buffer buf;
    Reader r;
    Reader *pr;
    func_002117A0(&buf);
    pr = &r;
    func_0020E348(pr,buf.b+0x10);
    if (func_0020E538(pr,src,0x81)) {
        func_0024DB78(self,pr);
        func_002688E8(*self->p,src);
        func_00265D10(*self->p,r.n);
        func_0020E640(pr);
    }
    void *ret = *self->p;
    return ret != 0;
}
