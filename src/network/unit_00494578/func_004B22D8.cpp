struct V{short delta,pad;void(*fn)(void*,int);};struct O{V*table;};struct S{O*owner;int id,value;~S() __asm__("func_004B22D8");static void operator delete(void*) __asm__("func_005C1628");};
extern "C" void func_005C1628(void*);
S::~S(){S*self=this;int id=self->id;if(id!=-1){O*p=self->owner;V*e=p->table+5;e->fn((char*)p+e->delta,id);}self->id=-1;self->value=0;}
