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
    else if (rear + 1 < numsSize && nums[front] > nums[rear] && (nums[front] + nums[rear]) <= nums[rear + 1])
    {
      nums[front] += nums[rear];
      rear++;
      ans--;
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