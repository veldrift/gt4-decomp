struct N{char p[0x54];int owner;int prev,next;};struct S{char p[0xa0];int count;N*head,*tail;};
extern char D_0082AA00[];
extern "C" void func_005769F0(void*),func_00576A28(void*),func_00306130(S*,int),func_003285F8(N*);
extern "C" unsigned char*func_00305548(unsigned char*);
extern "C" void func_00206B80(S*self,N*n){if(n){func_005769F0(D_0082AA00);N*p=(N*)n->prev;N*q=(N*)n->next;if(p)p->next=(int)q;else self->head=q;if(q)q->prev=(int)p;else self->tail=p;n->prev=0;n->next=0;n->owner=0;--self->count;func_00576A28(D_0082AA00);func_00306130(self,(int)func_00305548((unsigned char*)n));func_003285F8(n);}}
