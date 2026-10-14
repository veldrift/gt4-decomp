/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data {
    char pad[0x498];
    unsigned char count;
    char pad499[7];
    void *slots[42];
    unsigned short active;
    char pad54a[2];
    char *source;
    unsigned short length;
};
struct Context { char pad[0x2c]; int *state; Data *data; };
extern Context *D_006452D4;
extern "C" void *func_004C8C20(Context *, int, int);
extern "C" void *func_004C4070(void *, const void *, unsigned);
extern "C" int func_004BAE38(int index, int item) {
    if (index < 0) return 0x80001944;
    if (item < 0) return 0x80001D44;
    Context *ctx=D_006452D4;
    if (*ctx->state != 0x65) return 0x80000144;
    Data *data=ctx->data;
    if (index >= data->count) return 0x80001344;
    unsigned short expected=data->count-index-1;
    int selected=data->active;
    if (selected==0x7fff || (selected &= 0x7fff)!=expected) return 0x80001c44;
    if (data->length-1 < item) return 0x80001444;
    void *p=data->slots[selected];
    if (p==0) {
        p=func_004C8C20(ctx,0x1c,index);
        if (p==0) return 0x80000344;
    }
    D_006452D4->data->slots[selected]=p;
    func_004C4070(p,D_006452D4->data->source+item*0x1c,0x1c);
    return 0;
}
