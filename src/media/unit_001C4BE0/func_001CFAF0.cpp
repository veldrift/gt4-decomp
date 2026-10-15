/* compiler: ee-gcc2.96-stl */
#include <string.h>
void *memmove(void *, const void *, size_t) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;
typedef char u8;
extern "C" void free(void *p) throw();
extern "C" void *func_00575E60(int heap, int size);

template <class T>
class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() throw() {}
    PlainAlloc40(const PlainAlloc40 &) throw() {}
    template <class U> PlainAlloc40(const PlainAlloc40<U> &) throw() {}
    ~PlainAlloc40() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x40, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};


typedef vector<u8, PlainAlloc40<u8> > Vec;
struct VE { short delta,index; void *fn; };
struct Stream { char *vt; };
struct Obj { char pad[0x24]; char name[0x2C]; Vec pixels; short *image; };
struct Img { u8 *data; int *parsed; int compressed; };
extern char D_00694E90[];
extern "C" int func_0057DA20(char *,const char *,...);
extern "C" int *func_001D3B20(Img *);
extern "C" void func_001D3D70(Img *,short *);
extern "C" void func_001CC500(Obj *,int) throw();
static inline int getsize(Stream *s, char *name) {
    VE *e=(VE *)(s->vt+0x98);
    return ((int (*)(void *,char *))e->fn)((char *)s+e->delta,name);
}
static inline int status(Stream *s) {
    VE *e=(VE *)(s->vt+0x28);
    return ((int (*)(void *))e->fn)((char *)s+e->delta);
}
static inline int readfile(Stream *s,char *name,u8 *data,int n) {
    VE *e=(VE *)(s->vt+0x90);
    return ((int (*)(void *,char *,u8 *,int,int))e->fn)((char *)s+e->delta,name,data,n,0);
}
extern "C" int func_001CFAF0(Obj *o,Stream *s) {
    char name[0x50];
    int retry=0;
    func_0057DA20(name,D_00694E90,o->name);
    int n=0;
    while(retry <3) {
        retry++;
        n=getsize(s,name);
        if(n>=0) break;
        if(n==-2) return 0;
    }
    if(n<=0) return 0;
    n=(n+63)&-64;
    Vec data((size_t)n);
    int tries=0;
    do {
        readfile(s,name,data.begin(),data.size());
        if(status(s)==0) break;
        tries++;
    } while(tries<3);
    if(__builtin_expect(status(s),0)) return 0;
    Vec *pixels=&o->pixels;
    pixels->resize(0x2000);
    Img img;
    Img *pi=&img;
    pi->data=data.begin(); pi->parsed=0; pi->compressed=0;
    pi->parsed=func_001D3B20(pi);
    func_001D3D70(pi,(short *)pixels->begin());
    o->image=(short *)pixels->begin();
    func_001CC500(o,1);
    return 1;
}
