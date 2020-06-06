// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-all-occurrences-of-a-most-frequent-element/0
// Smallest subarray with all occurrences of a most frequent element
#include <bits/stdc++.h>
using namespace std;
class items{
    public: 
    int start=-1;
    int end=-1;
    int freq=0;
    items(){}
    items(int start,int end,int freq){
        this->start=start;
        this->end=end;
        this->freq=freq;
    }

};
items process(vector<int> &vec){
    int n=vec.size();
    items ans(-1,-1,0);//startIndex=-1, endI=-1, frequency =0
    unordered_map<int , items> umap;
    for(int i=0;i<n;i++){
        if(umap.find(vec[i])!=umap.end()){
            items temp=umap[vec[i]];
            temp.freq=temp.freq+1;
            temp.end=i;
            umap[vec[i]]=temp;
        }
        else{
            items temp(i,i,1);
            umap[vec[i]]=temp;
        }
        // cout<<vec[i]<<endl;
        items temp1=umap[vec[i]];

        if(temp1.freq>ans.freq){
            ans.start=temp1.start;
            ans.end=temp1.end;
            ans.freq=temp1.freq;


        } else if(temp1.freq==ans.freq){
            int len1=ans.end-ans.start+1;
            int len2=temp1.end-temp1.start+1;
            if(len2<len1){
                ans.start=temp1.start;
                ans.end=temp1.end;
            }
        }
        // cout<<ans.start<<"   "<<ans.end<<"   "<<ans.freq<<endl;
        // cout<<"*****************"<<endl;

    }
    return ans;
}
int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        items it=process(vec);
        for(int i=it.start;i<=it.end;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;

    }
	return 0;   
}