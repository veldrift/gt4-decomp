/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result { int status, spare, offset; char padC[0xC]; int a,b; unsigned char flags; };
struct Ctx { int spare; unsigned char *data; };
struct Obj { char pad[0xB8]; int base; char padBC[8]; Ctx ctx; };
struct Out { int status, flag, b,a,spare,offset; };
extern "C" void func_004B3350(Result *, Ctx *);
extern "C" int func_004B1F90(Obj *o, Out *out) {
 Ctx *ctx = &o->ctx;
 Result r;
 func_004B3350(&r, ctx);
 if (r.status < 0) return 0;
 out->status = 0;
 out->flag = (r.flags >> 1) & 1;
 out->b = r.b;
 out->a = r.a;
 unsigned char *p = ctx->data + 0xC;
 out->offset = o->base + (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24)) + r.offset;
 return 1;
}
