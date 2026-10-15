/* compiler: ee-gcc2.96-stl */
/* list<LinkedPtr>::erase(iterator) inlined into a filter loop (SGI STL include/stl/stl_list.h) */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_list.h>

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *p) throw();

template <class T>
class PlainAlloc10 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef PlainAlloc10<U> other; };
    PlainAlloc10() throw() {}
    PlainAlloc10(const PlainAlloc10 &) throw() {}
    template <class U> PlainAlloc10(const PlainAlloc10<U> &) throw() {}
    ~PlainAlloc10() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) {
        free(p);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

struct Range {
    char pad[2];
    short lo;
    short hi;
    bool contains(int t) const { return t >= lo && t < hi; }
};

/* a polymorphic game object: the vtable pointer after 0x5C bytes of fields, the destructor first */
struct Obj {
    int f0;
    Range *range;
    char pad[0x5C - 8];
    virtual ~Obj();
};

/* a shared pointer whose owners form a ring: the last owner deletes the object */
struct LinkedPtr {
    Obj *p;
    LinkedPtr *prev;
    LinkedPtr *next;
    ~LinkedPtr() {
        if (prev == next) {
            if (p) delete p;
        } else {
            next->prev = prev;
            prev->next = next;
        }
    }
};

typedef list<LinkedPtr, PlainAlloc10<LinkedPtr> > List;

struct Self {
    char pad[0x64];
    int frame;
    char pad68[0xA4 - 0x68];
    List items;
};

extern "C" void func_004803B8(Self *self) {
    List::iterator it = self->items.begin();
    while (it != self->items.end()) {
        if (!(*it).p->range->contains(self->frame))
            it = self->items.erase(it);
        else
            ++it;
    }
}
