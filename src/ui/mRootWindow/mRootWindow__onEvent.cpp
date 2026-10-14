/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_list.h>
struct Obj;
struct Entry { short delta, idx; int (*fn)(void *, int, void *, int); };
struct Obj { int word; Entry *vt; char pad[0xbc]; list<Obj *> children; };
extern "C" Obj *func_00235C00(Obj *);
extern "C" int mWidget__onEvent(Obj *, int, void *, int);
extern "C" int mEvent__propagateEvent(void *, int, Obj *);
extern "C" int mRootWindow__onEvent(Obj *self, int arg, void *ev, int direct) {
    if (!direct) {
        int handled = 0;
        if (func_00235C00(self) && func_00235C00(self) != self) {
            int result = mEvent__propagateEvent(ev, arg, func_00235C00(self));
            if (result) return result;
            handled = 1;
        }
        list<Obj *>::reverse_iterator it = self->children.rbegin();
        list<Obj *>::reverse_iterator end = self->children.rend();
        for (; it != end; it++) {
            if (*it != func_00235C00(self)) {
                Obj *o = *it;
                Entry *e = o->vt + 0x2a8/8;
                int result = e->fn((char *)o + e->delta, arg, ev, 0);
                if (result) return result;
            }
            if (*it == self) handled = 1;
        }
        if (handled) return 0;
    }
    return mWidget__onEvent(self, arg, ev, 0);
}
