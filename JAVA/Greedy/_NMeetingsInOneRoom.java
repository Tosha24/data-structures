package JAVA.Greedy;
import java.util.*;

class meeting{
    int start;
    int end;
    int pos;
    meeting(int start, int end, int pos){
        this.start = start;
        this.end = end;
        this.pos = pos;
    }
}

class meetingComparator implements Comparator<meeting>{
    @Override
    public int compare(meeting m1, meeting m2){
        if(m1.end < m2.end) return -1;
        else if(m1.end > m2.end) return 1;
        else if(m1.pos < m2.pos) return -1;
        return 1;
    }
}

public class _NMeetingsInOneRoom {
    private static int maxMeetings(int[] start, int[] end, int N){
        ArrayList<meeting> meet = new ArrayList<>();

        for(int i = 0; i < start.length; i++)
            meet.add(new meeting(start[i], end[i], i+1));
        
        meetingComparator mc = new meetingComparator(); 
        Collections.sort(meet, mc); 
        int max_meetings = 1;
        int limit = meet.get(0).end; 
        
        for(int i = 1;i<start.length;i++) {
            if(meet.get(i).start > limit) {
                limit = meet.get(i).end; 
                max_meetings = max_meetings + 1;
            }
        }
        return max_meetings;
    }
    public static void main(String[] args) {
        int[] start = {1, 3, 0, 5, 8, 5};
        int[] end = {2, 4, 6, 7, 9, 9};
        int N = 6;
        System.out.println(maxMeetings(start, end, N));
    }
}
