/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; unsigned short a; char pad6[2]; unsigned short b; char padA[6]; char data[1]; };
struct Entry { void *data; unsigned short a,b; };
struct Out { int z,pad; unsigned char a,b; unsigned short n,x,y; Entry entries[1]; };
struct Obj { Node *head; Out *out; int n; char padC[0x970]; int x,y; };
extern "C" void func_00494A28(Obj *) throw();
extern "C" void func_00494578(Obj *, int) throw();
extern "C" Out *func_00494E50(Obj *p, int a, int b) {
 func_00494A28(p);
 Out *o=p->out;
 int i=0;
 o->a=a; o->b=b; o->z=0;
 o->n=(unsigned short)p->n; o->x=(unsigned short)p->x; o->y=(unsigned short)p->y;
 Node *q=p->head;
 if (i<p->n) {
 Entry *e=o->entries;
 do { e->data=q->data; e->a=q->a; e->b=q->b; e++; q=q->next; i++; } while (i<p->n);
 }
 func_00494578(p,((int)o+p->n*8+0x1f)&~15);
 return o;
}
