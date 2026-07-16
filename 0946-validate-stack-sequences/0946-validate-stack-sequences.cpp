class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

      int i = 0,j = 0;
      int n = pushed.size();

          for(int k=0;k<n;k++)
          {
           
            pushed[i] = pushed[k];
            i++;
            while(i > 0 && pushed[i-1] == popped[j])
            {
                i-=1;
                j+=1;
            
            }

          };


          return i == 0 && j == n; 
    }
};