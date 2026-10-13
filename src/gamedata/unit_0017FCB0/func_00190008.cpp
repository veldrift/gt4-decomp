extern "C" void*func_00575E60(int,int);
extern "C" void free(void*);
struct VEntry{short delta,index;void*fn;};
struct File{VEntry*vt;};struct Owner{char pad[16];File*file;};
struct Storage{int m0;VEntry*vt;};
static inline int count(File*f){VEntry*e=(VEntry*)((char*)f->vt+0x10);return ((int(*)(void*))e->fn)((char*)f+e->delta);}
static inline void serialize(File*f,void*p){VEntry*e=(VEntry*)((char*)f->vt+0x28);((int(*)(void*,void*))e->fn)((char*)f+e->delta,p);}
static inline int write(Storage*s,int key,void*p,int n){VEntry*e=(VEntry*)((char*)s->vt+0x1C8);return ((int(*)(void*,int,void*,int))e->fn)((char*)s+e->delta,key,p,n);}
struct Buffer{void*p;int size;};
extern "C" int func_00190008(Owner*self,Storage*storage,int key){int n=(count(self->file)+63)&~63;Buffer buf;buf.p=0;buf.size=n;buf.p=func_00575E60(64,n);Buffer*pb=&buf;serialize(self->file,buf.p);int result=write(storage,key,buf.p,n);free(buf.p);return result>0;}
