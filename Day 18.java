// Merge Intervals

class Solution {
    public int[][] merge(int[][] intervals) {
        
        Arrays.sort(intervals, new Comparator<int[]>() { 
          @Override              
          public int compare(final int[] entry1, final int[] entry2) { 
            if (entry1[0] > entry2[0]) 
                return 1; 
            else if(entry1[0] < entry2[0])
                return -1; 
            else
                return 0;
          } 
        });
        
        ArrayList<ArrayList<Integer> > ans  = new ArrayList<ArrayList<Integer> >(); 
        int si = intervals[0][0];
        int ei = intervals[0][1];
        
        for(int i = 1; i < intervals.length; i++) {
            if(intervals[i][0] > ei) {
                ans.add(new ArrayList<Integer>(Arrays.asList(si, ei))); 
                si = intervals[i][0];
            }
            ei = Math.max(ei, intervals[i][1]);
        }
        ans.add(new ArrayList<Integer>(Arrays.asList(si, ei))); 
        int[][] arr = new int[ans.size()][];
        
		for(int i=0; i < ans.size(); i++){ 
            arr[i] = new int[]{ans.get(i).get(0), ans.get(i).get(1)};
			 
		} 
        return arr;
    }
}