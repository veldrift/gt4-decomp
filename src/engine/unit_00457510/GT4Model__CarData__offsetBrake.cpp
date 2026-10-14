struct Stream {
    int f0, f4, f8, fC, f10, f14;
    char pad18[0x20];
    int f38, f3C, f40;
    char pad44[12];
};
struct Ent { const char *name; int id; };
struct Info { char pad[0x30]; unsigned short cnt; char pad32[0x32]; Ent *arr; };
struct Obj { char pad[0x18]; Info *info; };
extern char D_006AB070[], D_006AB080[], D_006AB090[], D_006AB098[];
extern "C" int func_0057F238(const char *, const char *);
extern "C" int func_004552E8(Info *, int);
extern "C" int func_00494F80(Stream *, int, int);
extern "C" int func_00494FC8(Stream *);
extern "C" float *func_00495560(Stream *);
static inline char *more(Stream *s) { return s->f40 == 0 ? &s->pad18[16] : 0; }
extern "C" void GT4Model__CarData__offsetBrake(Obj *o, float amount)
{
    if (o->info) {
        if (amount != 0.0f) {
            for (Ent *e = o->info->arr; e != o->info->arr + o->info->cnt; e++) {
                const char *name = e->name;
                int id = e->id;
                int hit = 0;
                if (func_0057F238(name, D_006AB070) == 0 || func_0057F238(name, D_006AB080) == 0 ||
                    func_0057F238(name, D_006AB090) == 0 || func_0057F238(name, D_006AB098) == 0)
                    hit = 1;
                float v = amount;
                if (!hit) v = -v;
                Stream it;
                func_00494F80(&it, func_004552E8(o->info, id), 1);
                while (more(&it)) {
                    float *p = func_00495560(&it);
                    *p += v;
                    func_00494FC8(&it);
                }
            }
        }
    }
}
