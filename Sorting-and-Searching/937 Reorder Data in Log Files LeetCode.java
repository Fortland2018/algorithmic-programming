class Solution {

    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, new Comparator<String>() {
            @Override
            public int compare(String a, String b){
                String a_i = a.substring(0, a.indexOf(" ")).trim();
                String a_c = a.substring(a.indexOf(" "));
                String b_i = b.substring(0, b.indexOf(" ")).trim();
                String b_c = b.substring(b.indexOf(" "));

                Scanner as = new Scanner(a_c);
                Scanner bs = new Scanner(b_c);
                String pier = as.next().trim();
                String dru = bs.next().trim();


                if(!pier.matches("\\d+")
                        && !dru.matches("\\d+")){
                    int cmp = a_c.compareTo(b_c);
                    if (cmp != 0) {
                        return cmp;
                    }

                    return a_i.compareTo(b_i);
                }

                if(pier.matches("\\d+")
                        && !dru.matches("\\d+")){
                    return 1;
                }

                if(!pier.matches("\\d+")
                        && dru.matches("\\d+")){
                    return -1;
                }
                return 0;


            }
        });
        return logs;

    }
}