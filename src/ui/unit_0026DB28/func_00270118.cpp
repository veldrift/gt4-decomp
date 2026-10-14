/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Vec4 {
    f32 x,y,z,w;
    Vec4(const Vec4 &o):x(o.x),y(o.y),z(o.z),w(o.w) {}
    Vec4 &operator=(const Vec4 &o) {
        if (this != &o) { x=o.x; y=o.y; z=o.z; w=o.w; }
        return *this;
    }
};
struct Elem { s32 a,b; Vec4 p,q; s32 c; };
struct Heap { const char *name; };
extern "C" Heap *MRegion__tf() throw();
extern "C" void *func_00326750(unsigned int,int,const char *);
extern "C" void func_00326798(void *,s32,s32,const char *);
extern "C" Vec4 *func_005E0D50(Vec4 *,Vec4 *,Vec4 *,int);
template<class I> inline Vec4 *value_type(const I &) { return 0; }
static inline void destroy_aux(Vec4 *first,Vec4 *last,Vec4 *) {
    for (;first!=last;++first) {}
}
static inline void destroy_range(Vec4 *first,Vec4 *last) {
    destroy_aux(first,last,value_type(first));
}
static inline Vec4 *copy_range(Vec4 *first,Vec4 *last,Vec4 *result) {
    return func_005E0D50(first,last,result,(int)value_type(result));
}
static inline void dealloc(Vec4 *p,s32 n) {
    if(p) func_00326798(p,n*16,4,MRegion__tf()->name);
}
struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};
struct VectorBase {
    Alloc alloc; Vec4 *begin,*end,*cap;
    VectorBase(s32 n,const Alloc &a):alloc(a),begin(0),end(0),cap(0) {
        begin=(Vec4 *)func_00326750(n*16,4,MRegion__tf()->name);
        end=begin;cap=begin+n;
    }
    ~VectorBase() {
        dealloc(begin,cap-begin);
    }
};
struct Vector:VectorBase {
    Alloc get_allocator() const { return alloc; }
    Vector(const Vector &o):VectorBase(o.end-o.begin,o.get_allocator()) {
        end=copy_range(o.begin,o.end,begin);
    }
    ~Vector() { destroy_range(begin,end); }
};
struct Cmp { s32 a; f32 b,c,d; s32 e,f; Vec4 p,q; s32 g,h; Vector v; s32 i; };

struct Reverse {
 Elem *current;
 Reverse() {}
 Reverse(Elem *p):current(p) {}
 Reverse(const Reverse &r):current(r.current) {}
 Elem *base() const {return current;}
 Elem &operator*() const {Elem *p=current;return *--p;}
 Reverse &operator++() {--current;return *this;}
 Reverse operator++(int) {Reverse t=*this;--current;return t;}
};
inline bool operator==(const Reverse &a,const Reverse &b) {return a.base()==b.base();}
inline bool operator!=(const Reverse &a,const Reverse &b) {return !(a==b);}
struct Elements {int alloc; Elem *first,*last,*cap;
 Elem *begin() {return first;} Elem *end() {return last;}
 Reverse rbegin() {return Reverse(last);} Reverse rend() {return Reverse(first);}
};
extern "C" float func_00233D98(void *);
extern "C" int func_00233DA8(void *);
extern "C" int func_00233DD8(void *);
extern "C" int func_00235E70(void *);
extern "C" void *func_00235C00(void *);
extern "C" void func_00235C80(void *,int);
extern "C" void *func_0025C2A0(void *);
extern "C" unsigned long func_00266428(void *);
extern "C" void func_0025BA38(void *,float *,float *);
extern "C" int func_0026F9E0(Cmp *,Elements *,void *,float,float,int) throw();
extern "C" void func_005DFF68(Elem *,Elem *,Elem *,int,Cmp);
extern "C" void func_005E07F0(Elem *,Elem *,Cmp);
static inline Elem *elem_type(Elem *const &) {return 0;}
static inline void destroy_elems(Elem *first,Elem *last,Elem *) {for(;first!=last;++first) {}}
static inline void destroy_elements(Elem *first,Elem *last) {destroy_elems(first,last,elem_type(first));}
static inline Elem *copy_elems(Elem *first,Elem *last,Elem *result) {
 for(int n=last-first;n>0;--n,++first,++result) *result=*first;
 return result;
}
static inline Elem *erase(Elements *v,Elem *first,Elem *last) {
 Elem *i=copy_elems(last,v->last,first);
 destroy_elements(i,v->last);
 v->last=v->last-(last-first);
 return first;
}
static inline void clear(Elements *v) {erase(v,v->begin(),v->end());}
static inline int lg(int n) {int k;for(k=0;n!=1;n>>=1) ++k;return k;}
static inline void sort(Elem *first,Elem *last,Cmp cmp) {if(first!=last) {func_005DFF68(first,last,elem_type(first),lg(last-first)*2,cmp);func_005E07F0(first,last,cmp);}}
extern "C" int func_00270118(Cmp *o,Elements *v,void *w) {
 o->d=func_00233D98(w);o->e=func_00233DA8(w);o->f=func_00233DD8(w);o->g=func_00235E70(w);
 for(void *p=func_00235C00(w);p;p=func_0025C2A0(p)) {if(func_00266428(p)) {o->h=(int)p;break;}}
 clear(v);
 float x,y;func_0025BA38(w,&x,&y);
 func_0026F9E0(o,v,w,x,y,0);
 if(v->begin()==v->end()) return 0;
 sort(v->begin(),v->end(),*o);
 int selected=0;
 if(o->a!=0) {
 if(o->a==1) {
 Elem *it=v->begin();
 for(;it!=v->end();it++) {if(it->a==o->g) {++it;if(it==v->end()) it=v->begin();break;}}
 if(it!=v->end()) selected=it->a;else selected=v->begin()->a;
 } else if(o->a==2) {
 Reverse it;it=v->rbegin();
 for(;it!=v->rend();it++) {if((*it).a==o->g) {++it;if(it==v->rend()) it=v->rbegin();break;}}
 if(it!=v->rend()) selected=(*it).a;else selected=v->end()[-1].a;
 }
 } else selected=v->begin()->a;
 if(o->g!=selected) {func_00235C80(w,selected);return 1;}
 return 0;
}
