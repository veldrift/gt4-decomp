/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Event { char pad[0xAC]; int kind; char name[0x15]; signed char flag; char tail[2]; };
struct Manager { char pad[0x5A8]; char *store; };
extern char D_00645570[];
extern char D_006C0D80[];
extern "C" int func_004F0B08(Manager *,const char *);
extern "C" int func_004F0C38(Manager *,const char *);
extern "C" void func_004F87E8(Manager *,int) throw();
extern "C" void func_004FE5F0(Event *event,Manager *manager) {
    if(manager==0) manager=(Manager *)D_00645570;
    if(func_004F0C38(manager,D_006C0D80)) { func_004F0B08(manager,event->name); return; }
    int kind=event->kind;
    int handled=0;
    if(kind<0 || kind==1) { func_004F87E8(manager,kind); handled=1; }
    if(handled) { func_004F0B08(manager,event->name); return; }
    int *count=(int *)(manager->store+0x5B30);
    int i=(*count)++;
    if(i<64) __builtin_memcpy(manager->store+0x1D8+i*200,event,200);
    if(event->flag) {
        func_004F87E8(manager,event->kind);
        if(event->flag) {
            func_004F87E8(manager,event->kind);
            __builtin_memcpy((char *)manager+0xA44,event,172);
            func_004F0B08(manager,event->name);
        }
    }
}
