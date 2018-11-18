#include <IntArray.h>
#include <stdio.h>

int main(){
  int testPassCnt =0;
  int testFailCnt =0;
  
  //test constructor for integer
  IntInf intNum(12);
  if(intNum.num == 12 && intNum.posInf == false && intNum.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, intNum should be {12, 0, 0} instead of {%d, %d, %d}", 
        intNum.num, intNum.postInf, intNum.negInf);
  }
  
  //test constructor for positive infinity
  IntInf pInf(,true,);
  if(pInf.num == 0 && pInf.posInf == true && pInf.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, pInf should be {0, 1, 0} instead of {%d, %d, %d}", 
        pInf.num, pInf.postInf, pInf.negInf);
  }
  
  //test constructor for negatice infinity
  IntInf nInf(,,true);
  if(nInf.num == 0 && nInf.posInf == false && nInf.negInf == true)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, nInf should be {0, 0, 1} instead of {%d, %d, %d}", 
        nInf.num, nInf.postInf, nInf.negInf);
  }
  
  //test = constructor
  IntInf sum = intNum;
  if(sum.num == 12 && sum.posInf == false && sum.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, nInf should be {12, 0, 0} instead of {%d, %d, %d}", 
        sum.num, sum.postInf, sum.negInf);
  }
  
  //test

  printf("Tests passed: %d, tests failed: %d\n", testPassCnt, testFailCnt);
  return 0; 
}
