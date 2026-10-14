struct Items{int n,pad,list;};struct Parent{char pad[96];int items;};
struct S{Parent* parent;int pad,mode;short index,gap;int selected;char other[88];int state;};
extern "C" void func_3FC0D0(S*);extern "C" void func_3FC108(S*);extern "C" void func_3FBD10(S*);
inline bool less(int n,const int& limit){return n<limit;}
extern "C" void func_003FC4F0(S* self,int index){if(less(index,0))index=0;Parent* p=self->parent;int n=((Items*)p->items)->n;if(index>=n)index=n-1;func_3FC0D0(self);if(p){self->index=index;self->mode=1;self->selected=*(int*)(index*4+((Items*)p->items)->list);}else{self->index=index;self->mode=0;self->selected=0;}self->state=0;func_3FC108(self);func_3FBD10(self);}
