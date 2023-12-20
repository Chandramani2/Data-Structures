#include<bits/stdc++.h>
using namespace std;

class LRUCache{
	 list<int> dq;
	 unordered_map<int, list<int>::iterator> mp;
	 int capacity;
	public:
		LRUCache(int capacity){
			this->capacity = capacity;
		}
		void hit(int x){
			if(mp.find(x) == mp.end()){
				if(dq.size() == capacity){
					int popBack = dq.back();
					dq.pop_back();
					mp.erase(popBack);
				}
			}
			else dq.erase(mp[x]);

			dq.push_front(x);
			mp[x] = dq.begin();
		}
		void display(){
			for(auto x: dq){
				cout<<x<< " ";
			}
			cout<<endl;
		}
};

int main(){
	LRUCache cache(5);
	cache.hit(5);
	cache.hit(4);
	cache.hit(3);
	cache.hit(2);
	cache.hit(1);
	cache.display();
	cache.hit(3);
	cache.display();
	return 0;
}