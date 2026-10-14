struct Stats{char pad[8];int count1;char pad2[8];int sum1;char pad3[8];int count2;char pad4[8];int sum2;};
extern "C" Stats D_00863BC8;
extern "C" int func_00522220();
extern "C" int func_005221B0(int a,int b,int extra){if(a){++D_00863BC8.count1;D_00863BC8.sum1+=a+extra;}if(b){++D_00863BC8.count2;D_00863BC8.sum2+=b+extra;}return func_00522220();}
