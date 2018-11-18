#include "IntArray.h"
#include <stdio.h>

int main(){
  int testPassCnt =0;
  int testFailCnt =0;
  
  //test constructor
  IntInf intNum(12);
  if(intNum.num == 12 && intNum.posInf == false && intNum.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, intNum should be {12, 0, 0} instead of {%d, %d, %d}", 
        intNum.num, intNum.postInf, intNum.negInf);
  }
  
  IntInf pInf(,true,);
  if(pInf.num == 0 && pInf.posInf == true && pInf.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, pInf should be {12, 0, 0} instead of {%d, %d, %d}", 
        pInf.num, pInf.postInf, pInf.negInf);
  }
  
  IntInf nInf(,,true);
  if(nInf.num == 0 && nInf.posInf == false && nInf.negInf == true)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, nInf should be {12, 0, 0} instead of {%d, %d, %d}", 
        nInf.num, nInf.postInf, nInf.negInf);
  }
  
  return 0; 
}
