struct Node{int pad;Node* next;};struct S{int a,b,active,c,enabled;Node* head;};
inline Node* next(Node* n){return n?n->next:0;}
extern "C" Node* func_0052DD98(S* self){Node* result=0;if(self && self->enabled && self->head && self->active){result=self->head;Node* p=result;do{result=p;p=next(result);}while(p);}return result;}
