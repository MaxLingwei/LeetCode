void moveZeros(int *nums, int numsSize)
{
    int i;
    int j;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            j = i + 1;
            while(nums[j] == 0)
            {
                j++;
            }
            if (j >= numsSize)
            {
                break;
            }
            exchange(&(nums[i]), &(nums[j]));
        }
    }
}

void exchange(int *num1, int *num2)
{
    int num;
    num = *num1;
    *num1 = *num2;
    *num2 = num;
}
