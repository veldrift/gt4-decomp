struct Elem{void*p;};struct Vector{int a;Elem*start,*finish,*end;};struct Obj{int a;void*table;int b;Vector*v;};extern "C" char hObject__vtable[],D_0069DE48[],D_0069DDB8[];
extern "C" void func_00309378(Elem*,int),RefCounter__structor_2(Obj*,int);extern "C" void**HObject__tf();extern "C" void func_00326798(void*,int,int,void*);
struct It{Elem*p;};static inline void destroy(It first,Elem*last){for(Elem*p=first.p;p!=last;++p)func_00309378(p,2);}
extern "C" void hObject__structor_2(Obj*p,int flags){p->table=hObject__vtable;Vector*v=p->v;if(v){It first={v->start};destroy(first,v->finish);Elem*base=v->start;int size=v->end-base;if(base)func_00326798(base,size*4,4,*HObject__tf());func_00326798(v,256,4,D_0069DE48);}RefCounter__structor_2(p,0);if(flags&1)func_00326798(p,16,4,D_0069DDB8);}
