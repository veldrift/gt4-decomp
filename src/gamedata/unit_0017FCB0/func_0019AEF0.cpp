/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

template<class T> class PlainAlloc40 {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;
    template<class U> struct rebind { typedef PlainAlloc40<U> other; };
    PlainAlloc40() {}
    PlainAlloc40(const PlainAlloc40&) {}
    template<class U> PlainAlloc40(const PlainAlloc40<U>&) {}
    ~PlainAlloc40() {}
    T* allocate(size_type, const void* = 0);
    void deallocate(T*, size_type);
    size_type max_size() const { return size_type(-1) / sizeof(T); }
    void construct(T* p, const T& value) { new(p) T(value); }
    void destroy(T* p) { p->~T(); }
};

typedef vector<signed char, PlainAlloc40<signed char> > Buffer_005CD9E8;
struct Image_0019AEF0 {
    Buffer_005CD9E8 field_00;
    unsigned int field_10, field_14, field_18, field_1c, field_20;
    float field_24;
    unsigned int size() const {
        unsigned int height = field_14;
        unsigned int row = field_10 * field_20;
        unsigned int layers = field_18 * field_1c;
        return row * height * layers;
    }
    void setSize(unsigned int format, unsigned int width, unsigned int height, unsigned int layers, unsigned int depth) {
        field_20 = format;
        field_10 = width;
        field_14 = height;
        field_1c = layers;
        field_18 = depth;
    }
};
struct Owner_0019AEF0 { char unknown_00[0xc4]; Image_0019AEF0 field_c4; };
extern "C" unsigned int func_00575D00();
extern "C" void func_005CD968(Buffer_005CD9E8*);

extern "C" void func_0019AEF0(Owner_0019AEF0* self) {
    Image_0019AEF0* image = &self->field_c4;
    image->field_24 = 1.3333332538604736328125f;
    unsigned int size = image->size();
    image->field_10 = 1280;
    image->field_14 = 960;
    image->field_1c = image->field_18 = 1;
    image->field_20 = 3;
    unsigned int required = image->size();
    unsigned int available = func_00575D00();
    if (size != required) {
        func_005CD968(&image->field_00);
        if (available < required) return;
        image->field_00.resize(required);
    }
}
