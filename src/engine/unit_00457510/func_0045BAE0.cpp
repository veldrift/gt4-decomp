/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0xf8a0]; int count; };
struct Item { char pad[0x4f0]; };
struct Obj { Data *data; int count; int other; Item items[1]; };
extern "C" void func_0045C438(Item *, Item *, int);
extern "C" void func_0045BAE0(Obj *obj) {
    obj->count = obj->data->count;
    for (int i = 0; i < obj->count; i++)
        func_0045C438(&obj->items[i], obj->items, obj->count);
}
