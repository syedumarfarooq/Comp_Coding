https://www.geeksforgeeks.org/problems/reverse-a-stack/1
class Solution{
public:
    void insertAtBottom(stack<int>& st,int target){
        if(st.empty()){
            st.push(target);
            return;
        }
        int temp=st.top();
        st.pop();
        insertAtBottom(st,target);
        st.push(temp);
    }
    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        int target=st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st,target);
    }
};
