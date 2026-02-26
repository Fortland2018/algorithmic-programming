1class Solution {
2    public int trap(int[] height) {
3        int n = height.length;
4        if(n <= 2) return 0;
5        int[] r = new int[n];
6        int[] l = new int[n];
7        int max = 0;
8        for(int i=0; i < n; i++){
9            if(height[i] > max) max = height[i];
10            r[i] = Math.max(max, height[i]);
11        }
12        max = 0;
13        for(int i = n-1; i >=0; i--){
14            if(height[i] > max) max = height[i];
15            l[i] = Math.max(max, height[i]);
16        }
17        int sum =0;
18        for(int i=0; i < n; i++){
19            int val = Math.min(r[i], l[i]);
20            if(val > height[i]) sum += val-height[i];
21        }
22        return sum;
23    }
24}