#include <unordered_map>
#include <iostream>

using namespace std;

class node {
public:
    int key, val;
    node(int k, int v) :key(k), val(v) {}
};

class LRUCache {
private:
    unordered_map<int, list<node>::iterator> map;
    list<node> cache;
    int capacity;

    // ��ĳ�� key ����Ϊ���ʹ��
    void make_recent(int key) {
        auto x = map[key];
        node new_x = *x;
        // ��������ɾ��
        cache.erase(x);
        // ���²嵽��ͷ
        cache.push_front(new_x);
        map[key] = cache.begin();  // ! ����Ҫ����ӳ��
    }

    // ������ʹ�õ�Ԫ��
    void add_recent(int key, int val) {
        // ����ͷ���������ʹ�õ�Ԫ��
        cache.emplace_front(key, val);
        // �� map �����ӳ��
        map[key] = cache.begin();
    }

    // ɾ�� key
    void delete_key(int key) {
        auto x = map[key];
        cache.erase(x);
        map.erase(key);
    }

    // ɾ��������δʹ�õ�Ԫ��
    void remove_least_recently_used() {
        // ����β���ĵ�һ��Ԫ�ؾ���������δʹ�õ�
        node deleted = cache.back();
        cache.pop_back();
        // �� map ��ɾ��
        map.erase(deleted.key);
    }
public:
    LRUCache(int capacity) :capacity(capacity), map(), cache() {}

    int get(int key) {
        if (!map.count(key)) return -1;
        // ������������Ϊ���ʹ�õ�
        make_recent(key);
        return map[key]->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            // ɾ���ɵ�����
            delete_key(key);
            // �²��������Ϊ���ʹ�õ�����
            add_recent(key, value);
            return;
        }

        if (capacity == cache.size()) {
            remove_least_recently_used();
        }

        add_recent(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    auto lruc = LRUCache(2);
    lruc.put(1, 1);
    lruc.put(2, 2);
    cout << lruc.get(1) << endl;
    lruc.put(3, 3);
    cout << lruc.get(2) << endl;
    lruc.put(4, 4);
    cout << lruc.get(1) << endl;
    cout << lruc.get(3) << endl;
    cout << lruc.get(4) << endl;
}