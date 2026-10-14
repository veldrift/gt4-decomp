struct Req { void *owner; int key; int id; int type; int user; };
struct Context { char pad[0x104]; int key; char pad108[0x60]; int (*callback)(Req *); int user; };
struct Global { char pad[0x118]; Context *current; };
struct Entry { int pad; int key; };
extern Global D_00854038;
extern "C" Entry *func_00515DD8(unsigned) throw();
extern "C" void func_00516030(int, int, unsigned) throw();
extern "C" int func_00517798(int, int, int);
extern "C" int func_00532588(Context *, int, int, int, void *);
extern "C" int func_005A48D8(void *, int, unsigned);
extern "C" int func_005172D0(int id) {
    Req req;
    short sid;
    Context *ctx = D_00854038.current;
    if (!ctx) return 8;
    Entry *e = func_00515DD8(id);
    if (!e) return 8;
    if (e->key == ctx->key) {
        e->key = -1;
        if (!ctx->callback) {
            func_00516030(-1, id, -2);
        } else {
            func_005A48D8(&req, 0, 20);
            int user = ctx->user;
            req.owner = D_00854038.current;
            req.key = e->key;
            req.type = 4;
            req.user = user;
            req.id = id;
            ctx->callback(&req);
        }
        sid = id;
        func_00517798(id, 0x50, 1);
        func_00532588(D_00854038.current, -1, 13, 2, &sid);
        return 0;
    }
    return 8;
}
