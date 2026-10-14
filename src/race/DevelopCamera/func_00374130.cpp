struct O;struct E {short adjust,pad;O *(*call)(void *,int);};struct S{E *table;char pad[0x9b8];int index;};struct Slot{char pad[0x168];O *object;char tail[0x30];inline O *get()const{return object;}};
extern "C" int func_00380D78(O *);
extern "C" int func_00374130(S *s){int index=s->index;Slot *slot=(Slot *)((char *)s+0x10)+index;E *e=s->table+27;O *o=e->call((char *)s+e->adjust,index);if(!o)return 0;O *target=slot->get();if(o!=target)return 0;return func_00380D78(o);}
