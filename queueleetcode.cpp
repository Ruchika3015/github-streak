class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count=0,count1=0;
        for(int n:students)
        {
            if(n==0)
            count++;
            else
            count1++;
        }
        for(int s:sandwiches)
        {
            if(s==0)
            {
                if (count==0)
                break;
                count--;
            }
            else
            {
                if (count1==0)
                break;
                count1--;
            }
        }
        return count+count1;
    }
};
