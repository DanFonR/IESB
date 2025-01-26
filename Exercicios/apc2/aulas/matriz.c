#include <stdio.h>
int main(){
  int nums[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
  };
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      printf("nums[%d][%d]: %d\n", i, j, nums[i][j]);
  
  int *p = (int *) nums;
  for (int i = 0; i < 3 * 4; i++)
    printf("nums[%d]: %d\n", i, *(p + i));
  return 0;
}