struct Obj;
struct Data { int handle, resource, arg; char padc[0x1018]; int code; char pad1028[0x1048]; void (*callback)(Obj *,int,int); };
struct Obj { char pad[0x3c]; int active, mode; Data *data; };
struct API { char pad[0x18]; void (*release)(int); };
extern API *D_0064B4B0;
extern "C" int func_0053BD78(void *,int *) throw();
extern "C" int func_00540EB0(int);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_0053D6F8(Obj *o) {
    int flag = 0;
    int result = 0;
    if (!o->mode) {
        o->data->callback(o,0,o->data->arg);
        Data *d = o->data;
        o->active = 0;
        d->callback = 0;
    } else {
        result = func_0053BD78(o,&flag);
        if (result || flag) {
            if (o->data->code != 200 || !flag) result = 0xd6dc;
            func_00540EB0(o->data->resource);
            o->data->resource = 0;
            D_0064B4B0->release(o->data->handle);
            o->data->handle = 0;
            func_005A48D8(&o->data->code,0,0x100c);
            o->data->callback(o,result,o->data->arg);
            Data *d = o->data;
            o->active = 0;
            d->callback = 0;
        }
    }
    return result;
}
