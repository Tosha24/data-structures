// Problem: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

import java.util.*;

public class _1203_SortItemsByGroupsRespectingDependencies {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        HashMap<Integer, List<Integer>> gGraph = new HashMap<>();
        HashMap<Integer, List<Integer>> iGraph = new HashMap<>();

        for(int i = 0; i < group.length; i++){
            if(group[i] == -1) group[i] = m++;
        }

        int[] itemInDegree = new int[n];
        int[] groupInDegree = new int[m];

        for(int to = 0; to < beforeItems.size(); to++){
            int toGroup = group[to];
            for(int from : beforeItems.get(to)){
                itemInDegree[to]++;
                if(!iGraph.containsKey(from)) iGraph.put(from, new ArrayList<Integer>());
                iGraph.get(from).add(to);
            }
        }

        for(int to = 0; to < group.length; to++){
            int toGroup = group[to];
            for(int from : beforeItems.get(to)){
                int fromGroup = group[from];
                if(!gGraph.containsKey(fromGroup)) gGraph.put(fromGroup, new ArrayList<Integer>());
                if(fromGroup != toGroup){
                    groupInDegree[toGroup]++;
                    gGraph.get(fromGroup).add(toGroup);
                }
            }
        }
        List<Integer> iList = tpSort(iGraph, itemInDegree, n);
        List<Integer> gList = tpSort(gGraph, groupInDegree, m);

        if(iList.size() == 0 || gList.size() == 0) return new int[0];

        HashMap<Integer, List<Integer>> groupedList = new HashMap<>();

        for(int item : iList){
            int grp = group[item];
            if(!groupedList.containsKey(grp)) groupedList.put(grp, new ArrayList<Integer>());
            groupedList.get(grp).add(item);
        }
        int i = 0;
        int[] ans = new int[n];

        for(int grp: gList){
            if(!groupedList.containsKey(grp)) continue;
            for(int item: groupedList.get(grp)){
                ans[i] = item;
                i++;
            }
        }
        return ans;
    }
    public List<Integer> tpSort(HashMap<Integer, List<Integer>> graph, int[] inDegree, int count){
        List<Integer> ans = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < inDegree.length; i++){
            if(inDegree[i] == 0) q.offer(i);
        }
        while(!q.isEmpty()){
            int cur = q.poll();
            ans.add(cur);
            if(!graph.containsKey(cur)) continue;
            for(int next: graph.get(cur)){
                inDegree[next]--;
                if(inDegree[next] == 0) q.offer(next);
            }
        }
        return count == ans.size() ? ans : new ArrayList<>();
    }

    public static void main(String[] args){
        int n = 8;
        int m = 2;
        int[] group = {-1,-1,1,0,0,1,0,-1};
        List<List<Integer>> beforeItems = new ArrayList<List<Integer>>(Arrays.asList(
            new ArrayList<Integer>(),
            new ArrayList<Integer>(),
            new ArrayList<Integer>(Arrays.asList(6)),
            new ArrayList<Integer>(Arrays.asList(6)),
            new ArrayList<Integer>(Arrays.asList(5)),
            new ArrayList<Integer>(Arrays.asList(6)),
            new ArrayList<Integer>(),
            new ArrayList<Integer>()
        ));

        _1203_SortItemsByGroupsRespectingDependencies s = new _1203_SortItemsByGroupsRespectingDependencies();
        int[] ans = s.sortItems(n, m, group, beforeItems);
        for(int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}