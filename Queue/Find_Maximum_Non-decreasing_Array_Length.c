int findMaximumLength(int *nums, int numsSize)
{
  int ans = 1;
  int front = 0;
  int rear = 1;
  while (rear < numsSize)
  {
    if (nums[front] <= nums[rear])
    {
      front = rear;
      rear++;
    }
    else
    {
      int cmp = rear++;
      while (rear < numsSize && nums[front] > nums[cmp])
      {
        nums[cmp] += nums[rear++];
      }
      if (nums[front] > nums[cmp])
      {
        return ans;
      }
      else
      {
        front = cmp;
      }
    }
    ans++;
  }
  return ans;
}
