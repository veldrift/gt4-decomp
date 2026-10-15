/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
#include <stl_function.h>
#include <stl_tempbuf.h>
#include <stl_heap.h>
#include <stl_algo.h>
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Ref {
    void *value;
    Ref(const Ref &) __asm__("func_00309360");
    ~Ref() __asm__("func_00309378");
    Ref &operator=(const Ref &other) {
        if (this != &other) {
            void *p = other.value;
            if (p) func_003285A8(p);
            if (value) func_003285F8(value);
            value = p;
        }
        return *this;
    }
};
struct GarageRef : Ref {
    GarageRef() __asm__("func_00148030");
    GarageRef(const Ref &) __asm__("func_0013BDC0");
    GarageRef(const GarageRef &) __asm__("func_0013BD50");
    ~GarageRef() __asm__("func_0013BD68");
    operator void *() const { return value; }
    GarageRef &operator=(const GarageRef &other) { Ref::operator=(other); return *this; }
};
struct Elem;
struct Mid {
    Ref ref;
    int score;
    Mid(const Ref &object, const int &number) : ref(object), score(number) {}
    operator Elem() const;
};
struct Elem {
    GarageRef ref;
    int score;
    Elem() : ref(), score(0) {}
    Elem(const Mid &other) : ref(other.ref), score(other.score) {}
    Elem(const Elem &other) : ref(other.ref), score(other.score) {}
    Elem &operator=(const Elem &other) {
        ref = other.ref;
        score = other.score;
        return *this;
    }
};
inline Mid::operator Elem() const { return Elem(*this); }
struct ArrayRef : Ref {
    ArrayRef(const ArrayRef &) __asm__("func_002ED5A8");
    ~ArrayRef() __asm__("func_002ED5C0");
    Ref &operator[](int) __asm__("func_002EFCE0");
};
struct Heap { const char *name; };
extern "C" Heap *func_005C9BD0();
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, unsigned int, int, const char *);
extern "C" unsigned int func_002EF9B0(void *);
extern "C" int func_00145EF0(void *);
template<class T> struct Alloc {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template<class U> struct rebind { typedef Alloc<U> other; };
    Alloc() {}
    Alloc(const Alloc &) {}
    ~Alloc() {}
    template<class U> Alloc(const Alloc<U> &) {}
    T *allocate(size_type count, const void * = 0) {
        return (T *)func_00326750(count * sizeof(T), 4, func_005C9BD0()->name);
    }
    void deallocate(T *p, size_type count) {
        if (p) func_00326798(p, count * sizeof(T), 4, func_005C9BD0()->name);
    }
    size_type max_size() const { return size_type(-1) / sizeof(T); }
    void construct(T *p, const T &value) { new(p) T(value); }
    void destroy(T *p) { p->~T(); }
};
inline bool operator<(const Elem &left, const Elem &right) { return left.score < right.score; }
typedef less<Elem> Less;
template<> Elem *__uninitialized_fill_n_aux<Elem *, size_t, Elem>(Elem *, size_t, const Elem &, __false_type) __asm__("func_005C6D40");
template<> Elem *__uninitialized_copy_aux<const Elem *, Elem *>(const Elem *, const Elem *, Elem *, __false_type) __asm__("func_005C6FC8");
template<> void __introsort_loop<Elem *, Elem, ptrdiff_t, Less>(Elem *, Elem *, Elem *, ptrdiff_t, Less) __asm__("func_005C6DA8");
template<> void __final_insertion_sort<Elem *, Less>(Elem *, Elem *, Less) __asm__("func_005C6F48");
typedef vector<Elem, Alloc<Elem> > Vec;
extern "C" void func_005C6BF0(ArrayRef, Vec, int);
static inline Mid make_score(const Ref &object, const int &score) {
    return Mid(object, score);
}
extern "C" void func_001479B8(ArrayRef array, int descending) {
    Vec values(func_002EF9B0(array.value));
    for (unsigned int i = 0; i < values.size(); ++i) {
        values[i] = make_score(array[i], func_00145EF0(GarageRef(array[i])));
    }
    sort(values.begin(), values.end(), Less());
    func_005C6BF0(array, values, descending);
}
