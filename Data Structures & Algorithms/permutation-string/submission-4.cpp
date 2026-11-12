class Solution{
private:
	bool areEqual(vector<int>&v1,vector<int>&v2){
		for(int i=0;i<26;i++){
			if(v1[i]!=v2[i])return false;
		}
		return true;
	}
public:
	bool checkInclusion(string s1,string s2){
		vector<int> freq1(26,0),freq2(26,0);
		for(auto c:s1){
			freq1[c-'a']++;
	
		}
		int n=s2.size();
		int m=s1.size();
		if(m>n)return false;
		for(int i=0;i<m;i++){
			freq2[s2[i]-'a']++;
		}
		for(int i=m;i<n;i++){
			if(areEqual(freq1,freq2))return true;
			freq2[s2[i-m]-'a']--;
			freq2[s2[i]-'a']++;
		}
		if(areEqual(freq1,freq2))return true;
		return false;
	}

};