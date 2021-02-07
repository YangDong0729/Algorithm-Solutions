#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class node {
public:
    int value, freq;
};

class LFUCache {
private:
    int capacity;
    int min_freq;
    // key -> value / freq �洢ʵ�ʵ�ֵ
    unordered_map<int, node> cache;
    // ��ȷ����Ƶ������ LRU
    // freq -> keys
    unordered_map<int, list<int>> freq2keys;
    // key -> �� list �е�λ��
    unordered_map<int, list<int>::iterator> key2iter;

    // �� key ��Ƶ�� + 1
    void increase_freq(int key) {
        int freq = cache[key].freq++;
        auto iter = key2iter[key];
        // ��ԭ����Ƶ����ɾ��
        freq2keys[freq].erase(iter);
        // ��ӵ��µ�Ƶ����
        freq2keys[freq + 1].push_front(key);
        key2iter[key] = freq2keys[freq + 1].begin();  // ����ӳ��
        // ���� min_freq
        if (freq2keys[freq].empty()) {
            freq2keys.erase(freq);
            if (freq == min_freq) ++min_freq;
        }
    }

    void remove_least_frequently_used() {
        int key = freq2keys[min_freq].back();
        freq2keys[min_freq].pop_back();
        key2iter.erase(key);
        cache.erase(key);
        if (freq2keys[min_freq].empty()) 
            freq2keys.erase(min_freq);  // ����� min_freq ����ȷ����û��ϵ���� add �лᱻ�� 1
    }

    void add(int key, int val) {
        cache[key] = { val, 1 };
        freq2keys[1].push_front(key);
        key2iter[key] = freq2keys[1].begin();
        min_freq = 1;
    }
    
public:
    LFUCache(int capacity):capacity(capacity), min_freq(0) {}

    int get(int key) {
        if (!cache.count(key)) return -1;
        increase_freq(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) return; // ! ע������Ϊ 0 �����
        if (!cache.count(key)) {
            if (cache.size() == capacity) {
                remove_least_frequently_used();
            }
            add(key, value);
        }
        else {
            cache[key].value = value;  // ���� value
            increase_freq(key);
        }    
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    // cnt(x) = �� x ��ʹ�ü���
    // cache=[] ����ʾ���һ��ʹ�õ�˳������ߵ�Ԫ��������ģ�
    LFUCache lFUCache(2);
    lFUCache.put(1, 1);                   // cache=[1,_], cnt(1)=1
    lFUCache.put(2, 2);                   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lFUCache.get(1) << endl;      // ���� 1
                                          // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache.put(3, 3);                   // ȥ���� 2 ����Ϊ cnt(2)=1 ��ʹ�ü�����С
                                          // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lFUCache.get(2) << endl;      // ���� -1��δ�ҵ���
    cout << lFUCache.get(3) << endl;      // ���� 3
                                          // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache.put(4, 4);                   // ȥ���� 1 ��1 �� 3 �� cnt ��ͬ���� 1 ���δʹ��
                                          // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lFUCache.get(1) << endl;      // ���� -1��δ�ҵ���
    cout << lFUCache.get(3) << endl;      // ���� 3
                                          // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lFUCache.get(4) << endl;      // ���� 4
                                          // cache=[3,4], cnt(4)=2, cnt(3)=3
}