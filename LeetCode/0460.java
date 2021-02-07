class LFUCache {
    // key �� val ��ӳ�䣬���Ǻ��ĳ�Ϊ KV ��
    HashMap<Integer, Integer> keyToVal;
    // key �� freq ��ӳ�䣬���Ǻ��ĳ�Ϊ KF ��
    HashMap<Integer, Integer> keyToFreq;
    // freq �� key �б��ӳ�䣬���Ǻ��ĳ�Ϊ FK ��
    HashMap<Integer, LinkedHashSet<Integer>> freqToKeys;
    // ��¼��С��Ƶ��
    int minFreq;
    // ��¼ LFU ������������
    int cap;

    public LFUCache(int capacity) {
        keyToVal = new HashMap<>();
        keyToFreq = new HashMap<>();
        freqToKeys = new HashMap<>();
        this.cap = capacity;
        this.minFreq = 0;
    }


    public int get(int key) {
        if (!keyToVal.containsKey(key)) {
            return -1;
        }
        // ���� key ��Ӧ�� freq
        increaseFreq(key);
        return keyToVal.get(key);
    }

    public void put(int key, int val) {
        if (this.cap <= 0) return;

        /* �� key �Ѵ��ڣ��޸Ķ�Ӧ�� val ���� */
        if (keyToVal.containsKey(key)) {
            keyToVal.put(key, val);
            // key ��Ӧ�� freq ��һ
            increaseFreq(key);
            return;
        }

        /* key �����ڣ���Ҫ���� */
        /* ���������Ļ���Ҫ��̭һ�� freq ��С�� key */
        if (this.cap <= keyToVal.size()) {
            removeMinFreqKey();
        }

        /* ���� key �� val����Ӧ�� freq Ϊ 1 */
        // ���� KV ��
        keyToVal.put(key, val);
        // ���� KF ��
        keyToFreq.put(key, 1);
        // ���� FK ��
        freqToKeys.putIfAbsent(1, new LinkedHashSet<>());
        freqToKeys.get(1).add(key);
        // ������ key ����С�� freq �϶��� 1
        this.minFreq = 1;
    }

    private void removeMinFreqKey() {
        // freq ��С�� key �б�
        LinkedHashSet<Integer> keyList = freqToKeys.get(this.minFreq);
        // �������ȱ�������Ǹ� key ���Ǹñ���̭�� key
        int deletedKey = keyList.iterator().next();
        /* ���� FK �� */
        keyList.remove(deletedKey);
        if (keyList.isEmpty()) {
            freqToKeys.remove(this.minFreq);
            // ������Ҫ���� minFreq ��
        }
        /* ���� KV �� */
        keyToVal.remove(deletedKey);
        /* ���� KF �� */
        keyToFreq.remove(deletedKey);
    }

    private void increaseFreq(int key) {
        int freq = keyToFreq.get(key);
        /* ���� KF �� */
        keyToFreq.put(key, freq + 1);
        /* ���� FK �� */
        // �� key �� freq ��Ӧ���б���ɾ��
        freqToKeys.get(freq).remove(key);
        // �� key ���� freq + 1 ��Ӧ���б���
        freqToKeys.putIfAbsent(freq + 1, new LinkedHashSet<>());
        freqToKeys.get(freq + 1).add(key);
        // ��� freq ��Ӧ���б���ˣ��Ƴ���� freq
        if (freqToKeys.get(freq).isEmpty()) {
            freqToKeys.remove(freq);
            // ������ freq ǡ���� minFreq������ minFreq
            if (freq == this.minFreq) {
                this.minFreq++;
            }
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */