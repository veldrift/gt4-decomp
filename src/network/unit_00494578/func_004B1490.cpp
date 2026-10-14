/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct Node { Node *next; Obj *const owner; Node(Obj *p); };
struct Obj { char pad[0xb0]; Node node; };
extern Node *D_006318BC;
extern "C" Obj *func_004B0960(Obj *) throw();
inline void *operator new(unsigned int, void *p) { return p; }
inline Node::Node(Obj *p) : next(D_006318BC), owner(p) { D_006318BC = this; }
extern "C" int func_004B1490(Obj *o) {
    func_004B0960(o);
    new (&o->node) Node(o);
}
