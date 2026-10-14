/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx { char p0[0x38]; char *a38; char p1[4]; char *a40; char p2[0x74]; char *aB8; };
struct Node { short type,p2,p4,idx; };
struct Obj { Ctx *ctx; Node *node; };
extern "C" int func_0047EA80(char *, int);
extern "C" int func_0047F2E0(char *, int);
extern "C" int func_0047FA60(char *, int);
extern "C" int func_0047D870(Obj *o, int x) {
 switch(o->node->type) {
 case 0: return func_0047EA80(o->ctx->a38+o->node->idx*24,x);
 case 1: return func_0047F2E0(o->ctx->a40+o->node->idx*40,x);
 case 7: return func_0047FA60(o->ctx->aB8+o->node->idx*24,x);
 default: return 0;
 }
}
