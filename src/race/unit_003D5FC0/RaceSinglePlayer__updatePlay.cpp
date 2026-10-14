/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct VEntry { short delta, index; void *fn; };
typedef char *(*GetFn)(char *,int);
typedef int (*Getter)(char *);
typedef void (*Setter)(char *,int);
typedef void (*Updater)(char *,float);
extern "C" void RaceBasic__updatePlay(char *,float);
extern "C" void RaceDisplay__commonPreUpdate(char *);
extern "C" void func_0039DA80(char *);
extern "C" int func_00373DA0(char *,int);
extern "C" void func_003B76F0(char *,int,int,int);
extern "C" void RaceSinglePlayer__updatePlay(char *self,float dt) {
    RaceBasic__updatePlay(self,dt);
    RaceDisplay__commonPreUpdate(*(char **)(self+0x6c));
    if(*(char **)(self+0xe420)) {
        VEntry *e=(VEntry *)(*(char **)(self+0x64)+0xd0);
        char *car=((GetFn)e->fn)(self+e->delta,0);
        {
            int stride=0x19c;
            char *panel=*(char **)(self+0xe420);
            VEntry *s=(VEntry *)(*(char **)panel+0x58);
            ((Setter)s->fn)(panel+s->delta,*(short *)(car+*(int *)(car+0x9bc)*stride+0x1c));
        }
        {
            VEntry *g=(VEntry *)(*(char **)car+0x120);
            int value=((Getter)g->fn)(car+g->delta);
            char *panel=*(char **)(self+0xe420);
            VEntry *s=(VEntry *)(*(char **)panel+0x60);
            ((Setter)s->fn)(panel+s->delta,value);
        }
        {
            int value=func_00373DA0(car,0);
            char *panel=*(char **)(self+0xe420);
            VEntry *s=(VEntry *)(*(char **)panel+0x70);
            ((Setter)s->fn)(panel+s->delta,value);
        }
        {
            VEntry *g=(VEntry *)(*(char **)car+0x1b0);
            int value=((Getter)g->fn)(car+g->delta);
            char *panel=*(char **)(self+0xe420);
            VEntry *s=(VEntry *)(*(char **)panel+0x78);
            ((Setter)s->fn)(panel+s->delta,value);
        }
        {
            char *panel=*(char **)(self+0xe420);
            VEntry *s=(VEntry *)(*(char **)panel+0x10);
            ((Updater)s->fn)(panel+s->delta,dt);
        }
    }
    func_0039DA80(*(char **)(self+0x6c));
    u32 mode=*(u32 *)(self+0xcc8);
    if(mode<2) {
        if(*(int *)(self+0x124e0)) return func_003B76F0(*(char **)(self+0x6c)+0xf4,0x1a,0,2);
    } else if(mode-2<2 && *(int *)(self+0x124e0)) {
        func_003B76F0(*(char **)(self+0x6c)+0xf4,1,0,0);
    }
}
