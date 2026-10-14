/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Link { Link *next; Obj *const owner; Link(Obj *p); };
struct Obj { char pad[0xf8]; Link link; };
extern Link *D_006318BC;
extern "C" int func_004ACA40(Obj *) throw();
inline void *operator new(unsigned int, void *p) { return p; }
inline Link::Link(Obj *p) : next(D_006318BC), owner(p) { D_006318BC = this; }
int func_004ACC28(Obj *p) {
    func_004ACA40(p);
    new (&p->link) Link(p);
}
