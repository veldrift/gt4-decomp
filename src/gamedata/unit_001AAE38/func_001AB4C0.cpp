/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_00622F4C;
extern "C" void func_001AB438(void *, void *) throw();
extern "C" int func_001C6160(void *, void *, void *);
extern "C" void *func_001C71B8(char *);
extern "C" void *func_001C71E0(char *);
extern "C" void *func_001C7468(char *);
extern "C" void *func_001C7490(char *);
extern "C" void func_004A1638(int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A4550(int,int);
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A5A90(float,float,float,float,float,float);
extern "C" void func_004A7454();
extern "C" void func_004A7890(float,float,float);
extern "C" void func_004AB040(int);
extern "C" void func_001AB4C0(char *self) {
 float rect[4]; char buf[32];
 char *p3=self+0x1e9c;
 char *p2=self+0xbc;
 int wide=*(int *)(D_00622F4C+0x38cc4);
 rect[0]=0; rect[1]=0; rect[2]=640; rect[3]=480;
 RaceEntryCar__update(1);func_004A53F8();func_004A7454();
 func_004A5A90(0,640,480,0,-1,1);
 if(wide) {func_004A7890(1,0x1.55554ep+0f,1);rect[3]*=0.75f;}
 RaceEntryCar__update(0);func_004A53F8();func_004A7454();
 func_004A1638(6);func_004AB040(4);func_004AB040(5);func_004A29A8(0);
 func_004A4550(2,1);func_004A4550(3,1);
 void *o=func_001C71E0(p2);
 if(o && func_001C6160(func_001C7490(p3),buf,rect))func_001AB438(o,buf);
 o=func_001C71B8(p2);
 if(o && func_001C6160(func_001C7468(p3),buf,rect))func_001AB438(o,buf);
 func_004A5400();RaceEntryCar__update(1);func_004A5400();RaceEntryCar__update(0);
}
