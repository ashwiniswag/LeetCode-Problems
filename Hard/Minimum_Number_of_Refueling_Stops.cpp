class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int> pq;
        
        int n = stations.size();
        int curFuel = startFuel;
        
        if(stations.size()==0){
            if(startFuel>=target){
                return 0;
            }   
            return -1;
        }
        
        if(startFuel<stations[0][0]){
            return -1;
        }
        
        
        curFuel-=stations[0][0];
        
        int count=0;
        for(int i=0; i<n; i++){
            
            int req =INT_MAX;
            
            if(i+1<n)
            req = stations[i+1][0]-stations[i][0];
            else req = target-stations[i][0];
            
            pq.push(stations[i][1]);
            while(curFuel<req){
                
                if(pq.empty()) return -1;
                count++;
                curFuel += pq.top();
                pq.pop();
            }
            
            if(i+1<n)
            curFuel -= (req);
            
            else{
                curFuel -= (req);
            }
        }
        
        if(curFuel>=0) return count;
        
        return -1;
    }
};
