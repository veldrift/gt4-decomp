/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type, const void * = 0);
    void deallocate(T *, size_type);
    size_type max_size() const throw() { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


typedef unsigned int u32;
struct Elem { void *obj; char pad[0x10]; };
typedef vector<Elem, GameAlloc<Elem> > Vec;
struct Obj { char pad[0x10]; int mode; float target[6]; float current[8]; float alpha,targetAlpha; int pad54; float smooth,smooth2,smoothAlpha,step; char pad68[0x10]; Vec vec; void *p88; };
extern "C" void func_0021B4F8(void *,float);
extern "C" int func_0048EDD0(u32);
extern "C" void *func_0057AED8(void *,float,float);
extern "C" float *func_0057AF30(float *,float);
extern "C" void *func_0057AFF0(void *,float);
extern "C" void *func_0057B0F8(void *,float,float);
extern u32 PDISTD__LOCALE;
static inline void approach(float *cur,float target,float smooth) { *cur += (target-*cur)*smooth; }
extern "C" void func_00153BB8(Obj *self) {
    approach(&self->alpha,self->targetAlpha,self->smoothAlpha);
    self->alpha += self->step;
    if (self->alpha < 0.0f) self->alpha = 0.0f;
    else if (self->alpha > 1.0f) self->alpha = 1.0f;
    if (self->mode != 0) {
        if (self->mode == 1) {
            float *r = &self->current[4];
            func_0057AF30(r,80.0f);
            func_0057AFF0(r,4.0f);
            func_0057AED8(r,0.0f,360.0f);
        } else if (self->mode == 2) {
            func_0057B0F8(&self->current[4],self->target[4],0x1.999998p-3f);
        }
        approach(&self->current[0],self->target[0],self->smooth);
        approach(&self->current[1],self->target[1],self->smooth);
        approach(&self->current[2],self->target[2],self->smooth);
        approach(&self->current[3],self->target[3],self->smooth2);
        approach(&self->current[7],self->target[5],self->smooth2);
        float dt = 0x1.111110p-6f;
        if (func_0048EDD0(PDISTD__LOCALE)) dt = 0x1.47ae14p-6f;
        for (u32 i=0;i<self->vec.size();i++) {
            func_0021B4F8(self->vec[i].obj,dt);
        }
        if (self->p88) func_0021B4F8(self->p88,dt);
    }
}
