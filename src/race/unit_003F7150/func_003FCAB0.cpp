typedef unsigned long long u64;
struct Rec { char pad[0x13]; unsigned char t; char pad2[0xc]; };
struct B { char pad[0x3444]; int v; };
struct L { char pad[8]; B **items; };
struct O { char pad[0x60]; L *l; char pad2[0x14]; u64 id; };
extern "C" bool func_00447F48(u64 id, Rec *out);
extern "C" int func_003FCAB0(O *o, int i)
{
    Rec r;
    func_00447F48(o->id, &r);
    if (r.t == 2 && o->l->items[i]->v != 0) return 1;
    return 0;
}
