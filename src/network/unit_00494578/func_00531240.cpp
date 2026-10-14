struct Data { unsigned values[100]; unsigned count; };
extern "C" Data *func_00535970(int);
extern "C" int func_00531240(unsigned *out,int arg) {
 unsigned values[100];
 if(!out) return 23;
 Data *data=func_00535970(arg);
 if(!data) return 22;
 int i;
 for(i=0;i<100;i++) values[i]=data->values[i];
 for(i=99;i>0;i--) {
  for(int j=0;j<i;j++) {
   if(values[j]>values[j+1]) {
    unsigned t=values[j];
    values[j]=values[j+1];
    values[j+1]=t;
   }
  }
 }
 *out=values[50];
 return 0;
}
