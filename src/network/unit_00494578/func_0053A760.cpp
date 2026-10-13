
int func_0053A760(signed char *arg0, unsigned int arg1)
{
  signed char *new_var;
  int var_v0;
  signed char *new_var2;
  signed char *var_v1;
  var_v1 = arg0 + 1;
  var_v0 = 0;
  new_var2 = arg0 + arg1;
  if (arg0 != 0)
  {
    signed char *end = new_var2;
    var_v1 = arg0;
    if (arg0 < end)
    {
      if ((*arg0) != 0)
      {
        new_var = end;
        while (var_v1 < new_var)
        {
          if ((*var_v1) == 0)
          {
            break;
          }
          var_v1++;
        }

      }
    }
    var_v0 = var_v1 - arg0;
  }
  return var_v0;
}
