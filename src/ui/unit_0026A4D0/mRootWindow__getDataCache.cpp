struct N{char pad[0x14];void*object;};
struct Iter{N*p;Iter(){}Iter(N*n):p(n){}Iter(const Iter&o):p(o.p){}};
struct Tree{int pad;N*end;};
struct Str{char*p;};
extern "C" Iter find(Tree*,Str*) __asm__("func_005DEDB0");
extern "C" char D_0069A1F8[],D_0069A208[],D_0069A210[];
extern "C" void func_005D4AD8(const char*,const char*);
extern "C" void func_003285A8(void*),func_003285F8(void*);
inline bool different(const Iter&a,const Iter&b){return a.p!=b.p;}
inline const char*text(Str*s){int n=((int*)s->p)[-4];if(!n)return D_0069A208;s->p[n]=0;return s->p;}
inline void assign(void**to,void**from){if(to!=from){void*p=*from;if(p)func_003285A8(p);if(*to)func_003285F8(*to);*to=p;}}
extern "C" int mRootWindow__getDataCache(void*self,void**out,Str*key){Tree*t=(Tree*)((char*)self+32);Iter it=find(t,key);if(different(it,Iter(t->end))){func_005D4AD8(D_0069A1F8,text(key));assign(out,&it.p->object);return 1;}func_005D4AD8(D_0069A210,text(key));return 0;}
