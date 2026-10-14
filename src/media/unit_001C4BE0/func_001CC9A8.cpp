/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int size; char pad[0x48]; char *vtbl; };
struct VE3 { short delta,index; void (*fn)(void *,int *,int *,int); };
struct VE0 { short delta,index; int (*fn)(void *); };
struct VE1 { short delta,index; int (*fn)(void *,int); };
extern "C" void func_001CC098(Obj *) throw();
extern "C" void func_001CC4D8(Obj *,int) throw();
extern "C" void func_001CC500(Obj *,int) throw();
extern "C" void func_001CC9A8(Obj *self,int arg) {
 func_001CC098(self);
 int x=0,y=0;
 VE3 *e=(VE3 *)(self->vtbl+0xD8);
 e->fn((char *)self+e->delta,&x,&y,arg);
 x++; y++;
 VE0 *e0=(VE0 *)(self->vtbl+0xE0);
 x+=e0->fn((char *)self+e0->delta);
 VE1 *e1=(VE1 *)(self->vtbl+0xE8);
 y+=e1->fn((char *)self+e1->delta,arg);
 y+=(x+1)/2+1;
 self->size=y;
 func_001CC4D8(self,1);
 func_001CC500(self,1);
}
