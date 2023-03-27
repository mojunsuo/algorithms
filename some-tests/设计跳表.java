class Skiplist {
    private static final int MAX_LEVEL = 32;
    private static final double SKIPLIST_P = 0.25;
    private Node head;
    private int curLevel;

    public Skiplist() {
        this.head = new Node(-1, MAX_LEVEL);
        this.curLevel = 0;
    }

    public boolean search(int target) {
        Node cur = this.head;
        for (int i = curLevel - 1; i >= 0; i--) {
            //�ҵ���i������С��target��Ԫ��
            while (cur.next[i] != null && cur.next[i].val < target) {
                cur = cur.next[i];
            }
        }
        //�Ѿ��ڵ�һ��
        cur = cur.next[0];
        //��ǰԪ�ص�ֵ�Ƿ���� target
        return cur != null && cur.val == target;
    }

    public void add(int num) {
        //��Ÿ��µ�λ��
        Node[] update = new Node[MAX_LEVEL];
        Arrays.fill(update, head);
        Node cur = this.head;
        for (int i = curLevel - 1; i >= 0; i--) {
            //�ҵ����в��ǰ�����
            while (cur.next[i] != null && cur.next[i].val < num) {
                cur = cur.next[i];
            }
            update[i] = cur;
        }
        int randomLevel = randomLevel();
        //������ߵĲ���
        this.curLevel = Math.max(this.curLevel, randomLevel);
        Node newNode = new Node(num, randomLevel);
        //�����������������level
        for (int i = 0; i < randomLevel; i++) {
            newNode.next[i] = update[i].next[i];
            update[i].next[i] = newNode;
        }
    }

    public boolean erase(int num) {
        Node[] update = new Node[MAX_LEVEL];
        Node cur = this.head;
        for (int i = curLevel - 1; i >= 0; i--) {
            //�ҵ���i������С��target��Ԫ��
            while (cur.next[i] != null && cur.next[i].val < num) {
                cur = cur.next[i];
            }
            update[i] = cur;
        }
        cur = cur.next[0];
        //�ж�num�Ƿ����
        if (cur == null || cur.val != num) {
            return false;
        }
        for (int i = 0; i < curLevel; i++) {
            if (update[i].next[i] != cur) {
                break;
            }
            //ɾ����i���ֵ��num��ȵ�Ԫ��
            update[i].next[i] = cur.next[i];
        }
        //�п������ϲ�ֻ��һ��Ԫ�أ����̲���
        while (curLevel > 1 && head.next[curLevel - 1] == null) {
            curLevel--;
        }
        return true;
    }

    /**
     * �� randomLevel ������������� 1~MAX_LEVEL ֮���������
     * 1/2 �ĸ��ʷ��� 2
     * 1/4 �ĸ��ʷ��� 3
     * 1/8 �ĸ��ʷ��� 4 �Դ�����
     */
    private int randomLevel() {
        int level = 1;
        // �� level < MAX_LEVEL���������С���趨�Ľ�������ʱ��level + 1
        while (Math.random() < SKIPLIST_P && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }
}

class Node {
    int val;
    Node[] next;

    public Node(int val, int maxLevel) {
        this.val = val;
        this.next = new Node[maxLevel];
    }
}


/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */