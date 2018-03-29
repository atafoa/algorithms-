#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n,k ;
int cnt = 0 ;
vector<int> p(100,0);

void gen(){
	if(v.size() == n){
		cnt++;
		if(cnt % k == 0){
			for(auto x : v){
				cout<<x<<" ";
			}
			cout<<endl;
		}
		
	}
	else{
		
		for(int i = 1 ; i <= n ; i++){
			
			if(v.size() and v[0] != 1 ){
				return ;
			}
			if(p[i])
				continue;
			
			
			int x = v.size();
			int parent ;
			if(x & 1){
				parent = (x-1)/2;
			}
			else
				parent = (x-2)/2;
			
			if(x==0)
				parent = 0 ;
			
			if(v.size() and v[parent] > i ){
				continue ;
			}
			
			
			p[i] = 1;
			v.push_back(i);
			gen();
			p[i] = 0;
			v.pop_back();
		}
	}
}
int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>k;
	gen();
	cout<<"TOTAL "<<cnt<<endl;
	
}
