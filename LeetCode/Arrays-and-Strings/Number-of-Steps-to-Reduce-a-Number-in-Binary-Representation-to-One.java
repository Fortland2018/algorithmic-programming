1class Solution {
2    public int numSteps(String s) {
3        int score = 0;
4        StringBuilder sb = new StringBuilder(s);
5        while(!sb.toString().equals("1")){
6            score++;
7            if(sb.charAt(sb.length()-1) == '0'){
8                sb.replace(sb.length()-1, sb.length(), "" );
9            } else {
10                int k = sb.length()-2;
11                boolean stop = false;
12                sb.replace(sb.length()-1, sb.length(), "0");
13                while(!stop && k >=0){
14                    if(sb.charAt(k) == '1'){
15                        sb.replace(k,k+1, "0");
16                        k--;
17                    } else {
18                        sb.replace(k, k+1, "1");
19                        stop = true;}
20                }
21                if(stop == false) {
22                    stop = true;
23                    sb.insert(0, "1");}
24            }
25        }
26        return score;
27    }
28}