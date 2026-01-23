

public static void main() {
   LruCache lruCache = new LruCache(4);
   lruCache.put("abc", 1);
   lruCache.put("def", 2);
   lruCache.put("ghi", 3);
   lruCache.put("jkl", 4);
   lruCache.put("mno", 5);
   lruCache.put("pqr", 6);
   lruCache.printAll();
   System.out.println(lruCache.get("abc"));
   System.out.println(lruCache.get("jkl"));
   lruCache.printAll();
}
