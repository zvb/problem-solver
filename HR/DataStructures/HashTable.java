import java.util.*;
// HashTable <String, Integer>, String - small letter latin
public class HashTable {
    private Vector<Entry> [] buckets;
    private final static int capacity = 1000;
    public HashTable() {
        buckets = Vector [capacity];
        for (int i = 0 ; i < capacity ; i ++)
            buckets[i] = new Vector<Entry>();
    }
    private static int hashCode(String s) {
        if (s == null) return 0;
        int result = 0;
        for (int i = 0 ; i < s.length() ; i ++)
            result = result * 31 + s.charAt(i) - 'a';
        return result;
    }
    public void put(String K, Integer V) {
        int hashCode = hashCode(K);
        hashCode %= capacity;
        if (hashCode < 0) hashCode += capacity;
        Vector<Entry> v = buckets[hashCode];
        for (int i = 0 ; i < v.size(); i ++) {
            if (v.get(i).key.equals(K)) {
                v.get(i).value = V;
                return;
            }
        }
        v.push_back(new Entry(K, V));
    }
    public Integer getValue(String key) {
        int hashCode = hashCode(key);
        hashCode %= capacity;
        if (hashCode < 0) hashCode += capacity;
        Vector<Entry> v = buckets[hashCode];
        for (int i = 0 ; i < v.size(); i ++) {
            if (v.get(i).key.equals(key)) {
                return v.get(i).value;
            }
        }
        return null;
    }
    public static void main(String args[]) {
        HashTable table = new HashTable();
        table.put("Nurlan", 22);
        table.put("Yessenzhar", 24);
        table.put("Nurgul", 9);
        System.out.println(table.getValue("Nurlan"));
        System.out.println(table.getValue("Nurlan"));
        System.out.println(table.getValue("Yessenzhar"));
        System.out.println(table.getValue("Yessenzharr"));
    }
    
    
    
    public static class Entry {
        public String key;
        public Integer value;
        public Entry(String key, Integer value) {
            this.key = key;
            this.value = value;
        }
    }
}