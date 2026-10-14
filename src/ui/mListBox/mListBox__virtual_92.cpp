extern "C" void mBox__virtual_92(char *,void *);
extern "C" int func_00265DC8(char *);
extern "C" int func_00206850(char *);
extern "C" void func_00231C10(void *);
extern "C" void func_00231C48(void *);
extern "C" void func_002B3670(char *,int,void *) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern char D_008381C8[];
extern "C" void mListBox__virtual_92(char *self,void *arg1) {
 mBox__virtual_92(self,arg1);
 if (func_00265DC8(self) && *(int *)(self+0x124)>=0) {
 if (func_00206850(self)) func_00231C10(arg1);
 func_00576788(D_008381C8);
 for (int i=*(int *)(self+0x13c); i<=*(int *)(self+0x140); i++) func_002B3670(self,i,arg1);
 func_005767C0(D_008381C8);
 if (func_00206850(self)) func_00231C48(arg1);
 }
}
