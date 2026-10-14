struct V{short adjust,pad;float(*fn)(void*,int);};struct O{V*table;};
extern "C" void func_00450D88(void*);
extern "C" void func_00450F50(void*,int,float,float,float);
static inline V& entry(O*p,int i){return p->table[i];}
static inline float query(O*p,int slot,int i){V&e=entry(p,slot);return e.fn((char*)p+e.adjust,i);}
extern "C" void func_00450CB8(void*p,O*o){int i=0;func_00450D88(p);do{float x=query(o,11,i),y=query(o,12,i),z=query(o,13,i);func_00450F50(p,i,x,y,z);++i;}while(i<4);}
