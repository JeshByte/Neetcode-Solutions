class Solution {
public:
    void generate(int n1,int n2,string output,vector<string>&collect){
        if((n1+n2)==0){
            collect.push_back(output);
            return;
        }
        if(n1>=1){
            generate(n1-1,n2,output+"(",collect);
        }
        if(n2>n1){
            generate(n1,n2-1,output+")",collect);
        }
    }
    vector<string> generateParenthesis(int n) {
        string output="";
        vector<string>collect;
        generate(n,n,output,collect);
        return collect;
    }
};
