struct Obj { char pad[0x28]; int first,count,second; };
extern "C" void func_00498B28(void*);
inline void relocate(int&p,void*base){p+=(int)base;}
extern "C" void func_003BEB58(Obj*self){relocate(self->first,self);if(self->count)relocate(self->second,self);func_00498B28((void*)self->first);}
