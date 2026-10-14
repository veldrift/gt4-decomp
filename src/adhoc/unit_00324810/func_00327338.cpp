/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
struct TypeInfo {const char *name;};
extern "C" TypeInfo *HSymID__tf();
extern "C" void *func_00326750(unsigned,int,const char*) throw();
extern "C" void func_00326798(void*,int,int,const char*) throw();
extern "C" int HSymID__GetID(void*);
extern "C" const char *HSymID__GetName(int);
extern "C" void HOutput__printf(void*,const char*,...);
struct Sym { int id; Sym():id(0){} Sym(int x):id(x){} Sym(const Sym&x):id(x.id){} ~Sym(){} Sym&operator=(const Sym&x){if(this!=&x)id=x.id;return *this;} };
template<> Sym* __uninitialized_fill_n_aux(Sym*,unsigned,const Sym&,__false_type) __asm__("func_005EE170");

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
    T *allocate(size_type n, const void * = 0) {
        return (T*)func_00326750(n*sizeof(T),4,HSymID__tf()->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p,n*sizeof(T),4,HSymID__tf()->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<Sym,GameAlloc<Sym> > Vec;
struct Node{int color;Node *parent,*left,*right;int key,index;};
struct It {Node *node;
It(){} It(Node*n):node(n){}
int *value(){return &node->key;}
void increment(){if(node->right!=0){node=node->right;while(node->left!=0)node=node->left;}else{Node*y=node->parent;while(node==y->right){node=y;y=y->parent;}if(node->right!=y)node=y;}}
It operator++(int){It tmp=*this;increment();return tmp;}
};
static inline bool ne(const It&a,const It&b){return a.node!=b.node;}
struct Tree{int alloc;Node *header;unsigned count;};
extern "C" void func_00327338(char *self,void*out){
Tree*t=(Tree*)(self+0x30);
It i;It e;
i.node=t->header->left;e.node=t->header;
Vec v((Vec::size_type)t->count);
It *pe=&e;
for(;ne(i,*pe);i++){int *value=i.value();v[value[1]]=Sym(HSymID__GetID(value));}
int n=v.size();
for(int j=0;j<n;++j)HOutput__printf(out,"[ADHOC] %03d %s\n",j,HSymID__GetName(v[j].id));
HOutput__printf(out,"[ADHOC] Total Symbol ID: %d\n",n);
}
