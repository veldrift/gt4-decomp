struct Node{Node*next,*prev;int value;};struct Iter{Node*p;Iter(){}Iter(Node*n){p=n;}Iter(const Iter&x){p=x.p;}};struct S{char pad[0x1c];Node*head;};
extern "C" void func_00576788(void*),func_005767C0(void*);extern "C" void**func_005EC158();extern "C" void*func_00326750(int,int,void*);
inline Iter insert(Iter pos,const int&value){Node*n=(Node*)func_00326750(12,4,*func_005EC158());int*p=&n->value;if(p)*p=value;n->next=pos.p;n->prev=pos.p->prev;pos.p->prev->next=n;pos.p->prev=n;return Iter(n);}
extern "C" void func_002EAB90(S*self,int unused,int value){int copy=value;func_00576788((char*)self+0x44);Iter result=insert(Iter(self->head),copy);func_005767C0((char*)self+0x44);}
