struct O;struct E {short adjust,pad;O *(*call)(void *,int);};struct S{E *table;char pad[0x9b8];int index;};struct Slot{char pad[0x168];O *object;char tail[0x30];inline O *get()const{return object;}};
struct Target { int unk0; char pad4[0x1e4]; float unk1E8; };
extern "C" float func_00374040(S *s){int index=s->index;Slot *slot=(Slot *)((char *)s+0x10)+index;E *e=s->table+27;O *o=e->call((char *)s+e->adjust,index);float result=0.0f;if(o && o==slot->get())result=((Target *)o)->unk1E8;return result;}
