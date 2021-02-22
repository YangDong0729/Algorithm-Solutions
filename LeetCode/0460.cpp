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
    // key -> value / freq 存储实际的值
    unordered_map<int, node> cache;
    // 在确定的频次下是 LRU
    // freq -> keys
    unordered_map<int, list<int>> freq2keys;
    // key -> 在 list 中的位置
    unordered_map<int, list<int>::iterator> key2iter;

    // 给 key 的频次 + 1
    void increase_freq(int key) {
        int freq = cache[key].freq++;
        auto iter = key2iter[key];
        // 从原来的频次中删掉
        freq2keys[freq].erase(iter);
        // 添加到新的频次中
        freq2keys[freq + 1].push_front(key);
        key2iter[key] = freq2keys[freq + 1].begin();  // 重新映射
        // 更新 min_freq
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
            freq2keys.erase(min_freq);  // 这里的 min_freq 不正确，但没关系，在 add 中会被置 1
    }

    void add(int key, int val) {
        cache[key] = { val, 1 };
        freq2keys[1].push_front(key);
        key2iter[key] = freq2keys[1].begin();
        min_freq = 1;
    }

public:
    LFUCache(int capacity) :capacity(capacity), min_freq(0) {}

    int get(int key) {
        if (!cache.count(key)) return -1;
        increase_freq(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (capacity == 0) return; // ! 注意容量为 0 的情况
        if (!cache.count(key)) {
            if (cache.size() == capacity) {
                remove_least_frequently_used();
            }
            add(key, value);
        }
        else {
            cache[key].value = value;  // 更新 value
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
    // cnt(x) = 键 x 的使用计数
    // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
    LFUCache lFUCache(2);
    lFUCache.put(1, 1);                   // cache=[1,_], cnt(1)=1
    lFUCache.put(2, 2);                   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lFUCache.get(1) << endl;      // 返回 1
                                          // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache.put(3, 3);                   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                                          // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lFUCache.get(2) << endl;      // 返回 -1（未找到）
    cout << lFUCache.get(3) << endl;      // 返回 3
                                          // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache.put(4, 4);                   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                                          // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lFUCache.get(1) << endl;      // 返回 -1（未找到）
    cout << lFUCache.get(3) << endl;      // 返回 3
                                          // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lFUCache.get(4) << endl;      // 返回 4
                                          // cache=[3,4], cnt(4)=2, cnt(3)=3
}