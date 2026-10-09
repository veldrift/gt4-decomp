struct Obj { char pad[0x166C]; int active; };
struct Resource { char data[0x100]; Obj *owner; };
struct Callback { void (*fn)(); Resource *self; };
extern "C" void func_0038FFC8(Obj *,int);
extern "C" Resource *func_005C1498(int);
extern "C" int func_005A609C(Resource *,void *);
extern "C" void func_0038FEF0();
extern "C" void func_0044CBE8(Resource *,Callback *);
extern "C" void func_0038FF38(Obj *self,void *data,int mode) {
    if(self->active) return;
    if(mode==2) {func_0038FFC8(self,0);return;}
    Resource *resource=func_005C1498(0x104);
    resource->owner=self;
    func_005A609C(resource,data);
    Callback callback;callback.fn=func_0038FEF0;callback.self=resource;
    func_0044CBE8(resource,&callback);
}
