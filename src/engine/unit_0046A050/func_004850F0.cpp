/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Vec2 { float x,y; };
struct Val;
extern "C" void func_004768C0(Val *) throw();
struct Val { int type,value; Val(const Val &); ~Val() {func_004768C0(this);} };
struct Item { unsigned short flags; short index; };
struct Array {
 Item *data; int count;
 Item *begin() const {return data;}
 Item *end() const {return data+count;}
};
struct Def { char pad[10]; unsigned short flags; Array items; };
struct Entry {int a,b;};
struct Class {char pad[0xa8]; Entry *entries;};
struct Obj {
 Class *cls;
 char pad4[0x24]; float scale;
 char pad2c[0x30]; char *vtable;
 char pad60[0x20]; Obj *child;
 char pad84[0x14]; int hidden;
};
struct Event {char pad[0x40]; int state[3]; Vec2 pos;};
struct VTest {short delta,index; int (*fn)(void *,Vec2 *,float);};
struct VGet {short delta,index; void *(*fn)(void *);};
extern "C" int func_0047D968(Obj *,Event *,u32) throw();
extern "C" Def *func_00484D20(Obj *) throw();
extern "C" int func_0047D038(void *) throw();
extern "C" int func_0047D200(void *,u32) throw();
extern "C" void func_0047DC88(Obj *,Vec2 *,int) throw();
extern "C" int func_00484D48(Obj *,int,int,Event *) throw();
extern "C" Val func_004817E8(void *,Entry *,Event *) throw();
static inline void *vget(Obj *o) {
 VGet *e=(VGet *)(o->vtable+0x18);
 return e->fn((char *)o+e->delta);
}
extern "C" int func_004850F0(Obj *self, Event *event,u32 mask) {
 int r=func_0047D968(self,event,mask);
 if(r) return 1;
 if(self->hidden) return r;
 Def *def=func_00484D20(self);
 int state=func_0047D038(event->state);
 int found=0;
 int flags=0;
 if(mask&0x38) {
   Obj **slot=&self->child;
   if(*slot) {
     Vec2 pos=event->pos;
     func_0047DC88(self,&pos,0);
     Obj *child=*slot;
     VTest *e=(VTest *)(child->vtable+0x28);
     if(e->fn((char *)child+e->delta,&pos,self->scale))
       flags=func_00484D48(self,1,state,event);
     else flags=func_00484D48(self,0,state,event);
   }
 }
 if((def->flags&flags) || (mask && (def->flags&0x200))) {
   for(Item *it=def->items.begin();it!=def->items.end();++it) {
     u32 code=it->flags>>9;
     if((it->flags&flags) || (code && func_0047D200(event->state,code)))

       func_004817E8(vget(self),self->cls->entries+it->index,event);
     found=1;
   }
 }
 return found;
}
