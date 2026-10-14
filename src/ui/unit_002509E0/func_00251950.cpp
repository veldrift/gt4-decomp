struct Obj {char pad[0xe0];unsigned frames;};
extern "C" void func_00251950(struct Obj *p,float seconds) {p->frames=(unsigned)(seconds*60.0f);}
