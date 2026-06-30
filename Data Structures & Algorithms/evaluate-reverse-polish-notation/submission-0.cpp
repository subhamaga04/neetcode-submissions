class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        for(string ch : tokens){
            if(ch != "*" && ch != "/" && ch != "+" && ch != "-"){
                int num = stoi(ch); 
                st.push(num); 
            }else if(ch == "*"){
                int num1 = st.top(); st.pop();  
                int num2 = st.top(); st.pop(); 
                st.push(num2 * num1); 

            }else if(ch == "/"){
                int num1 = st.top(); st.pop();  
                int num2 = st.top(); st.pop(); 
                st.push(num2 / num1); 
            }else if(ch == "+"){
                int num1 = st.top(); st.pop();  
                int num2 = st.top(); st.pop(); 
                st.push(num2 + num1); 
            }else{
                int num1 = st.top(); st.pop();  
                int num2 = st.top(); st.pop(); 
                st.push(num2 - num1); 
            }  
        }
        return st.top(); 
    }
};
