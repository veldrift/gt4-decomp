struct Node{unsigned flags;};struct Obj{char pad[104];Node* head;};
extern "C" Node* func_00454AE0(Node*) throw();
inline Node* scan(Node* p,unsigned key){while(p->flags&0xffffff00U){if((p->flags>>8)==key)return p;p=func_00454AE0(p);}return 0;}
extern "C" Node* func_00454B08(Obj* self,unsigned key){if(!self->head)return 0;return scan(self->head,key);}
