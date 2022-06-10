
#include<bits/stdc++.h>
#include<map>
#include<queue>
class LRUCache
{
    map<int, pair<list<int> :: iterator, int> > m;
    int size;
    list<int> lru;
public:
    
    
    LRUCache(int capacity)
    {
        size = capacity;
    }
    
    void bringFront(int key) {
        lru.erase(m[key].first);
        lru.push_front(key);
        m[key].first = lru.begin();
    }

    int get(int key)
    {
        if(m.count(key) > 0) {
            bringFront(key);
            return m[key].second;
        }   
        return -1;
    }

    void put(int key, int value)
    {
        if(m.count(key)) {
           m[key].second = value;
            bringFront(key);
        }
        else {
            if(m.size() == size) {
                m.erase(lru.back());
                lru.pop_back();
            }
            lru.push_front(key);
            m[key] = {lru.begin(), value};
            
        }
     
    }
};
