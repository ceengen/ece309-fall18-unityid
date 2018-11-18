#include <IntInf.h>
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
        intNum.num, intNum.posInf, intNum.negInf);
  }
  
  //test constructor for positive infinity
  IntInf pInf(0,false,true);
  if(pInf.num == 0 && pInf.posInf == true && pInf.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, pInf should be {0, 0, 1} instead of {%d, %d, %d}", 
        pInf.num, pInf.posInf, pInf.negInf);
  }
  
  //test constructor for negatice infinity
  IntInf nInf(0,true);
  if(nInf.num == 0 && nInf.posInf == false && nInf.negInf == true)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("Constructor test fails, nInf should be {0, 1, 0} instead of {%d, %d, %d}", 
        nInf.num, nInf.posInf, nInf.negInf);
  }
  
  //test = operator with int
  IntInf e = intNum;
  if(e.num == 12 && e.posInf == false && e.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("= operator test fails, nInf should be {12, 0, 0} instead of {%d, %d, %d}", 
        e.num, e.posInf, e.negInf);
  }
  
  //test = operator with ninf
  IntInf e2 = nInf;
  if(e2.num == 0 && e2.posInf == false && e2.negInf == true)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("= operator test fails, nInf should be {0, 1, 0} instead of {%d, %d, %d}", 
        e2.num, e2.posInf, e2.negInf);
  }
  
  //test + operator with pinf
  IntInf sum = pInf + pInf;
  if(sum.num == 0 && sum.posInf == true && sum.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("+ operator test fails, pInf should be {0, 0, 1} instead of {%d, %d, %d}", 
        sum.num, sum.posInf, sum.negInf);
  }

  //test - operator with nInf and pInf
  IntInf minus = nInf - pInf;
  if(minus.num == 0 && minus.posInf == true && minus.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("- operator test fails, pInf should be {0, 0, 1} instead of {%d, %d, %d}", 
        minus.num, minus.posInf, minus.negInf);
  }
  
  //test * operator with nInf and intNum
  IntInf product = nInf * intNum;
  if(product.num == 0 && product.posInf == false && product.negInf == true)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("* operator test fails, nInf should be {0, 1, 0} instead of {%d, %d, %d}", 
        product.num, product.posInf, product.negInf);
  }
  
  //test / operator with intNum and intNum
  IntInf result = intNum/intNum;
  if(result.num == 1 && result.posInf == false && result.negInf == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("/ operator test fails, nInf should be {1, 0, 0} instead of {%d, %d, %d}", 
        result.num, result.posInf, result.negInf);
  }
  
  //test == operator with intNum and pInf
  bool areEqual = intNum == pInf;
  if(areEqual == false)
    testPassCnt++;
  else
  {
    testFailCnt++;
    printf("== operater test fails, are equal should be false");
  }
  
  printf("Tests passed: %d, tests failed: %d\n", testPassCnt, testFailCnt);
  return 0; 
}
