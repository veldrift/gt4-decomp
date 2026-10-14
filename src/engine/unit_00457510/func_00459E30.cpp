/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z; };
struct Range { int a,b; };
extern char D_006AB1F0[];
extern "C" void func_0045B4D8(Range *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, int);
extern "C" void func_0045AF58(void *, int);
extern "C" void GT4Model__BinStreamWriter__writeArray(void *, const void *, int);
extern "C" void func_0045B548(Range *, void *);
struct E { short delta,index; void (*fn)(); };
struct Obj { E *vt; };
template<int slot> static inline void vector(Obj *p,Vec *v,float f) { E *e=p->vt+slot; ((void (*)(Vec *,void *,float))e->fn)(v,(char *)p+e->delta,f); }
template<int slot> static inline void vectori(Obj *p,Vec *v,int i,float f) { E *e=p->vt+slot; ((void (*)(Vec *,void *,int,float))e->fn)(v,(char *)p+e->delta,i,f); }
template<int slot> static inline float scalar(Obj *p) { E *e=p->vt+slot; return ((float (*)(void *))e->fn)((char *)p+e->delta); }
template<int slot> static inline float scalari(Obj *p,int i) { E *e=p->vt+slot; return ((float (*)(void *,int))e->fn)((char *)p+e->delta,i); }
template<int slot> static inline int integer(Obj *p) { E *e=p->vt+slot; return ((int (*)(void *))e->fn)((char *)p+e->delta); }
static inline float getx(const Vec *p) { return p->x; }
extern "C" void func_00459E30(void *w,Obj *p,float f) {
Range r;
Vec v10,v20,v30,v40,v50,v60;
float f70,f74,f78,f7c,f80,f84,f88,f8c,f90,f94,f98,f9c,fa0,fa4,fa8;
int i=0;
func_0045B4D8(&r,w,D_006AB1F0);
GT4Model__BinStreamWriter__write8u(w,0);
vector<4>(p,&v10,f); GT4Model__BinStreamWriter__writeArray(w,&v10,12);
vector<5>(p,&v20,f); GT4Model__BinStreamWriter__writeArray(w,&v20,12);
vector<6>(p,&v30,f); GT4Model__BinStreamWriter__writeArray(w,&v30,12);
vector<7>(p,&v40,f); GT4Model__BinStreamWriter__writeArray(w,&v40,12);
vector<8>(p,&v50,f); GT4Model__BinStreamWriter__writeArray(w,&v50,12);
f70=scalar<15>(p); GT4Model__BinStreamWriter__writeArray(w,&f70,4);
f74=scalar<16>(p); GT4Model__BinStreamWriter__writeArray(w,&f74,4);
func_0045AF58(w,integer<18>(p));
f78=scalar<19>(p); GT4Model__BinStreamWriter__writeArray(w,&f78,4);
f7c=scalar<20>(p); GT4Model__BinStreamWriter__writeArray(w,&f7c,4);
f80=scalar<21>(p); GT4Model__BinStreamWriter__writeArray(w,&f80,4);
f84=scalar<22>(p); GT4Model__BinStreamWriter__writeArray(w,&f84,4);
do {
vectori<9>(p,&v10,i,f); GT4Model__BinStreamWriter__writeArray(w,&v10,12);
vectori<10>(p,&v20,i,f); GT4Model__BinStreamWriter__writeArray(w,&v20,12);
f88=scalari<11>(p,i); GT4Model__BinStreamWriter__writeArray(w,&f88,4);
f8c=scalari<12>(p,i); GT4Model__BinStreamWriter__writeArray(w,&f8c,4);
f90=scalari<13>(p,i); GT4Model__BinStreamWriter__writeArray(w,&f90,4);
f94=scalari<14>(p,i); GT4Model__BinStreamWriter__writeArray(w,&f94,4);
vectori<9>(p,&v30,i,0.0f); float x=getx(&v30); vectori<9>(p,&v60,i,1.0f); f98=x-getx(&v60); GT4Model__BinStreamWriter__writeArray(w,&f98,4);
f9c=scalari<24>(p,i); GT4Model__BinStreamWriter__writeArray(w,&f9c,4);
fa0=scalari<25>(p,i); GT4Model__BinStreamWriter__writeArray(w,&fa0,4);
++i;
} while(i<4);
for(int j=0;j<4;j++) { fa4=scalari<26>(p,j); GT4Model__BinStreamWriter__writeArray(w,&fa4,4); }
fa8=scalar<23>(p); GT4Model__BinStreamWriter__writeArray(w,&fa8,4);
for(int j=0;j<4;j++) { vectori<27>(p,&v10,j,f); GT4Model__BinStreamWriter__writeArray(w,&v10,12); }
func_0045B548(&r,w);
}
