class LRUCache {
    int cap;
    LinkedHashMap<Integer, Integer> cache = new LinkedHashMap<>();
    public LRUCache(int capacity) { 
        this.cap = capacity;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        // �� key ��Ϊ���ʹ��
        makeRecently(key);
        return cache.get(key);
    }
    
    public void put(int key, int val) {
        if (cache.containsKey(key)) {
            // �޸� key ��ֵ
            cache.put(key, val);
            // �� key ��Ϊ���ʹ��
            makeRecently(key);
            return;
        }
        
        if (cache.size() >= this.cap) {
            // ����ͷ���������δʹ�õ� key
            int oldestKey = cache.keySet().iterator().next();
            cache.remove(oldestKey);
        }
        // ���µ� key �������β��
        cache.put(key, val);
    }
    
    private void makeRecently(int key) {
        int val = cache.get(key);
        // ɾ�� key�����²��뵽��β
        cache.remove(key);
        cache.put(key, val);
    }
}